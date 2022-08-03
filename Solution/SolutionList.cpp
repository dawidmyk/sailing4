#include "SolutionList.hpp"

SolutionList::~SolutionList() {
    QList<SolutionPointer>::const_iterator iterator = constBegin();
    const QList<SolutionPointer>::const_iterator end = constEnd();
    while(iterator != end) {
        delete *iterator;
        ++iterator;
    }
}