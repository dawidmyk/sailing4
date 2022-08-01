#include "MultiChoiceQuestionWidget.hpp"
#include <QButtonGroup>

MultiChoiceQuestionWidget::MultiChoiceQuestionWidget(QWidget * const parent,
	const ConstMultiChoiceQuestionPointer question):
	NormalQuestionWidget(parent, question)
	{
	group->setExclusive(false); 
	}
	
MultiChoiceQuestionWidget::~MultiChoiceQuestionWidget() {
}
