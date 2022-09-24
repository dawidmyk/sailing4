#include "QuestionWidget/MultiChoiceQuestionWidget.hpp"
#include "Defines/MultiChoiceSolutionPointer.hpp"

MultiChoiceQuestion::MultiChoiceQuestion(const StringPointer header, const StringPointer category,
                                         const StringListPointer possibleAnswers,
	                                     const SetOfIntsPointer correctAnswers):
	NormalQuestion(header, category, possibleAnswers), correctAnswers(correctAnswers)
	{
	}
	
ConstSetOfIntsPointer MultiChoiceQuestion::getCorrectAnswers() const {
	return correctAnswers.get();
}

QuestionWidget * MultiChoiceQuestion::newQuestionWidget(QWidget * const parent) const {
	return new MultiChoiceQuestionWidget(parent, this);
}

bool MultiChoiceQuestion::fit(const ConstSolutionPointer solution) const {
    const ConstMultiChoiceSolutionPointer castedSolution
        = static_cast<ConstMultiChoiceSolutionPointer>(solution);
    return *correctAnswers == *castedSolution->getChosenAnswers();
}


MultiChoiceQuestion::~MultiChoiceQuestion() {
}
