#pragma once

#include "Defines/StringPointer.hpp"
#include "Defines/SolutionPointer.hpp"
#include <QWidget>

class QuestionWidget;

class Question {
	
	private:
	StringUniquePointer header;
	
	public:
	Question(StringPointer header);
	
	ConstStringPointer getHeader() const;
	
	virtual QuestionWidget * newQuestionWidget(QWidget * parent) const = 0;
	
	virtual bool fit(ConstSolutionPointer solution) const = 0;
	
	virtual ~Question();
	
};
