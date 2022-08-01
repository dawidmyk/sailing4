#pragma once

#include "Defines/QuestionPointer.hpp"
#include <QList>

class QuestionList : public QList<QuestionPointer> {
	
	public:
	~QuestionList();
	
};
