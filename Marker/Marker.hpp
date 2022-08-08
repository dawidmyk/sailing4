#pragma once

#include "Mark/PartialMark.hpp"
#include "Defines/QuestionPointer.hpp"
#include "Defines/SolutionPointer.hpp"

class Marker {
    public:
    virtual PartialMark mark(ConstQuestionPointer question, ConstSolutionPointer solution) const = 0;
    
    virtual ~Marker();
};
