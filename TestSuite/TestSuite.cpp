#include "TestSuite.hpp"

TestSuite::TestSuite(const TestListPointer tests): tests(tests)
	{
	}
	
ConstTestListPointer TestSuite::getTests() const {
	return tests.get();
}
