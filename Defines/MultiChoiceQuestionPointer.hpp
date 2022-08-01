#pragma once

#include "Question/MultiChoiceQuestion.hpp"
#include <memory>

typedef MultiChoiceQuestion * MultiChoiceQuestionPointer;

typedef const MultiChoiceQuestion * ConstMultiChoiceQuestionPointer;

typedef std::unique_ptr<MultiChoiceQuestion> MultiChoiceQuestionUniquePointer;
