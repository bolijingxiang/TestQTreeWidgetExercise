#pragma once
#include <qwidget.h>

enum TypeKinds
{
	One,
	Two,
	Three,
	Four
};

enum NodeType
{
	NodeLeft,
	NodeRight
};

struct LineNode
{
	QWidget* lastNode;
	QWidget* nextNode;
};
//Q_DECLARE_METATYPE(TypeKinds);