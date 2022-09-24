project(sailing LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(headers
    Question/Question.hpp
    Defines/StringPointer.hpp
    Question/NormalQuestion.hpp
    StringList/StringList.hpp
    Defines/StringListPointer.hpp
    Defines/SetOfInts.hpp
    Question/MultiChoiceQuestion.hpp
    Question/OneChoiceQuestion.hpp
    Defines/QuestionPointer.hpp
    QuestionWidget/QuestionWidget.hpp
    Defines/NormalQuestionPointer.hpp
    QuestionWidget/NormalQuestionWidget.hpp
    Defines/MultiChoiceQuestionPointer.hpp
    QuestionWidget/MultiChoiceQuestionWidget.hpp
    Defines/OneChoiceQuestionPointer.hpp
    QuestionWidget/OneChoiceQuestionWidget.hpp
    Parser/Parser.hpp
    Parser/JsonParser.hpp
    Defines/ParserPointer.hpp
    Seeker/Seeker.hpp
    Seeker/CurrentDirSeeker.hpp
    Question/QuestionList.hpp
    Defines/QuestionListPointer.hpp
    Test/Test.hpp
    Defines/TestPointer.hpp
    Test/TestList.hpp
    Defines/TestListPointer.hpp
    TestSuite/TestSuite.hpp
    TestWidget/TestWidget.hpp
    MainWindow/MainWindow.hpp
    MainWindow/TestButton.hpp
    Defines/TestSuitePointer.hpp
    TestFormat/TestFormat.hpp
    main/fetchTests.hpp
    Defines/SeekerPointer.hpp
    Mark/PartialMark.hpp
    Mark/Mark.hpp
    Solution/Solution.hpp
    Solution/OneChoiceSolution.hpp
    Solution/MultiChoiceSolution.hpp
    Marker/Marker.hpp
    Marker/BinaryMarker.hpp
    Defines/SolutionPointer.hpp
    Defines/OneChoiceSolutionPointer.hpp
    Defines/MultiChoiceSolutionPointer.hpp
    Solution/SolutionList.hpp
    Defines/SolutionListPointer.hpp
    SolvedTest/SolvedTest.hpp
    Defines/MarkerPointer.hpp
    main/markTest.hpp )
set(sources
    Question/Question.cpp
    Question/NormalQuestion.cpp
    StringList/StringList.cpp
    Question/MultiChoiceQuestion.cpp
    Question/OneChoiceQuestion.cpp
    QuestionWidget/QuestionWidget.cpp
    QuestionWidget/NormalQuestionWidget.cpp
    QuestionWidget/MultiChoiceQuestionWidget.cpp
    QuestionWidget/OneChoiceQuestionWidget.cpp
    Parser/Parser.cpp
    Parser/JsonParser.cpp
    Seeker/CurrentDirSeeker.cpp
    Question/QuestionList.cpp
    Test/Test.cpp
    Test/TestList.cpp
    TestSuite/TestSuite.cpp
    TestWidget/TestWidget.cpp
    MainWindow/MainWindow.cpp
    MainWindow/TestButton.cpp
    main/main.cpp
    main/fetchTests.cpp
    Seeker/Seeker.cpp
    Mark/PartialMark.cpp
    Mark/Mark.cpp
    Solution/OneChoiceSolution.cpp
    Solution/MultiChoiceSolution.cpp
    Solution/SolutionList.cpp
    SolvedTest/SolvedTest.cpp
    Marker/BinaryMarker.cpp
    main/markTest.cpp
    Solution/Solution.cpp
    Marker/Marker.cpp)

set(forms
    QuestionWidget/QuestionWidget.ui
    TestWidget/TestWidget.ui
    MainWindow/MainWindow.ui)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
add_executable(sailing ${headers} ${sources} ${forms})
target_link_libraries(sailing Qt5::Widgets Qt5::Core Qt5::Gui)
target_compile_options(sailing PRIVATE -fmax-errors=3)