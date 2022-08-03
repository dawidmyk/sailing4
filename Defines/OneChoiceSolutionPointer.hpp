#pragma once

#include "Solution/OneChoiceSolution.hpp"
#include <memory>

typedef OneChoiceSolution * OneChoiceSolutionPointer;

typedef const OneChoiceSolution * ConstOneChoiceSolutionPointer;

typedef std::unique_ptr<OneChoiceSolution> OneChoiceSolutionUniquePointer;