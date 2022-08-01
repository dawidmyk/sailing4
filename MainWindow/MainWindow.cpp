#include "MainWindow.hpp"
#include <QVBoxLayout>
#include "TestButton.hpp"

MainWindow::MainWindow(const ConstTestSuitePointer testSuite, QWidget * const parent): QMainWindow(parent), ui(new Ui::MainWindow)
	{
	ui->setupUi(this);
	QVBoxLayout * const layout = new QVBoxLayout(ui->centralWidget);
	const ConstTestListPointer tests = testSuite->getTests();
	QList<TestPointer>::const_iterator iterator = tests->constBegin();
	const QList<TestPointer>::const_iterator end = tests->constEnd();
	int nume = 0;
	while(iterator != end) {
		TestButton * const button = new TestButton(++nume, *iterator, ui->centralWidget);
		layout->addWidget(button);
		++iterator;
	}
	show();
	}
