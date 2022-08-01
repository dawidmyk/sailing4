#include "OneChoiceQuestionWidget.hpp"

OneChoiceQuestionWidget::OneChoiceQuestionWidget(QWidget * const parent,
	const ConstOneChoiceQuestionPointer question):
	NormalQuestionWidget(parent, question)
	{
	QList<QRadioButton *>::const_iterator iterator = possibleAnswers.constBegin();
	const QList<QRadioButton *>::const_iterator end = possibleAnswers.constEnd();
	while(iterator != end) {
		connect(*iterator, SIGNAL(clicked(bool)), this, SLOT(uncheck())); 
		++iterator;
	}
	}
	
OneChoiceQuestionWidget::~OneChoiceQuestionWidget() {
}

void OneChoiceQuestionWidget::uncheck() {
	QRadioButton * radioButton = static_cast<QRadioButton *>(sender());
	if(radioButton->isChecked())
		radioButton->setChecked(false);
}
