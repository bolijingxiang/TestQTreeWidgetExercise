#pragma once

#include <QWidget>
#include "Struct.h"
#include <QObject>


class NodeWidget : public QWidget
{
	Q_OBJECT

public:
	NodeWidget(NodeType type,QWidget *parent=nullptr);
	~NodeWidget();

	NodeType getNodeType() { return m_nodeType; };
	QWidget* curParent() { return m_parent; };

//protected:
//	void mousePressEvent(QMouseEvent *event);
//	void mouseReleaseEvent(QMouseEvent *event);

private:
	NodeType m_nodeType= NodeLeft;
	QWidget* m_parent=nullptr;
};

