#pragma once

#include "StringList/StringList.hpp"

typedef StringList * StringListPointer;

typedef const StringList * ConstStringListPointer;

typedef std::unique_ptr<StringList> StringListUniquePointer;
