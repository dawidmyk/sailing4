#pragma once

#include "Question/NormalQuestion.hpp"
#include <memory>

typedef NormalQuestion * NormalQuestionPointer;

typedef const NormalQuestion * ConstNormalQuestionPointer;

typedef std::unique_ptr<NormalQuestion> NormalQuestionUniquePointer;
