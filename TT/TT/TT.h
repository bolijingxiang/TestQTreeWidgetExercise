#pragma once

#include <QtWidgets/QWidget>
#include "ui_TT.h"

class TT : public QWidget
{
	Q_OBJECT

public:
	TT(QWidget *parent = Q_NULLPTR);

private:
	Ui::TTClass ui;

	void init();
	void enableInit() {};
	void leave() {};

	void creatTreeWidget();
};
