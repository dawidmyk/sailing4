#include "fetchTests.hpp"
#include "Defines/StringListPointer.hpp"
#include "Context/Context.hpp"
#include "Defines/TestListPointer.hpp"

TestSuitePointer fetchTests(const SeekerPointer seeker, const TestFormat format) {
	
	StringListUniquePointer entries(seeker->takeEntryList());
	Context context(entries.get());
	
	context.makeJsonParser();
	
	TestListUniquePointer tests(new TestList);
		
	while(context.nextTest()) {
		QuestionListUniquePointer questions(new QuestionList);
		NextQuestionResult result;
		QuestionUniquePointer question;
		while((result = context.nextQuestion(&question)) == NextQuestionResult::success) {
			questions->append(question.release());
		}
		if(result == NextQuestionResult::end) {
			tests->append(new Test(questions.release()));
		}
	}
	return new TestSuite(tests.release());
	
}
