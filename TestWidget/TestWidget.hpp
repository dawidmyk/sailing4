#pragma once

#include "ui_TestWidget.h"
#include "Defines/TestPointer.hpp"
#include "Defines/SolvedTestPointer.hpp"
#include <QLabel>

namespace Ui {
	class TestWidget;
}

class TestWidget : public QWidget {

	Q_OBJECT
	
	private:
	
	std::unique_ptr<Ui::TestWidget> ui;
	QList<QuestionWidget *> questionWidgets;
	ConstTestPointer test;
	QLabel * score;
	
	public:
	
	TestWidget(int nume, ConstTestPointer test, QWidget * parent = nullptr);
	
	private:
	
	SolvedTestPointer getSolvedTest() const;
	
	private slots:
	
	void check();

};
