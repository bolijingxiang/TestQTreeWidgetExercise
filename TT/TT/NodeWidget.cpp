#include "NodeWidget.h"
#include <qevent.h>
#include "ExerciseWidget.h"
#include "NodeWidgetEvent.h"
#include <qdebug.h>

NodeWidget::NodeWidget(NodeType type,QWidget *parent)
	: QWidget(parent), m_nodeType(type)
{
	setAttribute(Qt::WA_StyledBackground);
	m_parent = parent == nullptr ? nullptr : parent;
	NodeWidgetEvent* _nodewidget = new NodeWidgetEvent(this);
}

NodeWidget::~NodeWidget()
{

}

//void NodeWidget::mousePressEvent(QMouseEvent * event)
//{
//	
//}
//
//void NodeWidget::mouseReleaseEvent(QMouseEvent * event)
//{
//	qDebug() <<"m_parent->parent->objectName():"<<this->objectName();
//}



