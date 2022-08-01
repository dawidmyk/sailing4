#pragma once

#include <QPushButton>
#include "Defines/TestPointer.hpp"

class TestButton : public QPushButton {

	Q_OBJECT
	
	private:
	int nume;
	ConstTestPointer test;
	
	public:
	TestButton(int nume, ConstTestPointer test, QWidget * parent = nullptr);
	
	private slots:
	
	void open();
	
};
