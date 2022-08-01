#pragma once

#include "ui_TestWidget.h"
#include "Defines/TestPointer.hpp"

namespace Ui {
	class TestWidget;
}

class TestWidget : public QWidget {

	Q_OBJECT
	
	private:
	
	std::unique_ptr<Ui::TestWidget> ui;
	
	public:
	
	TestWidget(int nume, ConstTestPointer test, QWidget * parent = nullptr);

};
