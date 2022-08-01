#pragma once

#include <QSet>
#include <memory>

typedef QSet<int> SetOfInts;

typedef SetOfInts * SetOfIntsPointer;

typedef const SetOfInts * ConstSetOfIntsPointer;

typedef std::unique_ptr<SetOfInts> SetOfIntsUniquePointer;
