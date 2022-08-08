#pragma once

#include "Defines/QuestionPointer.hpp"
#include "Defines/SolutionPointer.hpp"
#include "ui_QuestionWidget.h"

namespace Ui {
	class QuestionWidget;
}

class QuestionWidget : public QWidget {

	Q_OBJECT
	
	protected:
	std::unique_ptr<Ui::QuestionWidget> ui;

	public:
	QuestionWidget(QWidget * parent, ConstQuestionPointer question);
	
	virtual SolutionPointer getSolution() const = 0;
	
	virtual ~QuestionWidget();
	
};
