#pragma once

#include <QLabel>
#include "Struct.h"
#include "NodeWidget.h"

class CustomDragLabel : public QLabel
{
	Q_OBJECT

public:
	CustomDragLabel(const TypeKinds& typeKinds, QWidget* parent);
	CustomDragLabel(const QString& typeKinds, QWidget* parent);
	~CustomDragLabel();

	TypeKinds typeKind() { return m_type; };
	QList<NodeWidget*> getChildNode() { return m_listWidget; };
protected:
	void paintEvent(QPaintEvent *);

private:
	void createChildNode(TypeKinds typeKinds);
	TypeKinds m_type;
	QList<NodeWidget*> m_listWidget;

	bool m_dragFlag = false;
	bool m_leftFlag = false;
	bool m_rightFlag = false;
};
