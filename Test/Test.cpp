#include "Test.hpp"

Test::Test(const QuestionListPointer questions): questions(questions)
	{
	}
	
ConstQuestionListPointer Test::getQuestions() const {
	return questions.get();
}
