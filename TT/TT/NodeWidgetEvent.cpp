#include "NodeWidgetEvent.h"
#include "ExerciseWidget.h"
#include <qevent.h>
#include <qdebug.h>
#include <qtimer.h>

NodeWidgetEvent::NodeWidgetEvent(QWidget *parent)
	: QObject((QObject*)parent)
{
	m_parent = parent;
	m_parent->setMouseTracking(true);
	m_parent->installEventFilter(this);
	m_mousePressed = false;
	ExerciseWidget * _widget = (ExerciseWidget*)m_parent->parent()->parent();
	//connect(this, &NodeWidgetEvent::sendWidget, _widget, &ExerciseWidget::reveiceWidget);
	connect(this, &NodeWidgetEvent::sendMousePoint, _widget, &ExerciseWidget::reveicePos);
	//connect(this, &NodeWidgetEvent::sigTest, this, [=]() {});
	connect(this,&NodeWidgetEvent::selectFirstPoint,_widget,&ExerciseWidget::reveiceFirstNode);
	connect(this,&NodeWidgetEvent::selectSecondPoint,_widget,&ExerciseWidget::reveiceSecondNode);
	connect(this,&NodeWidgetEvent::releaseMousePoint,_widget,&ExerciseWidget::reveiceReleaseSig);
}


NodeWidgetEvent::~NodeWidgetEvent()
{
}

bool NodeWidgetEvent::eventFilter(QObject * obj, QEvent * event)
{
	QEvent::Type eventType = event->type();

	if (eventType == QEvent::Enter)
	{
		//if (!ExerciseWidget::drawingLine)return false;
		ExerciseWidget::drawingLine = false;
		qDebug() << "QEvent::DragEnter:" << m_parent->objectName();
		//emit sendWidget(false, m_parent);
		emit selectSecondPoint(m_parent);
	}

	if (eventType == QEvent::MouseButtonPress)
	{
		ExerciseWidget::drawingLine = true;
		qDebug() << "QEvent::MouseButtonPress"<<m_parent->objectName();
		emit selectFirstPoint(m_parent);
	}
	else if (eventType == QEvent::MouseButtonRelease)
	{
		QTimer::singleShot(20, [=]() 
		{
			if (ExerciseWidget::drawingLine)
			{
				ExerciseWidget::drawingLine = false;
				qDebug() << "QEvent::MouseButtonRelease" << m_parent->objectName();
				emit releaseMousePoint();
			}
		});


	}
	else if (eventType == QEvent::MouseMove)
	{
		QMouseEvent* mouseEvent = (QMouseEvent*)event;
		QPoint curPosLocal = mouseEvent->pos();
		QWidget* _curParent = m_parent;
		QPoint curPosGlobal;
		QWidget* _tmp = m_parent;
		curPosGlobal = _tmp->mapToParent(curPosLocal);
		int _level = 1;
		while (_level)
		{
			curPosGlobal= _tmp->parentWidget()->mapToParent(curPosGlobal);
			_tmp = _tmp->parentWidget();
			_level--;
		}
		//qDebug() << "QEvent::MouseMove" << m_parent->objectName();
		emit sendMousePoint(curPosGlobal);
		//qDebug() << "curPosGlobal:" << curPosGlobal;
		//QPoint curPosGlobal = m_parent->parentWidget()->mapToParent((m_parent->mapToParent(curPosLocal)));
	}
	return false;
}