#pragma once

#include "NormalQuestion.hpp"
#include "Defines/SetOfInts.hpp"

class MultiChoiceQuestion : public NormalQuestion {
	
	private:
	SetOfIntsUniquePointer correctAnswers;
	
	public:
	
	MultiChoiceQuestion(StringPointer header, StringPointer category,
                        StringListPointer possibleAnswers, SetOfIntsPointer correctAnswers);
	
	ConstSetOfIntsPointer getCorrectAnswers() const;
	
	QuestionWidget * newQuestionWidget(QWidget * parent) const override;

    bool fit(ConstSolutionPointer solution) const override;

    ~MultiChoiceQuestion() override;
	
};
	
