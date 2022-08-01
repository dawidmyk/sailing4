#pragma once

#include "Token.hpp"
#include "Defines/QuestionPointer.hpp"

class QuestionToken : public Token {

	private:
	
	QuestionUniquePointer question;
	
	public:
	
	QuestionToken(QuestionPointer question);
	
	bool isQuestion() const override;
	
	QuestionPointer takeQuestion();
	
	~QuestionToken() override;
	
};
