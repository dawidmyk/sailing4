#include "BinaryMarker.hpp"

PartialMark BinaryMarker::mark(const ConstQuestionPointer question, const ConstSolutionPointer solution) const {
    if(question->fit(solution))
        return PartialMark(1, 1);

    return PartialMark(0, 1);
}

BinaryMarker::~BinaryMarker() {
}
