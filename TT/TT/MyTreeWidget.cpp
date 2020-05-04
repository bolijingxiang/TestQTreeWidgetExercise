#include "MyTreeWidget.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QDropEvent>
#include <QMimeData>
#include "CustomDragLabel.h"
#include <qapplication.h>
#include <qevent.h>
#include <qdrag.h>
#include <qdebug.h>
#include <qobject.h>
#include <QPainter>
#include <qspinbox.h>
#include <QModelIndex>
#include <QAbstractItemModel>

int g_x=0;
MyTreeWidget::MyTreeWidget(QWidget *parent)
	: QTreeWidget(parent)
{
	init();
}

MyTreeWidget::~MyTreeWidget()
{
}

//void MyTreeWidget::mousePressEvent(QMouseEvent * e)
//{
//	QTreeWidgetItem *item = currentItem();
//	if (item == NULL|| item->parent()==nullptr)
//		return;
//
//	QString pValue = QString::number(int((void*)item));
//	QByteArray itemData;
//	itemData = QVariant(pValue).toByteArray();
//
//	QMimeData *mimeData = new QMimeData;
//	mimeData->setData("application/x-qabstractitemmodeldatalist", itemData);
//	//
//	//QDrag *drag = new QDrag(this);
//	//mimeData->setText("KK");
//	//drag->setMimeData(mimeData);
//	//drag->setHotSpot(QPoint(drag->pixmap().width() / 2, drag->pixmap().height() / 2));
//	//drag->setPixmap(QPixmap("./Resources/icon/putonganbaodengji1.png"));
//	//
//	//drag->setDragCursor(QPixmap("./Resources/icon/putonganbaodengji1.png"),Qt::CopyAction);
//	//Qt::DropAction dropAction=drag->exec(Qt::MoveAction | Qt::CopyAction, Qt::LinkAction);
//
//	QWidget* _te = new QWidget();
//	_te->setFixedSize(40, 40);
//	QLabel* _label = new QLabel(QStringLiteral("我七号放假"),_te);
//	_label->setFixedSize(_te->width(), _te->height());
//	QPixmap pixmap=_te->grab();
//	//QPixmap pixmap = dragPiamap->grab();
//
//	QDrag* drag = new QDrag(this);
//	drag->setPixmap(pixmap);
//	drag->setMimeData(mimeData);
//	drag->setHotSpot(QPoint(0,0));
//
//	Qt::DropAction dropAction=drag->exec(Qt::MoveAction);
//
//	//QPixmap pPixmap("./Resources/icon/lishijilu1.png");
//	//pPixmap = pPixmap.scaledToWidth(2);
//	//drag->setPixmap(pPixmap);
//	//drag->setHotSpot(QPoint(drag->pixmap().width() / 2, drag->pixmap().height() / 2));
//
//	//hide();
//
//
//	//qDebug() << "HH" << endl;
//	//Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
//
//	//if (dropAction == Qt::MoveAction)
//	//	close();
//	//else
//	//	show();
//
//}

void MyTreeWidget::dragEnterEvent(QDragEnterEvent * event)
{
	QWidget *source = qobject_cast<MyTreeWidget *>(event->source());
	if (source /*&& source != this*/)
	{
		event->setDropAction(Qt::MoveAction);
		/*event->setDropAction(Qt::MoveAction);  */
		event->accept();
	}
}

void MyTreeWidget::dragMoveEvent(QDragMoveEvent * event)
{
	QWidget *source = qobject_cast<MyTreeWidget *>(event->source());
	if (source /*&& source != this*/)
	{
		event->setDropAction(Qt::MoveAction);
		event->accept();
	}
}

void MyTreeWidget::dropEvent(QDropEvent * event)
{
	MyTreeWidget *source = qobject_cast<MyTreeWidget *>(event->source());
	if (source /*&& source != this*/)
	{
		MyTreeWidget *source = qobject_cast<MyTreeWidget *>(event->source());
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

void MyTreeWidget::startDrag(Qt::DropActions supportedActions)
{
	//Q_UNUSED(supportedActions);
	//QTreeWidgetItem *item = currentItem();
	//if (item == NULL)
	//	return;

	//QString pValue = QString::number(int((void*)item));
	//QByteArray itemData;
	//itemData = QVariant(pValue).toByteArray();

	//QMimeData *mimeData = new QMimeData;
	//mimeData->setData("application/x-qabstractitemmodeldatalist", itemData);

	//QDrag *drag = new QDrag(this);
	//drag->setMimeData(mimeData);

	////设置鼠标移动时，拖动的图片数据
	//QPixmap pPixmap("./Resources/icon/lishijilu1.png");
	//pPixmap = pPixmap.scaledToWidth(2);
	//drag->setPixmap(pPixmap);
	//drag->setHotSpot(QPoint(drag->pixmap().width() / 2, drag->pixmap().height() / 2));

	//if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
	//{
	//}

	//QMimeData *mimeData = new QMimeData;
	//mimeData->setText("fasfas");
	//QDrag *drag = new QDrag((QWidget*)(this));
	//drag->setMimeData(mimeData);
	//QPixmap pPixmap("./Resources/icon/lishijilu1.png");
	//pPixmap = pPixmap.scaledToWidth(2);
	//drag->setPixmap(pPixmap);
	//drag->exec(Qt::MoveAction);//注意这里一定要是MoveAction


	QTreeWidgetItem *item = currentItem();
	if (item == NULL|| item->parent()==nullptr)
		return;

	QString pValue = QString::number(int((void*)item));
	QByteArray itemData;
	itemData = QVariant(pValue).toByteArray();

	QMimeData *mimeData = new QMimeData;
	mimeData->setData("application/x-qabstractitemmodeldatalist", itemData);
	//
	//QDrag *drag = new QDrag(this);
	//mimeData->setText("KK");
	//drag->setMimeData(mimeData);
	//drag->setHotSpot(QPoint(drag->pixmap().width() / 2, drag->pixmap().height() / 2));
	//drag->setPixmap(QPixmap("./Resources/icon/putonganbaodengji1.png"));
	//
	//drag->setDragCursor(QPixmap("./Resources/icon/putonganbaodengji1.png"),Qt::CopyAction);
	//Qt::DropAction dropAction=drag->exec(Qt::MoveAction | Qt::CopyAction, Qt::LinkAction);

	QWidget* _te = new QWidget();
	_te->setFixedSize(40, 40);
	
	QLabel* _label = new QLabel(QStringLiteral("我七号放假"),_te);
	_label->setFixedSize(_te->width(), _te->height());
	QPixmap pixmap=_te->grab();
	//QPixmap pixmap = dragPiamap->grab();

	QDrag* drag = new QDrag(this);
	drag->setPixmap(pixmap);
	drag->setMimeData(mimeData);
	drag->setHotSpot(QPoint(0,0));

	Qt::DropAction dropAction=drag->exec(Qt::MoveAction);

	//QPixmap pPixmap("./Resources/icon/lishijilu1.png");
	//pPixmap = pPixmap.scaledToWidth(2);
	//drag->setPixmap(pPixmap);
	//drag->setHotSpot(QPoint(drag->pixmap().width() / 2, drag->pixmap().height() / 2));

	//hide();


	//qDebug() << "HH" << endl;
	//Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);

	//if (dropAction == Qt::MoveAction)
	//	close();
	//else
	//	show();

}

void MyTreeWidget::mouseMoveEvent(QMouseEvent * e)
{
	if (e->buttons() & Qt::LeftButton)
	{
		//int distance = (e->pos() - _startPos).manhattanLength();
		int distance = e->pos().manhattanLength();
		if (distance >= 0.01f)   //当拖动距离大于一个推荐抖动距离时，表示同意已经拖动操作了
			performDrag();
	}
	QTreeWidget::mouseMoveEvent(e);
}

void MyTreeWidget::performDrag()
{
	QTreeWidgetItem *item = currentItem();
	int column = currentColumn();
	if (item)  //必须是非顶层item才可以移动数据
// if(item)
	{
		QMimeData *mineData = new QMimeData;
		if (column != 4)   //只有第四列才可以移动数据
			return;
		mineData->setText(item->text(column));
		qDebug() << item->text(column);

		QDrag *drag = new QDrag(this);
		drag->setMimeData(mineData);
		drag->exec(Qt::MoveAction);
	}
}

//void MyTreeWidget::paintEvent(QPaintEvent * event)
//{
//
//}

//void MyTreeWidget::mouseMoveEvent(QMouseEvent * event)
//{
//	Q_D(MyTreeWidget);
//	QPoint topLeft;
//	QPoint bottomRight = event->pos();
//
//	if (state() == ExpandingState || state() == CollapsingState)
//		return;
//
//#if QT_CONFIG(draganddrop)
//	if (state() == DraggingState) {
//		topLeft = d->pressedPosition - d->offset();
//		if ((topLeft - bottomRight).manhattanLength() > QApplication::startDragDistance()) {
//			d->pressedIndex = QModelIndex();
//			startDrag(d->model->supportedDragActions());
//			setState(NoState); // the startDrag will return when the dnd operation is done
//			stopAutoScroll();
//		}
//		return;
//	}
//#endif // QT_CONFIG(draganddrop)
//
//	QPersistentModelIndex index = indexAt(bottomRight);
//	QModelIndex buddy = this->model->buddy(d->pressedIndex);
//	if ((state() == EditingState && d->hasEditor(buddy))
//		|| edit(index, NoEditTriggers, event))
//		return;
//
//	if (d->selectionMode != SingleSelection)
//		topLeft = d->pressedPosition - d->offset();
//	else
//		topLeft = bottomRight;
//
//	d->checkMouseMove(index);
//
//#if QT_CONFIG(draganddrop)
//	if (d->pressedIndex.isValid()
//		&& d->dragEnabled
//		&& (state() != DragSelectingState)
//		&& (event->buttons() != Qt::NoButton)
//		&& !d->selectedDraggableIndexes().isEmpty()) {
//		setState(DraggingState);
//		return;
//	}
//#endif
//
//	if ((event->buttons() & Qt::LeftButton) && d->selectionAllowed(index) && d->selectionModel) {
//		setState(DragSelectingState);
//		QItemSelectionModel::SelectionFlags command = selectionCommand(index, event);
//		if (d->ctrlDragSelectionFlag != QItemSelectionModel::NoUpdate && command.testFlag(QItemSelectionModel::Toggle)) {
//			command &= ~QItemSelectionModel::Toggle;
//			command |= d->ctrlDragSelectionFlag;
//		}
//
//		// Do the normalize ourselves, since QRect::normalized() is flawed
//		QRect selectionRect = QRect(topLeft, bottomRight);
//		setSelection(selectionRect, command);
//
//		// set at the end because it might scroll the view
//		if (index.isValid()
//			&& (index != d->selectionModel->currentIndex())
//			&& d->isIndexEnabled(index))
//			d->selectionModel->setCurrentIndex(index, QItemSelectionModel::NoUpdate);
//	}
//}

void MyTreeWidget::init()
{
	this->setColumnCount(1);
	//this->setHeaderHidden(true);
	setDragEnabled(true);
	this->setDefaultDropAction(Qt::MoveAction);
	//setAcceptDrops(true);
	//this->setDropIndicatorShown(true);
	setDragDropMode(QAbstractItemView::InternalMove);
	createTreeWidget();
}

void MyTreeWidget::createTreeWidget()
{
	MyQItemDelegate* _tt = new MyQItemDelegate(this);
	this->setItemDelegate(_tt);

	QTreeWidgetItem* _parentItem = new QTreeWidgetItem(this,QStringList(QString("test")));
	_parentItem->setFlags(Qt::ItemIsEnabled);
	//_parentItem->setData(0,Qt::UserRole+1,"chosen one");

	//_parentItem->setData();
	int _width= this->width() - 40;
	char str[80];
	sprintf(str,"QTreeView::item{margin-right:%dpx;height:40px;background:#00FFFF;}",80);
	//QString str = "QTreeView::item{margin-right:80px;height:40px;background:#00FFFF;}";
	this->setStyleSheet(str);
	for (int i=1;i<4;i++)
	{
		//QString _ii = QString::number(i);
		//QWidget* _btn = new QWidget(this);
		//_btn->setFixedSize(60,60);
		//_btn->setStyleSheet("border-image: url(./Resources/icon/lishijilu1.png); ");
		//QTreeWidgetItem* _subItem = new QTreeWidgetItem(_parentItem,QStringList(QString("11")));
		//_subItem->setText(0,"KK"+_ii);
		//
		//QPushButton* _btn = new QPushButton(this);
		//_btn->setText("HH"+QString::number(i));
		//setItemWidget(_subItem,0, _btn);
		//QIcon icon = QIcon("./Resources/icon/lishijilu1.png");
		//_subItem->setIcon(0,icon);
		//setIconSize(QSize(55, 24));
		//_parentItem->addChild(_subItem);

		//MyQItemDelegate* _tt01 = new MyQItemDelegate(this);
		//this->setItemDelegateForRow(i, _tt01);

		QTreeWidgetItem* _subItem = new QTreeWidgetItem(_parentItem, QStringList(QString(QString::number(i))));
		//QTreeWidgetItem* _subItem01 = new QTreeWidgetItem(_subItem, QStringList(QString(QString::number(i+i*4))));
		//_subItem->addChild(_subItem01);
		_subItem->setTextAlignment(0,Qt::AlignCenter);
		//QLabel* _widget = new QLabel(this);
		//_widget->setText("HelloWorld");
		//_widget->setStyleSheet("border:1px solid yellow");
		//setItemWidget(_subItem, 0, _widget);
		//_widget->setFixedSize(40, 40);
		_parentItem->addChild(_subItem);
		//_subItem->setData(0, Qt::UserRole+1, "chosen one");

	}


	this->expandAll();
}

MyQItemDelegate::~MyQItemDelegate()
{

}

QWidget * MyQItemDelegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	// step:1 根据不同的列，创建需要的控件，不支持的直接返回空
	if (index.column() == 1 || index.column() == 2)
	{
		QSpinBox *spinBox = new QSpinBox(parent);
		spinBox->setRange(0, 255);
		return spinBox;
	}
	else if (index.column() == 3 || index.column() == 4)
	{
		QDoubleSpinBox *dSpinBox = new QDoubleSpinBox(parent);
		dSpinBox->setRange(0, 100);
		dSpinBox->setSingleStep(1.00);
		return dSpinBox;
	}
	return nullptr;
}

void MyQItemDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	QStyleOptionViewItem viewOption(option);
	initStyleOption(&viewOption, index);
	if (index.parent().model() != nullptr)
	{
		QStyledItemDelegate::paint(painter, viewOption, index);
	}
	else
	{
		auto text = index.data().toString();
		auto myOpt = option;
		myOpt.displayAlignment = (Qt::AlignLeft|Qt::AlignVCenter);
		auto sWidth = myOpt.fontMetrics.width(text);
		auto sHeight = myOpt.fontMetrics.height();
		// 计算文字所在的范围，因为是居中对齐，所以需要计算相应的起始位置
		auto sRect = QRectF(myOpt.rect.x() + (myOpt.rect.width() - sWidth) / 2.0,
			myOpt.rect.y() + ((myOpt.rect.height() - sHeight) / 2.0), sWidth, sHeight);

		// 将渐变填充的范围设置成文字所在的范围
		//QLinearGradient l(sRect.x(), sRect.y(), sRect.x() + sRect.width(),
		//	sRect.y() + sRect.height());

		// 设置彩虹色渐变效果，彩虹由赤橙黄绿青蓝紫的颜色组成
		// 因此我们除去起始点为红色，每隔1/6就设置一种颜色
		//l.setColorAt(0, Qt::red);
		//l.setColorAt(1.0 / 6, QColor(255, 97, 0));
		//l.setColorAt(2.0 / 6, QColor(255, 255, 0));
		//l.setColorAt(3.0 / 6, Qt::green);
		//l.setColorAt(4.0 / 6, Qt::cyan);
		//l.setColorAt(5.0 / 6, Qt::blue);
		//l.setColorAt(1, QColor(255, 0, 255));

		// 这里并不使用painter，只需要QStyle即可实现效果
		// QPalette::Text为文本显示效果的role
		auto role = QPalette::Text;
		if (option.state & QStyle::State_Selected) {
			// 当前item被选中时绘制高亮的选中框
			role = QPalette::HighlightedText;
			painter->fillRect(option.rect, option.palette.highlight());
		}
		else
		{
			painter->fillRect(option.rect, QBrush(QColor(47, 79, 79)));
		}
		myOpt.palette.setBrush(role, QBrush(Qt::black));
		//myOpt.palette.setBrush(QPalette::Background, QBrush(QColor(47, 79, 79)));

		// 注意最后一个参数role，只有设置了它才能让QStyle正确地绘制自定义的文本显示效果
		QApplication::style()->drawItemText(painter, myOpt.rect, myOpt.displayAlignment,
			myOpt.palette, true, text, role);
	}
}

void MyQItemDelegate::setEditorData(QWidget * editor, const QModelIndex & index) const
{
	// step:2 给控件设置值
	if (index.column() == 1 || index.column() == 2)
	{
		QSpinBox *spinBox = dynamic_cast<QSpinBox *>(editor);
		if (spinBox)
		{
			int value = index.data().toString().toInt();
			spinBox->setValue(value);
		}
	}
	else if (index.column() == 3 || index.column() == 4)
	{
		QDoubleSpinBox *dSpinBox = dynamic_cast<QDoubleSpinBox *>(editor);
		if (dSpinBox)
		{
			double value = index.data().toString().toDouble();
			dSpinBox->setValue(value);
		}
	}
}

void MyQItemDelegate::setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const
{
	// step：3编辑完成，设置值给Mode层
	if (index.column() == 1 || index.column() == 2)
	{
		QSpinBox *spinBox = dynamic_cast<QSpinBox *>(editor);
		if (spinBox)
		{
			int value = spinBox->value();
			model->setData(index, value, Qt::DisplayRole);
		}
	}
	else if (index.column() == 3 || index.column() == 4)
	{
		QDoubleSpinBox *dSpinBox = dynamic_cast<QDoubleSpinBox *>(editor);
		if (dSpinBox)
		{
			double value = dSpinBox->value();
			model->setData(index, QString::number(value, 'f', 2), Qt::DisplayRole);
		}
	}
}

void MyQItemDelegate::updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	editor->setGeometry(option.rect);
}

