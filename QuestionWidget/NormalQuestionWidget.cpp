#include "NormalQuestionWidget.hpp"
#include <QRadioButton>

NormalQuestionWidget::NormalQuestionWidget(QWidget * const parent, const ConstNormalQuestionPointer question):
	QuestionWidget(parent, question)
	{
	QFormLayout * const layout = new QFormLayout(ui->possibleAnswers);
	group = new QButtonGroup(ui->possibleAnswers);
	const ConstStringListPointer possibleAnswers = question->getPossibleAnswers();
	QList<StringPointer>::const_iterator iterator = possibleAnswers->constBegin();
	const QList<StringPointer>::const_iterator end = possibleAnswers->constEnd();
	while(iterator != end) {
		QRadioButton * const button = new QRadioButton(ui->possibleAnswers);
		button->setText(**iterator);
		group->addButton(button);
		this->possibleAnswers.append(button);
		layout->addWidget(button);
		++iterator;
	}
}

NormalQuestionWidget::~NormalQuestionWidget() {
}
