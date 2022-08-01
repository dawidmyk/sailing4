#include "QuestionList.hpp"

QuestionList::~QuestionList() {
	QList<QuestionPointer>::const_iterator iterator = constBegin();
	const QList<QuestionPointer>::const_iterator end = constEnd();
	while(iterator != end) {
		delete *iterator;
		++iterator;
	}
}
