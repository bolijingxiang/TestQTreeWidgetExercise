#pragma once

#include <QObject>
#include <QWidget>

class NodeWidgetEvent : public QObject
{
	Q_OBJECT

public:
	NodeWidgetEvent(QWidget *parent);
	~NodeWidgetEvent();

	bool eventFilter(QObject* obj, QEvent* event);

signals:
	void sendWidget(bool state, QWidget* widget);
	void selectFirstPoint(QWidget*);
	void selectSecondPoint(QWidget*);
	void releaseMousePoint();
	void sendMousePoint(QPoint point);
private:
	QWidget* m_parent = nullptr;
	bool m_mousePressed;
};
