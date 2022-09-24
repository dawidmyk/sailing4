#include "NormalQuestion.hpp"

NormalQuestion::NormalQuestion(const StringPointer header, const StringPointer category,
                               const StringListPointer possibleAnswers):
	Question(header, category), possibleAnswers(possibleAnswers)
	{
	}
	
ConstStringListPointer NormalQuestion::getPossibleAnswers() const {
	return possibleAnswers.get();
}

NormalQuestion::~NormalQuestion() {
}
