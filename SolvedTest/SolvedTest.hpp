#pragma once

#include "Defines/SolutionListPointer.hpp"

class SolvedTest {
    private:
    SolutionListUniquePointer solutions;

    public:
    SolvedTest(SolutionListPointer solutions);

    ConstSolutionListPointer getSolutions() const;

};