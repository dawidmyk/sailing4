#pragma once

#include "Question/QuestionList.hpp"
#include <memory>

typedef QuestionList * QuestionListPointer;

typedef const QuestionList * ConstQuestionListPointer;

typedef std::unique_ptr<QuestionList> QuestionListUniquePointer;
