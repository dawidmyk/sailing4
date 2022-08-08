#include "OneChoiceQuestionWidget.hpp"
#include "Solution/OneChoiceSolution.hpp"

OneChoiceQuestionWidget::OneChoiceQuestionWidget(QWidget * const parent,
	const ConstOneChoiceQuestionPointer question):
	NormalQuestionWidget(parent, question)
	{
	const ConstStringListPointer possibleAnswers = question->getPossibleAnswers();
	QList<StringPointer>::const_iterator iterator = possibleAnswers->constBegin();
	const QList<StringPointer>::const_iterator end = possibleAnswers->constEnd();
	int i = 1;
	while(iterator != end) {
		QRadioButton * const button = new QRadioButton(ui->possibleAnswers);
		button->setText(**iterator);
		group->addButton(button);
		group->setId(button, i);
		layout->addWidget(button);
		connect(button, SIGNAL(clicked(bool)), this, SLOT(uncheck()));
		++i;
		++iterator;
	}
	}
	
SolutionPointer OneChoiceQuestionWidget::getSolution() const {
	return new OneChoiceSolution(group->checkedId());
}

OneChoiceQuestionWidget::~OneChoiceQuestionWidget() {
}

void OneChoiceQuestionWidget::uncheck() {
	QRadioButton * radioButton = static_cast<QRadioButton *>(sender());
	if(radioButton->isChecked())
		radioButton->setChecked(false);
}
