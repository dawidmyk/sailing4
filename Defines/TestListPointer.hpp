#pragma once

#include "Test/TestList.hpp"
#include <memory>

typedef TestList * TestListPointer;

typedef const TestList * ConstTestListPointer;

typedef std::unique_ptr<TestList> TestListUniquePointer;
