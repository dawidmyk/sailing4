#pragma once

#include "Defines/SolutionPointer.hpp"
#include <QList>

class SolutionList : public QList<SolutionPointer> {
    public:
    ~SolutionList();
};