#pragma once

#include "Question/OneChoiceQuestion.hpp"
#include <memory>

typedef OneChoiceQuestion * OneChoiceQuestionPointer;

typedef const OneChoiceQuestion * ConstOneChoiceQuestionPointer;

typedef std::unique_ptr<OneChoiceQuestion> OneChoiceQuestionUniquePointer;
