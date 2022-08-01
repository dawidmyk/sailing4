#pragma once

#include "Defines/QuestionListPointer.hpp"

class Test {
	private:
	QuestionListUniquePointer questions;
	
	public:
	Test(QuestionListPointer questions);
	
	ConstQuestionListPointer getQuestions() const;
	
};
