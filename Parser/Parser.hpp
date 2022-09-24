#pragma once

#include "Defines/TestPointer.hpp"
#include "Defines/QuestionPointer.hpp"
#include <QString>

class Parser {
	
	public:

    virtual bool parseTest(const QString & filename, TestUniquePointer * test) = 0;
    virtual bool parseQuestion(const QString & filename, QuestionUniquePointer * question) = 0;
	
	virtual ~Parser();
	
};
