#pragma once

#include <QLabel>
#include "Struct.h"

class CustomDragLabel : public QLabel
{
	Q_OBJECT

public:
	CustomDragLabel(const TypeKinds& typeKinds, QWidget* parent);
	~CustomDragLabel();

private:
	bool m_dragFlag = false;
	bool m_leftFlag = false;
	bool m_rightFlag = false;
};
