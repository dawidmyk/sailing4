#include "QuestionWidget/OneChoiceQuestionWidget.hpp"

OneChoiceQuestion::OneChoiceQuestion(const StringPointer header, const StringListPointer possibleAnswers, const int correctAnswer):
	NormalQuestion(header, possibleAnswers), correctAnswer(correctAnswer)
	{
	}
	
int OneChoiceQuestion::getCorrectAnswer() const {
	return correctAnswer;
}

QuestionWidget * OneChoiceQuestion::newQuestionWidget(QWidget * parent) const {
	return new OneChoiceQuestionWidget(parent, this);
}

OneChoiceQuestion::~OneChoiceQuestion() {
}
