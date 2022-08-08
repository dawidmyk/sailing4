#pragma once

#include "Defines/NormalQuestionPointer.hpp"
#include "QuestionWidget.hpp"
#include <QRadioButton>
#include <QButtonGroup>

class NormalQuestionWidget : public QuestionWidget {
	
	Q_OBJECT
	
	protected:
	QButtonGroup * group;
	QFormLayout * layout;
	
	public:
	NormalQuestionWidget(QWidget * parent, ConstNormalQuestionPointer question);
	
	virtual ~NormalQuestionWidget() override;
	
};
