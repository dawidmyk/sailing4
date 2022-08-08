#include "MultiChoiceQuestionWidget.hpp"
#include "Solution/MultiChoiceSolution.hpp"

MultiChoiceQuestionWidget::MultiChoiceQuestionWidget(QWidget * const parent,
	const ConstMultiChoiceQuestionPointer question):
	NormalQuestionWidget(parent, question)
	{
	group->setExclusive(false); 
	const ConstStringListPointer possibleAnswers = question->getPossibleAnswers();
	QList<StringPointer>::const_iterator iterator = possibleAnswers->constBegin();
	const QList<StringPointer>::const_iterator end = possibleAnswers->constEnd();
	while(iterator != end) {
		QCheckBox * const button = new QCheckBox(ui->possibleAnswers);
		button->setText(**iterator);
		group->addButton(button);
		this->possibleAnswers.append(button);
		layout->addWidget(button);
		++iterator;
	}
	}
	
SolutionPointer MultiChoiceQuestionWidget::getSolution() const {
	const SetOfIntsPointer chosenAnswers = new SetOfInts;
	QList<QCheckBox *>::const_iterator iterator = possibleAnswers.constBegin();
	const QList<QCheckBox *>::const_iterator end = possibleAnswers.constEnd();
	int i = 1;
	while(iterator != end) {
		if((*iterator)->isChecked())
			(*chosenAnswers) += i;
		++i;
		++iterator;
	}
	return new MultiChoiceSolution(chosenAnswers);
}
	
MultiChoiceQuestionWidget::~MultiChoiceQuestionWidget() {
}
