#pragma once

#include <QTreeWidget>
#include <QItemDelegate>
#include <qstyleditemdelegate.h>
#include <QWidget>
#include <QStyleOptionViewItem>

class MyTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	MyTreeWidget(QWidget *parent);
	~MyTreeWidget();

protected:
	//void mousePressEvent(QMouseEvent *e);
	void dragEnterEvent(QDragEnterEvent *e);
	void dragMoveEvent(QDragMoveEvent *e);
	void dropEvent(QDropEvent *e);
	void startDrag(Qt::DropActions /*supportedActions*/);
	void mouseMoveEvent(QMouseEvent *event);
	void performDrag();

	//void  paintEvent(QPaintEvent *event) final;

private:
	void init();
	void createTreeWidget();

	QPoint m_nPos;

	friend class ::tst_QAbstractItemView;
	friend class ::tst_QTreeView;
	friend class QTreeViewPrivate; // needed to compile with MSVC
	friend class QListModeViewBase;
	friend class QListViewPrivate;
	friend class QAbstractSlider;
};

class MyQItemDelegate :public QStyledItemDelegate
{
public:
	MyQItemDelegate(QObject *parent = nullptr):QStyledItemDelegate(parent) { };
	~MyQItemDelegate();

protected:
	virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	virtual void setEditorData(QWidget *editor, const QModelIndex &index) const;
	virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
	virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
