#include <QApplication>
#include "fetchTests.hpp"
#include "MainWindow/MainWindow.hpp"
#include "Seeker/CurrentDirSeeker.hpp"

int main(int count, char ** const args) {
	QApplication app(count, args);
	SeekerUniquePointer seeker(new CurrentDirSeeker);
	TestSuiteUniquePointer testSuite(fetchTests(seeker.get(), TestFormat::json));
	MainWindow mainWindow(testSuite.get());
	return app.exec();
}
