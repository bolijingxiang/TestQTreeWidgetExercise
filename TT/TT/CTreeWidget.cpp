#include "CTreeWidget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QDragEnterEvent>
#include <QMimeData>
#define BM_ICON_WIDTH 22

CTreeWidget::CTreeWidget(QWidget *parent)
	: QTreeWidget(parent)
{
	this->setSelectionMode(QAbstractItemView::SingleSelection);
	//启用拖放
	this->setDragEnabled(true);
	//设置拖放
	setAcceptDrops(true);
	//    this->viewport()->setAcceptDrops(true);
		//设置显示将要被放置的位置
	this->setDropIndicatorShown(true);
	//    //设置拖放模式为移动项目，否则为复制项目
	this->setDragDropMode(QAbstractItemView::InternalMove);
	//this->setAttribute(Qt::WA_PaintOutsidePaintEvent);
}

CTreeWidget::~CTreeWidget()
{
}

void CTreeWidget::dragEnterEvent(QDragEnterEvent * event)
{
	if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
		event->accept();
	else
		event->ignore();
}

void CTreeWidget::dragMoveEvent(QDragMoveEvent * event)
{
	if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")) {
		QTreeWidgetItem *hHitTest = itemAt(event->pos());
		event->setDropAction(Qt::MoveAction);
		if (hHitTest)
		{
			QPoint pos = event->pos();
			QRect rect = visualItemRect(hHitTest);
			m_oldLine = m_newLine;
			m_newLine = QLine(rect.bottomLeft(), rect.bottomRight());
			int left = rect.left() + BM_ICON_WIDTH + 3;
			if (pos.x() > left)
			{
				m_newLine.setP1(QPoint(left, m_newLine.y1()));
				m_child = true;
			}
			else
				m_child = false;

			QByteArray itemData = event->mimeData()->data("application/x-qabstractitemmodeldatalist");
			QTreeWidgetItem *dragItem = (QTreeWidgetItem*)((void*)QVariant(itemData).toInt());

			//绘线
			paintInsertPos(dragItem, hHitTest);
		}
		event->accept();
	}
	else
		event->ignore();
}

void CTreeWidget::dropEvent(QDropEvent * event)
{
	if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
	{
		QByteArray itemData = event->mimeData()->data("application/x-qabstractitemmodeldatalist");
		QTreeWidgetItem *item = (QTreeWidgetItem*)((void*)QVariant(itemData).toInt());
		QTreeWidgetItem *pItem = itemAt(event->pos());
		if (pItem == item || pItem == NULL)
		{
			event->ignore();
			return;
		}

		//移除
		if (item->parent())
		{
			item->parent()->removeChild(item);
		}
		else
		{
			takeTopLevelItem(indexOfTopLevelItem(item));
		}
		//插入
		if (pItem &&m_child)
		{
			pItem->insertChild(0, item);
		}
		else if (pItem)
		{
			QTreeWidgetItem *parentItem = pItem->parent();
			if (parentItem)
				parentItem->insertChild(parentItem->indexOfChild(pItem) + 1, item);
			else
				insertTopLevelItem(indexOfTopLevelItem(pItem) + 1, item);
		}
		////////////////////////////////////////////

		event->setDropAction(Qt::MoveAction);
		event->accept();
	}
	else
		event->ignore();
	QTreeWidget::dropEvent(event);
}

void CTreeWidget::startDrag(Qt::DropActions supportedActions)
{
	Q_UNUSED(supportedActions);
	QTreeWidgetItem *item = currentItem();
	if (item == NULL)
		return;

	QString pValue = QString::number(int((void*)item));
	QByteArray itemData;
	itemData = QVariant(pValue).toByteArray();

	QMimeData *mimeData = new QMimeData;
	mimeData->setData("application/x-qabstractitemmodeldatalist", itemData);

	QDrag *drag = new QDrag(this);
	drag->setMimeData(mimeData);

	//设置鼠标移动时，拖动的图片数据
	QPixmap pPixmap("./Resourcesicon/Drag.png");
	pPixmap = pPixmap.scaledToWidth(2);
	drag->setPixmap(pPixmap);
	drag->setHotSpot(QPoint(drag->pixmap().width()/2, drag->pixmap().height()/2));

	if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
	{
	}
}

void CTreeWidget::paintInsertPos(QTreeWidgetItem * dragItem, QTreeWidgetItem * hitItem)
{
	QPainter painter(this);
	painter.save();
	/***********擦除旧线***********/
	//直线
	QPen pen(palette().base().color());
	painter.setPen(pen);
	painter.drawLine(m_oldLine);
	//三角
	paintTriangle(m_oldLine.p1(), &painter);

	//在原item则不绘制线
	if (dragItem == hitItem)
	{
		m_newLine = QLine();
		return;
	}
	/***********绘制新线***********/
	//直线
	pen.setColor(Qt::green);
	pen.setWidth(1);
	painter.setPen(pen);
	painter.drawLine(m_newLine);
	painter.restore();
	//三角
	paintTriangle(m_newLine.p1(), &painter);
}

void CTreeWidget::paintTriangle(const QPoint & right, QPainter * painter)
{
	QPoint top = QPoint(right.x() - 4, right.y() - 3);
	QPoint bottom = QPoint(right.x() - 4, right.y() + 3);
	painter->drawLine(right, top);
	painter->drawLine(top, bottom);
	painter->drawLine(bottom, right);
}
