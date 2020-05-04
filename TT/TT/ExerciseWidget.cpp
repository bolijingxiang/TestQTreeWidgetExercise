#include "ExerciseWidget.h"
#include <qevent.h>
#include <QMimeData>

ExerciseWidget::ExerciseWidget(QWidget *parent)
	: QTreeWidget(parent)
{
	ui.setupUi(this);

	// 开启鼠标跟踪
	setMouseTracking(true);

	this->setColumnCount(1); //设置列数
	this->setColumnWidth(0, 200); //设置列宽
	this->setHeaderHidden(true); //隐藏标题栏

	//启用拖放
	this->setDragEnabled(true);
	//设置拖放
	this->setAcceptDrops(true);

	//设置显示将要被放置的位置
	this->setDropIndicatorShown(true);

	//设置拖放模式为移动项目，否则为复制项目
	this->setDragDropMode(QAbstractItemView::InternalMove);

	//设置item进入编辑的方式
	this->setEditTriggers(QAbstractItemView::SelectedClicked);
	init();// 初始化项目树
	//createUI();// 初始化文本文字
	QString str="woqihaofangjia";
	m_pCustomDragLabel = new CustomDragLabel(Two, this);

	////connect(m_pCustomDragLabel, SIGNAL(wantToGetPoint()), this, SLOT(receiverSIGNAL()));
	////connect(this, SIGNAL(sendPoint(QPoint)), m_pCustomDragLabel, SLOT(receiverData(QPoint)));

}

ExerciseWidget::~ExerciseWidget()
{
}

void ExerciseWidget::init()
{

}

void ExerciseWidget::dragEnterEvent(QDragEnterEvent * e)
{
	// 如果要配置mimeData层级树的类型，必须是“application/x-qabstractitemmodeldatalist”，具体原因不清楚
	if (e->mimeData()->hasText() || e->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
	{
		QByteArray data = e->mimeData()->data("application/x-qabstractitemmodeldatalist");
		QTreeWidgetItem *item = (QTreeWidgetItem*)((void*)QVariant(data).toInt());

		m_nPos = e->pos();
		QTreeWidgetItem *pItem = this->itemAt(m_nPos);

		if (children().contains(e->source()))
		{
			e->setDropAction(Qt::CopyAction);
			e->accept();
		}
		else
			e->acceptProposedAction();
	}
}

void ExerciseWidget::dragMoveEvent(QDragMoveEvent * e)
{
	if (e->mimeData()->hasText() || e->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
	{
		if (children().contains(e->source()))
		{
			e->setDropAction(Qt::CopyAction);
			e->accept();
		}
		else
			e->acceptProposedAction();
	}
}

void ExerciseWidget::dropEvent(QDropEvent * e)
{
	if (e->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
	{// 配置mimeData类型的层级树
		QByteArray data = e->mimeData()->data("application/x-qabstractitemmodeldatalist");

		QString strr;
		QByteArray strList;
		for (int i = 0; i < data.size(); i++)
		{
			if (data[i] != '\0')
			{
				strList.push_back(data[i]);
			}
		}
		strr = strList;
		strr = QString::fromLocal8Bit(strr.toStdString().data());

		// 创建自定义Label
		CustomDragLabel *label = new CustomDragLabel(Two, this);
		label->setStyleSheet("margin: 8px 8px 8px 8px;border:2px solid black;background-color: rgb(255,255,255);color: rgb(0,0,0);");
		label->move(e->pos());
		label->setAutoFillBackground(true);
		//ui->verticalLayout->addWidget(label);
		label->show();

		if (children().contains(e->source()))
		{
			e->setDropAction(Qt::CopyAction);
			e->accept();
		}
		else
		{
			e->acceptProposedAction();
		}
	}
	else if (e->mimeData()->hasText())
	{// 配置mimeData类型的文本
		QStringList strList = e->mimeData()->text().split(QRegExp("\\s+"), QString::SkipEmptyParts);
		QPoint pos = e->pos();

		foreach(QString str, strList)
		{
			//DragLabel *dragLabel = new DragLabel(str, this);
			//dragLabel->move(pos);
			//dragLabel->show();
			//pos += QPoint(dragLabel->width(), 0);
		}
		if (children().contains(e->source()))
		{
			e->setDropAction(Qt::MoveAction);
			e->accept();
		}
		else
		{
			e->acceptProposedAction();
		}
	}
	else
	{
		e->ignore();
	}
}

void ExerciseWidget::receiverSIGNAL()
{
	QPoint point = mapFromGlobal(QCursor::pos());
	//qDebug()<<point;  不要直接把mapFromGlobal(QCursor::pos())传进去，不然有BUG
	emit sendPoint(point);
}
