#pragma once

#include <QTreeWidget>
#include <qevent.h>
#include <qline.h>
#include <qdrag.h>

class CTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	CTreeWidget(QWidget *parent);
	~CTreeWidget();

protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dragMoveEvent(QDragMoveEvent *event);
	void dropEvent(QDropEvent *event);
	void startDrag(Qt::DropActions supportedActions);
	void paintInsertPos(QTreeWidgetItem *dragItem, QTreeWidgetItem *hitItem);
	void paintTriangle(const QPoint &right, QPainter *painter);

private:
	QLine m_oldLine;
	QLine m_newLine;
	bool m_child;
};
