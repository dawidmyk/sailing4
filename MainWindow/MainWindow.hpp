#pragma once

#include "ui_MainWindow.h"
#include "Defines/TestSuitePointer.hpp"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {

	Q_OBJECT
	
	private:
	std::unique_ptr<Ui::MainWindow> ui;
	
	public:
	MainWindow(ConstTestSuitePointer testSuite, QWidget * parent = nullptr);
	
};
