#include "CustomDragLabel.h"
#include "DragProxy.h"

CustomDragLabel::CustomDragLabel(const TypeKinds& typeKinds, QWidget* parent)
	: QLabel(parent)
{
	m_dragFlag = false;
	m_leftFlag = false;
	m_rightFlag = false;
	this->setMouseTracking(true);

	setMinimumSize(50, 50);
	setMaximumSize(800, 800);

	switch (typeKinds)
	{
	case One:
		this->setText("One");
		break;	
	case Two:
		this->setText("Two");
		break;	
	case Three:
		this->setText("Three");
		break;	
	case Four:
		this->setText("Four");
		break;
	default:
		this->setText("One");
		break;
	}
	this->setAlignment(Qt::AlignCenter);
	// 创建可拖拽、可缩放窗体
	DragProxy *m_pDragProxy = new DragProxy(this);
	m_pDragProxy->SetBorderWidth(10, 10, 10, 10);
	connect(m_pDragProxy, &DragProxy::sendUpdate, this, [=]() {update(); });
}

CustomDragLabel::~CustomDragLabel()
{
}
