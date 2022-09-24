#include "fetchTests.hpp"
#include "Defines/StringListPointer.hpp"
#include "Defines/TestListPointer.hpp"
#include "Defines/ParserPointer.hpp"
#include "Parser/JsonParser.hpp"

TestSuitePointer fetchTests(const SeekerPointer seeker, const TestFormat format) {
	
	StringListUniquePointer entries(seeker->takeEntryList());
    ParserUniquePointer parser;
    switch(format) {
        case TestFormat::json:
            parser.reset(new JsonParser);
            break;
    }
	
	TestListUniquePointer tests(new TestList);
    QList<StringPointer>::const_iterator it = entries->constBegin();
    const QList<StringPointer>::const_iterator end = entries->constEnd();
		
	while(it != end) {
		TestUniquePointer test;
		if(parser->parseTest(**it, &test))
            tests->append(test.release());
        ++it;
	}
	return new TestSuite(tests.release());
	
}
