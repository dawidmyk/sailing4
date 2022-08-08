#include "markTest.hpp"

Mark markTest(const ConstTestPointer test, const ConstSolvedTestPointer solvedTest, const ConstMarkerPointer marker) {
	const ConstQuestionListPointer questions = test->getQuestions();
	QList<QuestionPointer>::const_iterator questionIterator = questions->constBegin();
	const QList<QuestionPointer>::const_iterator questionEnd = questions->constEnd();
	QList<SolutionPointer>::const_iterator solutionIterator = solvedTest->getSolutions()->constBegin();
	Mark mark;
	while(questionIterator != questionEnd) {
		mark.add(marker->mark(*questionIterator, *solutionIterator));
		++questionIterator;
		++solutionIterator;
	}
	return mark;
}
