#include "JsonParser.hpp"
#include <QFile>
#include <QJsonDocument>
#include <QTextStream>
#include "Question/OneChoiceQuestion.hpp"
#include "Question/MultiChoiceQuestion.hpp"

using std::unique_ptr;

enum class MultiChoice {
	non,
	one,
	multi
};

bool JsonParser::getString(const QJsonObject::const_iterator objectIterator,
                           StringUniquePointer * const string) {
		
	const QJsonValue value = objectIterator.value();
	
	if(!value.isString())
		return false;
	
	string->reset(new QString(value.toString()));
	
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
		if(correctAnswer <= 0)
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

QJsonDocument * JsonParser::readDocument(const QString & filename) {
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QString s;

    QTextStream stream(&file);
    s.append(stream.readAll());

    QByteArray jsonData = s.toUtf8();
    return new QJsonDocument(QJsonDocument::fromJson(jsonData));
}

bool JsonParser::getQuestion(QuestionUniquePointer * const question, const QJsonObject * const object) {
    QJsonObject::const_iterator objectIterator = object->constBegin();

    const QJsonObject::const_iterator objectEnd = object->constEnd();

    StringUniquePointer header;
    StringUniquePointer category;
    StringListUniquePointer possibleAnswers;
    SetOfIntsUniquePointer correctAnswers;
    int correctAnswer = 0;
    MultiChoice multiChoice = MultiChoice::non;
    while(objectIterator != objectEnd) {
        if(objectIterator.key() == QString("question")) {
            if(!getString(objectIterator, &header))
                return false;
        }
        else if(objectIterator.key() == QString("category")) {
            if(!getString(objectIterator, &category))
                return false;
        }
        else if(objectIterator.key() == QString("possibleAnswers")) {
            if(!getPossibleAnswers(objectIterator, &possibleAnswers))
                return false;
        }
        else if(objectIterator.key() == QString("correctAnswers")) {
            if(multiChoice == MultiChoice::one)
                return false;
            if(!getCorrectAnswers(objectIterator, &correctAnswers))
                return false;
            else
                multiChoice = MultiChoice::multi;
        }
        else if(objectIterator.key() == QString("correctAnswer")) {
            if(multiChoice == MultiChoice::multi)
                return false;
            if(!getCorrectAnswer(objectIterator, &correctAnswer))
                return false;
            else
                multiChoice = MultiChoice::one;
        }
        else
            return false;
        ++objectIterator;
    }

    if(!(bool(header) && bool(possibleAnswers)))
        return false;

    if(multiChoice == MultiChoice::multi) {

        QSet<int>::const_iterator setIterator = correctAnswers->constBegin();
        const QSet<int>::const_iterator setEnd = correctAnswers->constEnd();
        while(setIterator != setEnd) {
            if(*setIterator > possibleAnswers->size())
                return false;
            ++setIterator;
        }
        question->reset(new MultiChoiceQuestion(header.release(), category.release(),
                                                possibleAnswers.release(),
                                                correctAnswers.release()));
        return true;

    }

    if(multiChoice == MultiChoice::one) {

        if(possibleAnswers->size() == 1)
            return false;

        if(correctAnswer > possibleAnswers->size())
            return false;

        question->reset(new OneChoiceQuestion(header.release(), category.release(),
                                              possibleAnswers.release(), correctAnswer));
        return true;
    }

    return false;

}

bool JsonParser::parseTest(const QString & filename, TestUniquePointer * const test) {
    unique_ptr<QJsonDocument> document(readDocument(filename));
    if(!document->isArray())
        return false;
    const QJsonArray array(document->array());
    QJsonArray::const_iterator it = array.constBegin();
    const QJsonArray::const_iterator end = array.constEnd();
    QuestionListUniquePointer questionList(new QuestionList);
    while(it != end) {
        if(!it->isObject())
            return false;
        const QJsonObject object = it->toObject();
        QuestionUniquePointer question;
        if(!getQuestion(&question, &object))
            return false;
        questionList->append(question.release());
        ++it;
    }
    test->reset(new Test(questionList.release()));
    return true;
}

bool JsonParser::parseQuestion(const QString & filename, QuestionUniquePointer * const question) {
    unique_ptr<QJsonDocument> document(readDocument(filename));
    if(!document->isObject())
        return false;
    QJsonObject object = document->object();
    return getQuestion(question, &object);
}

JsonParser::~JsonParser() {
}
