#pragma once

#include "Parser.hpp"
#include <memory>
#include <QJsonArray>
#include "Defines/StringListPointer.hpp"
#include "Defines/SetOfInts.hpp"
#include <QJsonObject>

class JsonParser : public Parser {

    private:
    QJsonDocument * readDocument(const QString & filename);
    bool getQuestion(QuestionUniquePointer * question, const QJsonObject * object);

	public:

    bool parseTest(const QString & filename, TestUniquePointer * test) override;
    bool parseQuestion(const QString & filename, QuestionUniquePointer * question) override;
	
	~JsonParser() override;
	
	private:
		
	static bool getString(QJsonObject::const_iterator objectIterator, StringUniquePointer * string);

	static bool getPossibleAnswers(QJsonObject::const_iterator objectIterator,
		StringListUniquePointer * possibleAnswers);
		
	static bool getCorrectAnswers(QJsonObject::const_iterator objectIterator,
		SetOfIntsUniquePointer * correctAnswers);
		
	static bool getCorrectAnswer(QJsonObject::const_iterator objectIterator,
		int * correctAnswer);
	
};
	
	
