#include "JsonParser.hpp"
#include <QFile>
#include <QJsonDocument>
#include <QTextStream>
#include "Token/EndToken.hpp"
#include "Token/FailToken.hpp"
#include "Token/QuestionToken.hpp"
#include "Question/OneChoiceQuestion.hpp"
#include "Question/MultiChoiceQuestion.hpp"

enum class MultiChoice {
	non,
	one,
	multi
};

void JsonParser::setSource(const QString & filename) {
	QFile file(filename);
	file.open(QIODevice::ReadOnly);
	QString s;

    QTextStream stream(&file);
    s.append(stream.readAll());
    
    QByteArray jsonData = s.toUtf8();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData);
    
    if(!jsonDocument.isArray()) {
		fail = true;
		return;
	}
	
	array.reset(new QJsonArray(jsonDocument.array()));
	
	iterator = array->constBegin();
	
	end = array->constEnd();

}

TokenPointer JsonParser::nextToken() {
	
	if(fail)
		return new FailToken;
		
	if(iterator == end)
		return new EndToken;
		
	if(!iterator->isObject())
		return new FailToken;
		
	const QJsonObject object = iterator->toObject();
		
	QJsonObject::const_iterator objectIterator = object.constBegin();
	
	const QJsonObject::const_iterator objectEnd = object.constEnd();
	
	StringUniquePointer header;
	StringListUniquePointer possibleAnswers;
	SetOfIntsUniquePointer correctAnswers;
	int correctAnswer = 0;
	MultiChoice multiChoice = MultiChoice::non;
	while(objectIterator != objectEnd) {
		if(objectIterator.key() == QString("question")) {
			if(!getHeader(objectIterator, &header))
				return new FailToken;
		}
		else if(objectIterator.key() == QString("possibleAnswers")) {
			if(!getPossibleAnswers(objectIterator, &possibleAnswers))
				return new FailToken;
		}
		else if(objectIterator.key() == QString("correctAnswers")) {
			if(multiChoice == MultiChoice::one)
				return new FailToken;
			if(!getCorrectAnswers(objectIterator, &correctAnswers))
				return new FailToken;
			else
				multiChoice = MultiChoice::multi;
		}
		else if(objectIterator.key() == QString("correctAnswer")) {
			if(multiChoice == MultiChoice::multi)
				return new FailToken;
			if(!getCorrectAnswer(objectIterator, &correctAnswer))
				return new FailToken;
			else
				multiChoice = MultiChoice::one;
		}
		else
			return new FailToken;
		++objectIterator;
	}
	
	if(!(bool(header) && bool(possibleAnswers)))
		return new FailToken;
			
	if(multiChoice == MultiChoice::multi) {
		
		QSet<int>::const_iterator setIterator = correctAnswers->constBegin();
		const QSet<int>::const_iterator setEnd = correctAnswers->constEnd();
		while(setIterator != setEnd) {
			if(*setIterator > possibleAnswers->size())
				return new FailToken;
			++setIterator;
		}
		++iterator;
		return new QuestionToken(new MultiChoiceQuestion(header.release(), possibleAnswers.release(), correctAnswers.release()));
	
	}
	
	if(multiChoice == MultiChoice::one) {
		
		if(correctAnswer > possibleAnswers->size())
			return new FailToken;
		
		++iterator;
		return new QuestionToken(new OneChoiceQuestion(header.release(), possibleAnswers.release(), correctAnswer));
	}
		
	return new FailToken;
}

bool JsonParser::getHeader(const QJsonObject::const_iterator objectIterator, StringUniquePointer * const header) {
		
	const QJsonValue value = objectIterator.value();
	
	if(!value.isString())
		return false;
	
	header->reset(new QString(value.toString()));
	
	return true;
	
}

bool JsonParser::getPossibleAnswers(const QJsonObject::const_iterator objectIterator,
	StringListUniquePointer * const possibleAnswers) {
		
	const QJsonValue value = objectIterator.value();
	
	if(!value.isArray())
		return false;
		
	const QJsonArray array = value.toArray();
	
	QJsonArray::const_iterator arrayIterator = array.constBegin();
	const QJsonArray::const_iterator arrayEnd = array.constEnd();
	
	if(arrayIterator == arrayEnd)
		return false;
	
	possibleAnswers->reset(new StringList);
	
	do {
		if(!arrayIterator->isString())
			return false;
		
		(*possibleAnswers)->append(new QString(arrayIterator->toString()));
		
		++arrayIterator;
	} while(arrayIterator != arrayEnd);
		
	return true;

}

bool JsonParser::getCorrectAnswers(const QJsonObject::const_iterator objectIterator,
	SetOfIntsUniquePointer * const correctAnswers) {
		
	const QJsonValue value = objectIterator.value();
	
	if(!value.isArray())
		return false;
		
	const QJsonArray array = value.toArray();
	
	QJsonArray::const_iterator arrayIterator = array.constBegin();
	const QJsonArray::const_iterator arrayEnd = array.constEnd();
	
	correctAnswers->reset(new SetOfInts);
	
	while(arrayIterator != arrayEnd) {
		const int correctAnswer = arrayIterator->toInt();
		if(correctAnswer == 0)
			return false;
			
		(**correctAnswers) += correctAnswer;
		
		++arrayIterator;
		
	}
	
	return true;
	
}

bool JsonParser::getCorrectAnswer(const QJsonObject::const_iterator objectIterator,
	int * const correctAnswer) {
		
	const QJsonValue value = objectIterator.value();
		
	*correctAnswer = value.toInt();
	if(*correctAnswer <= 0)
		return false;
		
	return true;
	
}

JsonParser::~JsonParser() {
}
