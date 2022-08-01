#pragma once

#include "Token/Token.hpp"
#include <memory>

typedef Token * TokenPointer;

typedef const Token * ConstTokenPointer;

typedef std::unique_ptr<Token> TokenUniquePointer;
