#include "NormalQuestion.hpp"

NormalQuestion::NormalQuestion(const StringPointer header, const StringListPointer possibleAnswers):
	Question(header), possibleAnswers(possibleAnswers)
	{
	}
	
ConstStringListPointer NormalQuestion::getPossibleAnswers() const {
	return possibleAnswers.get();
}

NormalQuestion::~NormalQuestion() {
}
