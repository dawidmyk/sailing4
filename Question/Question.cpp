#include "Question.hpp"

Question::Question(const StringPointer header, const StringPointer category):
    header(header), category(category)
	{
	}
	
ConstStringPointer Question::getHeader() const {
	return header.get();
}

ConstStringPointer Question::getCategory() const {
    return category.get();
}

Question::~Question() {
}
