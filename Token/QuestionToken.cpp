#include "QuestionToken.hpp"

QuestionToken::QuestionToken(const QuestionPointer question):
	question(question)
	{
	}
	
bool QuestionToken::isQuestion() const {
	return true;
}

QuestionPointer QuestionToken::takeQuestion() {
	return question.release();
}

QuestionToken::~QuestionToken() {
}
