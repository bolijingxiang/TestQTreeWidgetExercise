#include "ExerciseWidget.h"
#include <qevent.h>
#include <QMimeData>

ExerciseWidget::ExerciseWidget(QWidget *parent)
	: QTreeWidget(parent)
{
	ui.setupUi(this);

	// ����������
	setMouseTracking(true);

	this->setColumnCount(1); //��������
	this->setColumnWidth(0, 200); //�����п�
	this->setHeaderHidden(true); //���ر�����

	//�����Ϸ�
	this->setDragEnabled(true);
	//�����Ϸ�
	this->setAcceptDrops(true);

	//������ʾ��Ҫ�����õ�λ��
	this->setDropIndicatorShown(true);

	//�����Ϸ�ģʽΪ�ƶ���Ŀ������Ϊ������Ŀ
	this->setDragDropMode(QAbstractItemView::InternalMove);

	//����item����༭�ķ�ʽ
	this->setEditTriggers(QAbstractItemView::SelectedClicked);
	init();// ��ʼ����Ŀ��
	//createUI();// ��ʼ���ı�����
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
	// ���Ҫ����mimeData�㼶�������ͣ������ǡ�application/x-qabstractitemmodeldatalist��������ԭ�����
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
	{// ����mimeData���͵Ĳ㼶��
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

		// �����Զ���Label
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
	{// ����mimeData���͵��ı�
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
	//qDebug()<<point;  ��Ҫֱ�Ӱ�mapFromGlobal(QCursor::pos())����ȥ����Ȼ��BUG
	emit sendPoint(point);
}
