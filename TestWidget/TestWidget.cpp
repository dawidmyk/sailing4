#include "TestWidget.hpp"
#include <QVBoxLayout>
#include "QuestionWidget/QuestionWidget.hpp"
#include <QSpacerItem>
#include "Marker/BinaryMarker.hpp"
#include <QPushButton>
#include "main/markTest.hpp"

TestWidget::TestWidget(const int nume, const ConstTestPointer test, QWidget * const parent):
	QWidget(parent, Qt::Window),
	ui(new Ui::TestWidget),
	test(test)
{
	ui->setupUi(this);
	setWindowTitle(QString("Rozwiąż test ") + QString::number(nume));
	QVBoxLayout * const layout = new QVBoxLayout(ui->areaWidget);
	const ConstQuestionListPointer questions = test->getQuestions();
	QList<QuestionPointer>::const_iterator iterator = questions->constBegin();
	const QList<QuestionPointer>::const_iterator end = questions->constEnd();
	while(iterator != end) {
		QuestionWidget * const widget = (*iterator)->newQuestionWidget(ui->areaWidget);
		layout->addWidget(widget);
		questionWidgets.append(widget);
		layout->addSpacing(30);
		++iterator;
	}
	QPushButton * const check = new QPushButton(ui->areaWidget);
	layout->addWidget(check);
	check->setText("Sprawdź");
	connect(check, SIGNAL(clicked(bool)), this, SLOT(check()));
	score = new QLabel(ui->areaWidget);
	layout->addWidget(score);
	show();
}

void TestWidget::check() {
	SolvedTestUniquePointer solvedTest(getSolvedTest());
	MarkerUniquePointer marker(new BinaryMarker);
	Mark mark = markTest(test, solvedTest.get(), marker.get());
	score->setText(QString("Wynik: ") + toString(mark));
}

SolvedTestPointer TestWidget::getSolvedTest() const {
	SolutionListPointer solutions = new SolutionList;
	QList<QuestionWidget *>::const_iterator iterator = questionWidgets.constBegin();
	const QList<QuestionWidget *>::const_iterator end = questionWidgets.constEnd();
	while(iterator != end) {
		solutions->append((*iterator)->getSolution());
		++iterator;
	}
	return new SolvedTest(solutions);
}
