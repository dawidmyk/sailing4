#pragma once

#include "Solution.hpp"
#include "Defines/SetOfInts.hpp"

class MultiChoiceSolution : public Solution {

	private:
	SetOfIntsUniquePointer chosenAnswers;
	
	public:
	ConstSetOfIntsPointer getChosenAnswers() const;
	
};
