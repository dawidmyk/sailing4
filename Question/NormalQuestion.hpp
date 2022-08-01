#pragma once

#include "Defines/StringListPointer.hpp"
#include "Question.hpp"

class NormalQuestion : public Question {
	
	private:
	StringListUniquePointer possibleAnswers;
	
	public:
	NormalQuestion(StringPointer header, StringListPointer possibleAnswers);
	
	ConstStringListPointer getPossibleAnswers() const;
	
	virtual ~NormalQuestion() override;
	
};
