#pragma once

#include "Solution/MultiChoiceSolution.hpp"
#include <memory>

typedef MultiChoiceSolution * MultiChoiceSolutionPointer;

typedef const MultiChoiceSolution * ConstMultiChoiceSolutionPointer;

typedef std::unique_ptr<MultiChoiceSolution> MultiChoiceSolutionUniquePointer;