#include "QuestionWidget.hpp"

QuestionWidget::QuestionWidget(QWidget * const parent, const ConstQuestionPointer question):
	QWidget(parent), ui(new Ui::QuestionWidget)
	{
	ui->setupUi(this);
	ui->header->setText(*question->getHeader());
	}

QuestionWidget::~QuestionWidget() {
}
