#include "SolvedTest.hpp"

SolvedTest::SolvedTest(SolutionListPointer solutions):
    solutions(solutions)
    {
    }

ConstSolutionListPointer SolvedTest::getSolutions() const {
    return solutions.get();
}