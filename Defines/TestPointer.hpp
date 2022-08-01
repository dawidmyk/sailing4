#pragma once

#include "Test/Test.hpp"
#include <memory>

typedef Test * TestPointer;

typedef const Test * ConstTestPointer;

typedef std::unique_ptr<Test> TestUniquePointer;
