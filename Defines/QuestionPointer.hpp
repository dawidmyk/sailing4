#pragma once

#include "Question/Question.hpp"
#include <memory>

typedef Question * QuestionPointer;

typedef const Question * ConstQuestionPointer;

typedef std::unique_ptr<Question> QuestionUniquePointer;
