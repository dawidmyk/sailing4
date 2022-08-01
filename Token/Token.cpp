#include "Token.hpp"

bool Token::isEnd() const {
	return false;
}

bool Token::isFail() const {
	return false;
}

bool Token::isQuestion() const {
	return false;
}

Token::~Token() {
}
