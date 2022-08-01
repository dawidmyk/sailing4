#pragma once

#include "NormalQuestion.hpp"
#include "Defines/SetOfInts.hpp"

class MultiChoiceQuestion : public NormalQuestion {
	
	private:
	SetOfIntsUniquePointer correctAnswers;
	
	public:
	
	MultiChoiceQuestion(StringPointer header, StringListPointer possibleAnswers, SetOfIntsPointer correctAnswers);
	
	ConstSetOfIntsPointer getCorrectAnswers() const;
	
	QuestionWidget * newQuestionWidget(QWidget * parent) const override;
	
	~MultiChoiceQuestion() override;
	
};
	
