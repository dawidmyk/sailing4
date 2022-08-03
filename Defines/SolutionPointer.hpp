#pragma once

#include "Solution/Solution.hpp"
#include <memory>

typedef Solution * SolutionPointer;

typedef const Solution * ConstSolutionPointer;

typedef std::unique_ptr<Solution> SolutionUniquePointer;