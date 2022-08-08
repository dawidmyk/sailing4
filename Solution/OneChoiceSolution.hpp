#pragma once

#include "Solution.hpp"

class OneChoiceSolution : public Solution {
	private:
	int chosenAnswer;
	
	public:
	int getChosenAnswer() const;
	
	OneChoiceSolution(int chosenAnswer);
	
	~OneChoiceSolution() override;
	
};
