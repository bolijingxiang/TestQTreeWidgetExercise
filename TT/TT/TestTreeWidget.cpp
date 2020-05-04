#include "TestTreeWidget.h"
#include <QMimeData>
#include <QDebug>

TestTreeWidget::TestTreeWidget(QWidget *parent)
	: QTreeWidget(parent)
{
	this->setSelectionMode(QAbstractItemView::ExtendedSelection);
	this->setDragEnabled(true);
	this->setAcceptDrops(true);
	this->setDefaultDropAction(Qt::MoveAction);
	//this->setDragDropMode(QAbstractItemView::DragDrop);
	this->setDragDropMode(QAbstractItemView::InternalMove);
}

TestTreeWidget::~TestTreeWidget()
{
}

void TestTreeWidget::dragEnterEvent(QDragEnterEvent * event)
{
	QWidget *source = qobject_cast<TestTreeWidget *>(event->source());
	if (source /*&& source != this*/)
	{
		event->setDropAction(Qt::MoveAction);
		/*event->setDropAction(Qt::MoveAction);  */
		event->accept();
	}

}

void TestTreeWidget::dropEvent(QDropEvent * event)
{
	TestTreeWidget *source = qobject_cast<TestTreeWidget *>(event->source());
	if (source /*&& source != this*/)
	{
		TestTreeWidget *source = qobject_cast<TestTreeWidget *>(event->source());
		if (source)
		{
			QTreeWidgetItem *item = this->itemAt(event->pos()); //当前位置的item
			if (item == nullptr)   //如果放下的位置没有item，则退出，没有这句话死机！
				return;
			//如果“放下位置的item是顶层item，且原来的是顶层”或者“放下的不是顶层，且原来也不是顶层”
			if (-1 == this->indexOfTopLevelItem(item) && (-1 == this->indexOfTopLevelItem(currentItem())) ||
				-1 != this->indexOfTopLevelItem(item) && (-1 != this->indexOfTopLevelItem(currentItem())))

			{
				qDebug() << QStringLiteral("放下的文本是: ") << event->mimeData()->text();
				item->setText(currentColumn(), event->mimeData()->text());
				event->setDropAction(Qt::MoveAction);
				event->accept();
			}
		}
	}
}
