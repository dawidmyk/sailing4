#pragma once

#include "Defines/SeekerPointer.hpp"
#include "Defines/TestSuitePointer.hpp"
#include "TestFormat/TestFormat.hpp"

TestSuitePointer fetchTests(SeekerPointer seeker, TestFormat format);
