#pragma once

#include "Defines/TestListPointer.hpp"

class TestSuite {
	private:
	TestListUniquePointer tests;
	
	public:
	TestSuite(TestListPointer tests);
	
	ConstTestListPointer getTests() const;
	
};
