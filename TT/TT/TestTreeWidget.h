#pragma once

#include <QTreeWidget>
#include <qevent.h>

class TestTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	TestTreeWidget(QWidget *parent);
	~TestTreeWidget();

protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);
};
