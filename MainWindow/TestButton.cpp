#include "TestButton.hpp"
#include "TestWidget/TestWidget.hpp"

TestButton::TestButton(const int nume, const ConstTestPointer test, QWidget * const parent):
	QPushButton(parent), nume(nume), test(test) {
	setText(QString("Test ") + QString::number(nume));
	connect(this, SIGNAL(clicked(bool)), this, SLOT(open()));
	}
	
void TestButton::open() {
	new TestWidget(nume, test, parentWidget());
}
