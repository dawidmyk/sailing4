#pragma once

#include "Parser.hpp"
#include <memory>
#include <QJsonArray>
#include "Defines/StringListPointer.hpp"
#include "Defines/SetOfInts.hpp"
#include <QJsonObject>

class JsonParser : public Parser {
	
	private:
	std::unique_ptr<QJsonArray> array;
	
	QJsonArray::const_iterator iterator;
	
	QJsonArray::const_iterator end;

	public:
	
	void setSource(const QString & filename) override;
	
	TokenPointer nextToken() override;
	
	~JsonParser() override;
	
	private:
		
	static bool getHeader(QJsonObject::const_iterator objectIterator, StringUniquePointer * header);

	static bool getPossibleAnswers(QJsonObject::const_iterator objectIterator,
		StringListUniquePointer * possibleAnswers);
		
	static bool getCorrectAnswers(QJsonObject::const_iterator objectIterator,
		SetOfIntsUniquePointer * correctAnswers);
		
	static bool getCorrectAnswer(QJsonObject::const_iterator objectIterator,
		int * correctAnswer);
	
};
	
	
