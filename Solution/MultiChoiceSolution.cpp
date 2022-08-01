#include "MultiChoiceSolution.hpp"

ConstSetOfIntsPointer MultiChoiceSolution::getChosenAnswers() const {
	return chosenAnswers.get();
}
