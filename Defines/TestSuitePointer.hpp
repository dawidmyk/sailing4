#pragma once

#include "TestSuite/TestSuite.hpp"
#include <memory>

typedef TestSuite * TestSuitePointer;

typedef const TestSuite * ConstTestSuitePointer;

typedef std::unique_ptr<TestSuite> TestSuiteUniquePointer;
