#pragma once

#include "Token.hpp"

class EndToken : public Token {
	
	public:
	
	bool isEnd() const override;
	
	~EndToken() override;
	
};
