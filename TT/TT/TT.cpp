#include "TT.h"
#include "MyTreeWidget.h"
#include <QHBoxLayout>

TT::TT(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init();
}

void TT::init()
{
	MyTreeWidget* _mytreeWidget = new MyTreeWidget(this);
	//QHBoxLayout* _hbo = new QHBoxLayout;
	//_hbo->setContentsMargins(0, 0, 0, 0);
	//_hbo->addWidget(_mytreeWidget);
}

void TT::creatTreeWidget()
{

}
