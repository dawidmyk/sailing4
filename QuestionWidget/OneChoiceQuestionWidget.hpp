#pragma once

#include "Defines/OneChoiceQuestionPointer.hpp"
#include "NormalQuestionWidget.hpp"

class OneChoiceQuestionWidget : public NormalQuestionWidget {
	
	Q_OBJECT
	
	public:
	OneChoiceQuestionWidget(QWidget * parent, ConstOneChoiceQuestionPointer question);
	
	~OneChoiceQuestionWidget() override;
	
	private slots:
	
	void uncheck();
	
};
