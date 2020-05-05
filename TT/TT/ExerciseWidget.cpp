#include "ExerciseWidget.h"
#include <qevent.h>
#include <QMimeData>
#include <qpainter.h>
#include <QDebug>
#include <qjsonarray.h>
#include <qjsonobject.h>
#include <qjsondocument.h>
#include <qfile.h>
#include <qdir.h>

bool ExerciseWidget::drawingLine = false;

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
	//QString str="woqihaofangjia";
	//m_pCustomDragLabel = new CustomDragLabel(Two, this);

	////connect(m_pCustomDragLabel, SIGNAL(wantToGetPoint()), this, SLOT(receiverSIGNAL()));
	////connect(this, SIGNAL(sendPoint(QPoint)), m_pCustomDragLabel, SLOT(receiverData(QPoint)));
	connect(ui.saveBtn,&QPushButton::clicked,this,&ExerciseWidget::saveDataToLocal);
	connect(ui.readBtn,&QPushButton::clicked,this,&ExerciseWidget::readDataFromLocal);

}

ExerciseWidget::~ExerciseWidget()
{
}

void ExerciseWidget::init()
{

}

void ExerciseWidget::insertNode(QWidget* lastNode, QWidget* nextNode)
{
	if (!m_lineNodesMap.contains(lastNode))
	{
		m_lineNodesMap.insert(lastNode, nextNode);
	}
	else
	{
		changeNode(lastNode,nextNode);
	}

}

void ExerciseWidget::deleteNode(QWidget * headNode)
{
	if (m_lineNodesMap.contains(headNode))
	{
		m_lineNodesMap.remove(headNode);
	}

}

void ExerciseWidget::changeNode(QWidget * lastNode, QWidget * nextNode)
{
	m_lineNodesMap[lastNode] = nextNode;
}

void ExerciseWidget::reveicePos(QPoint mousePoint)
{
	m_mousePos= mousePoint;
	update();
}

void ExerciseWidget::reveiceFirstNode(QWidget * widget)
{
	m_selectPointPress = true;
	QPoint _tmpPoint = widget->parentWidget()->mapToGlobal(widget->pos());
	QPoint curPosGlobal = this->mapFromGlobal(_tmpPoint);
	m_initPos = curPosGlobal + QPoint(widget->width() / 2, widget->height() / 2);
	m_firstNode = widget;

	if (m_lineNodesMap.contains(widget))
	{
		m_lineNodesMap.remove(widget);
	}

	for (QMap<QWidget*, QWidget*>::iterator it=m_lineNodesMap.begin();it!=m_lineNodesMap.end();it++)
	{
		if(it.value() == widget)
		{
			m_lineNodesMap.erase(it);
			break;
		}
	}

	viewport()->update();
}

void ExerciseWidget::reveiceSecondNode(QWidget * widget)
{
	if (m_firstNode == nullptr)return;
	if (m_lineNodesMap.contains(m_firstNode))
	{
		m_lineNodesMap[m_firstNode] = widget;
	}
	else
	{
		m_lineNodesMap.insert(m_firstNode,widget);
	}
	m_selectPointPress = false;
	m_firstNode = nullptr;
	m_secondNode = nullptr;
	viewport()->update();
}

void ExerciseWidget::reveiceReleaseSig()
{
	m_selectPointPress = false;
	m_firstNode = nullptr;
	m_secondNode = nullptr;
	viewport()->update();
}

void ExerciseWidget::saveDataToLocal()
{
	QJsonObject rootjson;

	QJsonArray arraysRoot;
	for (int i=0;i< m_curSceneWidgetList.count();i++)
	{
		QJsonObject _kindJson;//
		CustomDragLabel* _tempDragLabel = m_curSceneWidgetList[i];
		TypeKinds _type = _tempDragLabel->typeKind();
		_kindJson.insert("type",(int)_type);

		//QPoint
		QJsonObject _pointJson;
		int _x = _tempDragLabel->x();
		int _y = _tempDragLabel->y();
		_pointJson.insert("x", _x);
		_pointJson.insert("y", _y);
		_kindJson.insert("point",_pointJson);

		//子节点地址
		QList<NodeWidget*> _listNode = m_curSceneWidgetList[i]->getChildNode();
		QJsonArray _nodeArray;
		for (int i=0;i<_listNode.count();i++)
		{
			NodeWidget* _tempNodeWidget=_listNode[i];
			int* _value = (int*)(_tempNodeWidget);
			char ch[20];
			sprintf(ch, "%p", _value);
			std::string _valueStr(ch,ch+strlen(ch));
			_nodeArray.insert(i, QString::fromStdString(_valueStr));
		}
		_kindJson.insert("childNode",_nodeArray);

		arraysRoot.insert(i,_kindJson);
	}
	rootjson.insert("data", arraysRoot);

	//线条数据
	QJsonArray chilidrenRootNode;
	QMap<QWidget*, QWidget*>::iterator _it;
	int i = 0;
	for (_it=m_lineNodesMap.begin(),i=0;_it!=m_lineNodesMap.end();_it++,i++)
	{
		QJsonObject childJson;
		int* _keyVal = (int*)_it.key();
		char ch[20];
		sprintf(ch, "%p", _keyVal);
		std::string _keyStr(ch, ch + strlen(ch));
		childJson.insert("key",QString::fromStdString(_keyStr));

		int* _valueVal = (int*)_it.value();
		memset(ch, '\0',strlen(ch));
		sprintf(ch, "%p", _valueVal);
		std::string _valueStr(ch, ch + strlen(ch));
		childJson.insert("value", QString::fromStdString(_valueStr));
		chilidrenRootNode.insert(i,childJson);
	}
	if (m_lineNodesMap.count()>0)
	{
		rootjson.insert("line", chilidrenRootNode);
	}


	QJsonDocument _jsonDocument;
	_jsonDocument.setObject(rootjson);

	QFile file(QDir::currentPath() + "/Resources/1.json");
	if (!file.open(QIODevice::WriteOnly)) {
		qDebug() << "File open error";
	}
	else {
		qDebug() << "File open!";
	}
	file.write(_jsonDocument.toJson());
	file.close();

	//QByteArray complex_byte_array = _jsonDocument.toJson(QJsonDocument::Compact);
	//QString complex_json_str(complex_byte_array);
	//qDebug() << "complex_json_str:" << complex_json_str;
}

void ExerciseWidget::readDataFromLocal()
{
	QFile loadFile(QDir::currentPath() + "/Resources/1.json");
	if (!loadFile.open(QIODevice::ReadOnly))
	{
		return;
	}
	QByteArray _alldata = loadFile.readAll();
	loadFile.close();

	QJsonParseError jsonError;
	QJsonDocument jsonDoc(QJsonDocument::fromJson(_alldata,&jsonError));
	if (jsonError.error=QJsonParseError::NoError)
	{
		return;
	}

	QJsonObject rootObj = jsonDoc.object();
	QJsonArray arraysRoot = rootObj.value("data").toArray();
	for (int i=0;i<arraysRoot.count();i++)
	{
		QJsonObject _widgetJosn = arraysRoot.at(i).toObject();
		TypeKinds _type = (TypeKinds)_widgetJosn.value("type").toInt();
		
		QJsonObject _pointjson= _widgetJosn.value("point").toObject();
		int x = _pointjson.value("x").toInt();
		int y = _pointjson.value("y").toInt();
		QPoint _point(x,y);

		CustomDragLabel* _customDragLabel = new CustomDragLabel(_type,this);
		

		m_curSceneWidgetList.push_back(_customDragLabel);
		_customDragLabel->setStyleSheet("margin: 20px 20px 20px 20px;border:2px solid black;background-color: rgb(255,255,255);color: rgb(0,0,0);");
		_customDragLabel->move(_point);
		_customDragLabel->setAutoFillBackground(true);
		//ui->verticalLayout->addWidget(label);


		QJsonArray _childrenNode = _widgetJosn.value("childNode").toArray();

		QList<NodeWidget*> _tempList=_customDragLabel->getChildNode();
		for (int i=0;i<_tempList.count();i++)
		{
			QString _address=_childrenNode.at(i).toString();
			m_loadLocalChildNodeData.insert(_address,_tempList[i]);
		}
		_customDragLabel->show();
	}

	//保存线条
	QJsonArray lineRoot = rootObj.value("line").toArray();
	for (int i=0;i<lineRoot.count();i++)
	{
		QJsonObject _lineJson = lineRoot.at(i).toObject();
		QString _key = _lineJson.value("key").toString();
		QString _value = _lineJson.value("value").toString();
		if (m_loadLocalChildNodeData.contains(_key)&&m_loadLocalChildNodeData.contains(_value))
		{
			QWidget* _keyWid = m_loadLocalChildNodeData[_key];
			QWidget* _valWid = m_loadLocalChildNodeData[_value];

			m_lineNodesMap.insert(_keyWid, _valWid);
		}
	}
	viewport()->update();
}

void ExerciseWidget::reveiceWidget(bool state, QWidget* widget)
{
	m_selectPointPress = state;
	if (state)
	{
		QPoint _tmpPoint = widget->parentWidget()->mapToGlobal(widget->pos());
		QPoint curPosGlobal = this->mapFromGlobal(_tmpPoint);
		m_initPos = curPosGlobal+QPoint(widget->width()/2,widget->height()/2);
	}
	qDebug() << "state:" << state;
	//update();
	viewport()->update();
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

		//QString strr;
		//QByteArray strList;
		//for (int i = 0; i < data.size(); i++)
		//{
		//	if (data[i] != '\0')
		//	{
		//		strList.push_back(data[i]);
		//	}
		//}
		//strr = strList;
		//strr = QString::fromLocal8Bit(strr.toStdString().data());

		QDataStream _dataStream(&data,QIODevice::ReadOnly);
		QString _strr;
		int _kind;
		_dataStream >> _strr>>_kind;

		// 创建自定义Label
		CustomDragLabel *label = new CustomDragLabel((TypeKinds)_kind, this);
		m_curSceneWidgetList.push_back(label);
		label->setStyleSheet("margin: 20px 20px 20px 20px;border:2px solid black;background-color: rgb(255,255,255);color: rgb(0,0,0);");
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

void ExerciseWidget::paintEvent(QPaintEvent * event)
{
	QTreeWidget::paintEvent(event);
	QPainter _painter(viewport());

	QPen _pen(Qt::red);
	_pen.setWidth(3);
	_painter.setPen(_pen);
	if (m_selectPointPress)
	{
		_painter.drawLine(m_initPos, m_mousePos);
	}

	QMap<QWidget*, QWidget*>::iterator _it;
	for (_it=m_lineNodesMap.begin();_it!=m_lineNodesMap.end();_it++)
	{
		QPoint _keyPoint = _it.key()->parentWidget()->mapToGlobal(_it.key()->pos());
		QPoint _keyPosGlobal = this->mapFromGlobal(_keyPoint);
		QPoint _startPos = _keyPosGlobal + QPoint(_it.key()->width() / 2, _it.key()->height() / 2);

		QPoint _valPoint = _it.value()->parentWidget()->mapToGlobal(_it.value()->pos());
		QPoint _valPosGlobal = this->mapFromGlobal(_valPoint);
		QPoint _endPos = _valPosGlobal + QPoint(_it.value()->width() / 2, _it.value()->height() / 2);

		_painter.drawLine(_startPos, _endPos);
	}
	_painter.setRenderHint(QPainter::Antialiasing,true);
	viewport()->update();
}

bool ExerciseWidget::viewportEvent(QEvent * event)
{
	QTreeWidget::viewportEvent(event);
	return false;
}
