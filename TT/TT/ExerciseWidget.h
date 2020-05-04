#pragma once

#include <QTreeWidget>
#include "ui_ExerciseWidget.h"
#include "CustomDragLabel.h"

class ExerciseWidget : public QTreeWidget
{
	Q_OBJECT

public:
	ExerciseWidget(QWidget *parent = Q_NULLPTR);
	~ExerciseWidget();

	void init();

signals:
	void sendPoint(QPoint);

protected:
	void dragEnterEvent(QDragEnterEvent *e);
	void dragMoveEvent(QDragMoveEvent *e);
	void dropEvent(QDropEvent *e);
	void receiverSIGNAL();
private:
	Ui::ExerciseWidget ui;

	CustomDragLabel* m_pCustomDragLabel;

	QPoint m_nPos;
};
