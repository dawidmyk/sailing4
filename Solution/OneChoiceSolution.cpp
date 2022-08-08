#include "OneChoiceSolution.hpp"

int OneChoiceSolution::getChosenAnswer() const {
	return chosenAnswer;
}

OneChoiceSolution::OneChoiceSolution(const int chosenAnswer): chosenAnswer(chosenAnswer)
	{
	}

OneChoiceSolution::~OneChoiceSolution() {
}
