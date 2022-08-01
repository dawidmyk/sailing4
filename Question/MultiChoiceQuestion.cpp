#include "QuestionWidget/MultiChoiceQuestionWidget.hpp"

MultiChoiceQuestion::MultiChoiceQuestion(const StringPointer header, const StringListPointer possibleAnswers,
	const SetOfIntsPointer correctAnswers):
	NormalQuestion(header, possibleAnswers), correctAnswers(correctAnswers)
	{
	}
	
ConstSetOfIntsPointer MultiChoiceQuestion::getCorrectAnswers() const {
	return correctAnswers.get();
}

QuestionWidget * MultiChoiceQuestion::newQuestionWidget(QWidget * const parent) const {
	return new MultiChoiceQuestionWidget(parent, this);
}

MultiChoiceQuestion::~MultiChoiceQuestion() {
}
