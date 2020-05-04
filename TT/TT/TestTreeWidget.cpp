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
			QTreeWidgetItem *item = this->itemAt(event->pos()); //��ǰλ�õ�item
			if (item == nullptr)   //������µ�λ��û��item�����˳���û����仰������
				return;
			//���������λ�õ�item�Ƕ���item����ԭ�����Ƕ��㡱���ߡ����µĲ��Ƕ��㣬��ԭ��Ҳ���Ƕ��㡱
			if (-1 == this->indexOfTopLevelItem(item) && (-1 == this->indexOfTopLevelItem(currentItem())) ||
				-1 != this->indexOfTopLevelItem(item) && (-1 != this->indexOfTopLevelItem(currentItem())))

			{
				qDebug() << QStringLiteral("���µ��ı���: ") << event->mimeData()->text();
				item->setText(currentColumn(), event->mimeData()->text());
				event->setDropAction(Qt::MoveAction);
				event->accept();
			}
		}
	}
}
