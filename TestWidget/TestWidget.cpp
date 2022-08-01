#include "TestWidget.hpp"
#include <QVBoxLayout>
#include "QuestionWidget/QuestionWidget.hpp"
#include <QSpacerItem>

TestWidget::TestWidget(const int nume, const ConstTestPointer test, QWidget * const parent):
	QWidget(parent, Qt::Window),
	ui(new Ui::TestWidget)	
{
	ui->setupUi(this);
	setWindowTitle(QString("Rozwiąż test ") + QString::number(nume));
	QVBoxLayout * const layout = new QVBoxLayout(this);
	const ConstQuestionListPointer questions = test->getQuestions();
	QList<QuestionPointer>::const_iterator iterator = questions->constBegin();
	const QList<QuestionPointer>::const_iterator end = questions->constEnd();
	while(iterator != end) {
		QuestionWidget * const widget = (*iterator)->newQuestionWidget(this);
		layout->addWidget(widget);
		layout->addSpacing(30);
		++iterator;
	}
	show();
}
