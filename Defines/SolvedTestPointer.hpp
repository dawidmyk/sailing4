#pragma once

#include "SolvedTest/SolvedTest.hpp"
#include <memory>

typedef SolvedTest * SolvedTestPointer;

typedef const SolvedTest * ConstSolvedTestPointer;

typedef std::unique_ptr<SolvedTest> SolvedTestUniquePointer;