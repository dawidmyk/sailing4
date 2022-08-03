#pragma once

#include "Solution/SolutionList.hpp"
#include <memory>

typedef SolutionList * SolutionListPointer;

typedef const SolutionList * ConstSolutionListPointer;

typedef std::unique_ptr<SolutionList> SolutionListUniquePointer;