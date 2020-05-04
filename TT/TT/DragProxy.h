#pragma once

#include <QObject>
#include <qrect>
#include <qwidget.h>
#include <qmap.h>


class DragProxy : public QObject
{
	enum WidgetRegion
	{
		Top,
		Bottom,
		TopRight,
		LeftBottom,
		Right,
		Left,
		RightBottom,
		LeftTop,
		Inner,
		Unknown
	};

	Q_OBJECT

public:
	DragProxy(QWidget *parent);
	~DragProxy();

	WidgetRegion HitTest(const QPoint& pos);
	void MakeRegions();
	void StopCursorTimer();
	void StartCursorTimer();
	bool eventFilter(QObject* obj, QEvent* event);
	void UpdateGeometry(int x, int y, int w, int h);
	void SetBorderWidth(int top, int right, int bottom, int left);

signals:
	void sendUpdate();

private:
	int m_top;
	int m_right;
	int m_bottom;
	int m_left;

	QWidget* m_proxyWidget;
	WidgetRegion m_regionPressed;
	QPoint m_originPosGlobal;

	bool m_mousePressed;
	int m_cursorTimerId;

    QMap<int,QRect> m_regions;
	QRect m_originGeo;
};
