#include "TestList.hpp"

TestList::~TestList() {
	QList<TestPointer>::const_iterator iterator = constBegin();
	const QList<TestPointer>::const_iterator end = constEnd();
	while(iterator != end) {
		delete *iterator;
		++iterator;
	}
}
