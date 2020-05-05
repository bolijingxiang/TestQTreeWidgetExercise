#include "CustomDragLabel.h"
#include "DragProxy.h"
#include <qpainter.h>


CustomDragLabel::CustomDragLabel(const TypeKinds& type, QWidget* parent)
	: QLabel(parent)
{
	m_dragFlag = false;
	m_leftFlag = false;
	m_rightFlag = false;
	this->setMouseTracking(true);

	setMinimumSize(100, 100);
	setMaximumSize(800, 800);
	m_type = type;
	switch (type)
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
	m_pDragProxy->SetBorderWidth(20, 20, 20, 20);
	connect(m_pDragProxy, &DragProxy::sendUpdate, this, [=]() {update(); });
	createChildNode(type);
}

CustomDragLabel::CustomDragLabel(const QString& typeKinds, QWidget* parent)
	: QLabel(parent)
{
	m_dragFlag = false;
	m_leftFlag = false;
	m_rightFlag = false;
	this->setMouseTracking(true);

	setMinimumSize(100, 100);
	setMaximumSize(800, 800);

	this->setText(typeKinds);

	this->setAlignment(Qt::AlignCenter);
	// 创建可拖拽、可缩放窗体
	DragProxy *m_pDragProxy = new DragProxy(this);
	m_pDragProxy->SetBorderWidth(20, 20, 20, 20);
	connect(m_pDragProxy, &DragProxy::sendUpdate, this, [=]() {update(); });
	createChildNode(One);
}

CustomDragLabel::~CustomDragLabel()
{
}

void CustomDragLabel::paintEvent(QPaintEvent *event)
{
	QLabel::paintEvent(event);
	//TypeKinds typeKinds;
	//switch (typeKinds)
	//{
	//default:
	//{
	//	QPainter _painter(this);
	//	QColor _color(Qt::red);
	//	QBrush _brush(_color);
	//	_painter.setBrush(_brush);
	//	_painter.drawRect(this->width()-20,this->height()/2-5,10,10);
	//	_painter.drawRect(20-10,this->height()/2-5,10,10);
	//}
	//	break;
	//}
}

void CustomDragLabel::createChildNode(TypeKinds typeKinds)
{
	switch (typeKinds)
	{
	case One:
	case Two:
	case Three:
	case Four:
	{
		NodeWidget* _rightWidget = new NodeWidget(NodeRight, this);
		_rightWidget->setObjectName(this->text());
		_rightWidget->setStyleSheet("background:red;");
		_rightWidget->setFixedSize(10, 10);
		_rightWidget->move(this->width() - 20, this->height() / 2 - 5);

		NodeWidget* _leftWidget = new NodeWidget(NodeLeft, this);
		_leftWidget->setObjectName(this->text());
		_leftWidget->setStyleSheet("background:blue;");
		_leftWidget->setFixedSize(10, 10);
		_leftWidget->move(20 - 10, this->height() / 2 - 5);

		m_listWidget.push_back(_rightWidget);
		m_listWidget.push_back(_leftWidget);
	}
		break;
	default:
		break;
	}
}
