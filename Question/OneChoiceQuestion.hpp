#pragma once

#include "NormalQuestion.hpp"

class OneChoiceQuestion : public NormalQuestion {

	private:
	int correctAnswer;
	
	public:
	OneChoiceQuestion(StringPointer header, StringPointer category,
                      StringListPointer possibleAnswers, int correctAnswer);
	
	int getCorrectAnswer() const;
	
	QuestionWidget * newQuestionWidget(QWidget * parent) const override;
	
	bool fit(ConstSolutionPointer solution) const override;
	
	~OneChoiceQuestion() override;
	
};
