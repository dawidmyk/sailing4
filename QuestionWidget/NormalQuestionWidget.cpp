#include "NormalQuestionWidget.hpp"
#include <QRadioButton>

NormalQuestionWidget::NormalQuestionWidget(QWidget * const parent, const ConstNormalQuestionPointer question):
	QuestionWidget(parent, question)
	{
	layout = new QFormLayout(ui->possibleAnswers);
	group = new QButtonGroup(ui->possibleAnswers);
	}

NormalQuestionWidget::~NormalQuestionWidget() {
}
