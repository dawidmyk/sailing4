#include "StringList.hpp"

StringList::~StringList() {
	QList<StringPointer>::const_iterator iterator = constBegin();
	const QList<StringPointer>::const_iterator end = constEnd();
	while(iterator != end) {
		delete *iterator;
		++iterator;
	}
}
