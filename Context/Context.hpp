#pragma once

#include "Defines/ParserPointer.hpp"
#include "Defines/StringListPointer.hpp"
#include "Defines/QuestionPointer.hpp"
#include "NextQuestionResult.hpp"

class Context {
	
	private:
	ParserUniquePointer parser;
	QList<StringPointer>::const_iterator iterator;
	const QList<StringPointer>::const_iterator end;
	
	public:
	Context(ConstStringListPointer entryList);
	
	void makeJsonParser();
	
	bool nextTest();
	
	NextQuestionResult nextQuestion(QuestionUniquePointer * question);
	
};
