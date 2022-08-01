QT += core gui widgets
CONFIG += debug
TARGET = sailing
TEMPLATE = app
SOURCES += Question/Question.cpp \
	Question/NormalQuestion.cpp \
	StringList/StringList.cpp \
	Question/MultiChoiceQuestion.cpp \
	Question/OneChoiceQuestion.cpp \
	QuestionWidget/QuestionWidget.cpp \
	QuestionWidget/NormalQuestionWidget.cpp \
	QuestionWidget/MultiChoiceQuestionWidget.cpp \
	QuestionWidget/OneChoiceQuestionWidget.cpp \
	Parser/Parser.cpp \
	Parser/JsonParser.cpp \
	Token/Token.cpp \
	Token/EndToken.cpp \
	Token/FailToken.cpp \
	Token/QuestionToken.cpp \
	Context/Context.cpp \
	Seeker/CurrentDirSeeker.cpp \
	Question/QuestionList.cpp \
	Test/Test.cpp \
	Test/TestList.cpp \
	TestSuite/TestSuite.cpp \
	TestWidget/TestWidget.cpp \
	MainWindow/MainWindow.cpp \
	MainWindow/TestButton.cpp \
	main/main.cpp \
	main/fetchTests.cpp \
	Seeker/Seeker.cpp \
	Mark/PartialMark.cpp \
	Mark/Mark.cpp \
	Solution/OneChoiceSolution.cpp \
	Solution/MultiChoiceSolution.cpp
HEADERS += Question/Question.hpp \
	Defines/StringPointer.hpp \
	Question/NormalQuestion.hpp \
	StringList/StringList.hpp \
	Defines/StringListPointer.hpp \
	Defines/SetOfInts.hpp \
	Question/MultiChoiceQuestion.hpp \
	Question/OneChoiceQuestion.hpp \
	Defines/QuestionPointer.hpp \
	QuestionWidget/QuestionWidget.hpp \
	Defines/NormalQuestionPointer.hpp \
	QuestionWidget/NormalQuestionWidget.hpp \
	Defines/MultiChoiceQuestionPointer.hpp \
	QuestionWidget/MultiChoiceQuestionWidget.hpp \
	Defines/OneChoiceQuestionPointer.hpp \
	QuestionWidget/OneChoiceQuestionWidget.hpp \
	Token/Token.hpp \
	Parser/Parser.hpp \
	Parser/JsonParser.hpp \
	Token/Token.hpp \
	Token/EndToken.hpp \
	Token/FailToken.hpp \
	Token/QuestionToken.hpp \
	Defines/TokenPointer.hpp \
	Defines/ParserPointer.hpp \
	Context/NextQuestionResult.hpp \
	Context/Context.hpp \
	Seeker/Seeker.hpp \
	Seeker/CurrentDirSeeker.hpp \
	Question/QuestionList.hpp \
	Defines/QuestionListPointer.hpp \
	Test/Test.hpp \
	Defines/TestPointer.hpp \
	Test/TestList.hpp \
	Defines/TestListPointer.hpp \
	TestSuite/TestSuite.hpp \
	TestWidget/TestWidget.hpp \
	MainWindow/MainWindow.hpp \
	MainWindow/TestButton.hpp \
	Defines/TestSuitePointer.hpp \
	TestFormat/TestFormat.hpp \
	main/fetchTests.hpp \
	Defines/SeekerPointer.hpp \
	Mark/PartialMark.hpp \
	Mark/Mark.hpp \
	Solution/Solution.hpp \
	Solution/OneChoiceSolution.hpp \
	Solution/MultiChoiceSolution.hpp
	
QMAKE_CXXFLAGS += -fmax-errors=3
FORMS += QuestionWidget/QuestionWidget.ui \
	TestWidget/TestWidget.ui \
	MainWindow/MainWindow.ui
