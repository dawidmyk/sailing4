#pragma once

#include "Defines/MultiChoiceQuestionPointer.hpp"
#include "NormalQuestionWidget.hpp"

class MultiChoiceQuestionWidget : public NormalQuestionWidget {

	Q_OBJECT

	public:
	MultiChoiceQuestionWidget(QWidget * parent, ConstMultiChoiceQuestionPointer question);
	
	~MultiChoiceQuestionWidget() override;

};
