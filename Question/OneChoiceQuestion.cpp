#include "QuestionWidget/OneChoiceQuestionWidget.hpp"
#include "Defines/OneChoiceSolutionPointer.hpp"

OneChoiceQuestion::OneChoiceQuestion(const StringPointer header, const StringPointer category,
                                     const StringListPointer possibleAnswers, const int correctAnswer):
	NormalQuestion(header, category, possibleAnswers), correctAnswer(correctAnswer)
	{
	}
	
int OneChoiceQuestion::getCorrectAnswer() const {
	return correctAnswer;
}

QuestionWidget * OneChoiceQuestion::newQuestionWidget(QWidget * const parent) const {
	return new OneChoiceQuestionWidget(parent, this);
}

bool OneChoiceQuestion::fit(const ConstSolutionPointer solution) const {
    const ConstOneChoiceSolutionPointer castedSolution = static_cast<ConstOneChoiceSolutionPointer>(solution);
    return correctAnswer == castedSolution->getChosenAnswer();
}


OneChoiceQuestion::~OneChoiceQuestion() {
}
