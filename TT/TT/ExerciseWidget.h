#pragma once

#include <QTreeWidget>
#include "ui_ExerciseWidget.h"
#include "CustomDragLabel.h"
#include <qmap.h>
#include <iostream>

class ExerciseWidget : public QTreeWidget
{
	Q_OBJECT

public:
	ExerciseWidget(QWidget *parent = Q_NULLPTR);
	~ExerciseWidget();

	void init();
	void insertNode(QWidget* lastNode,QWidget* nextNode);
	void deleteNode(QWidget* node);
	void changeNode(QWidget* lastNode, QWidget* nextNode);

	static bool drawingLine;

public slots:
	void reveiceWidget(bool state, QWidget* widget);
	void reveicePos(QPoint mousePoint);

	void reveiceFirstNode(QWidget* widget);
	void reveiceSecondNode(QWidget* widget);
	void reveiceReleaseSig();
	void saveDataToLocal();
	void readDataFromLocal();
signals:
	void sendPoint(QPoint);

protected:
	void dragEnterEvent(QDragEnterEvent *e);
	void dragMoveEvent(QDragMoveEvent *e);
	void dropEvent(QDropEvent * e);
	void receiverSIGNAL();

	void paintEvent(QPaintEvent *event);
	bool viewportEvent(QEvent *event);

private:
	Ui::ExerciseWidget ui;
	CustomDragLabel* m_pCustomDragLabel;
	QPoint m_nPos;

	QMap<QWidget*, QWidget*> m_lineNodesMap;
	QList<CustomDragLabel*> m_curSceneWidgetList;

	QMap<QString, NodeWidget*> m_loadLocalChildNodeData;

	QPoint m_initPos;
	bool m_selectPointPress=false;
	QPoint m_mousePos;

	QWidget* m_firstNode=nullptr;
	QWidget* m_secondNode=nullptr;
};
