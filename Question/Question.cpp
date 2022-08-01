#include "Question.hpp"

Question::Question(const StringPointer header): header(header)
	{
	}
	
ConstStringPointer Question::getHeader() const {
	return header.get();
}

Question::~Question() {
}
