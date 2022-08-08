#include "MultiChoiceSolution.hpp"

ConstSetOfIntsPointer MultiChoiceSolution::getChosenAnswers() const {
	return chosenAnswers.get();
}

MultiChoiceSolution::MultiChoiceSolution(const SetOfIntsPointer chosenAnswers): chosenAnswers(chosenAnswers)
	{
	}

MultiChoiceSolution::~MultiChoiceSolution() {
}
