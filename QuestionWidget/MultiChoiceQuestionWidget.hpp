#pragma once

#include "Defines/MultiChoiceQuestionPointer.hpp"
#include "NormalQuestionWidget.hpp"
#include <QCheckBox>

class MultiChoiceQuestionWidget : public NormalQuestionWidget {

	Q_OBJECT
	
	private:
	QList<QCheckBox *> possibleAnswers;

	public:
	MultiChoiceQuestionWidget(QWidget * parent, ConstMultiChoiceQuestionPointer question);
	
	SolutionPointer getSolution() const override;
	
	~MultiChoiceQuestionWidget() override;
	
};
