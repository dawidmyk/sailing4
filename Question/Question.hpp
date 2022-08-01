#pragma once

#include "Defines/StringPointer.hpp"
#include <QWidget>

class QuestionWidget;

class Solution;

class Question {
	
	private:
	StringUniquePointer header;
	
	public:
	Question(StringPointer header);
	
	ConstStringPointer getHeader() const;
	
	virtual QuestionWidget * newQuestionWidget(QWidget * parent) const = 0;
	
	virtual bool fit(const Solution * solution) const = 0;
	
	virtual ~Question();
	
};
