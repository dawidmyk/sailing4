#pragma once

#include "Token.hpp"

class FailToken : public Token {
	
	public:
	
	bool isFail() const override;
	
	~FailToken() override;
	
};
