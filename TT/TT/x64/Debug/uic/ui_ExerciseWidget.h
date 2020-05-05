/********************************************************************************
** Form generated from reading UI file 'ExerciseWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXERCISEWIDGET_H
#define UI_EXERCISEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include "mytreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_ExerciseWidget
{
public:
    MyTreeWidget *treeWidget;
    QPushButton *readBtn;
    QPushButton *saveBtn;

    void setupUi(QTreeWidget *ExerciseWidget)
    {
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        ExerciseWidget->setHeaderItem(__qtreewidgetitem);
        if (ExerciseWidget->objectName().isEmpty())
            ExerciseWidget->setObjectName(QString::fromUtf8("ExerciseWidget"));
        ExerciseWidget->resize(836, 646);
        ExerciseWidget->setAutoScroll(true);
        ExerciseWidget->setTabKeyNavigation(true);
        ExerciseWidget->setDragEnabled(true);
        ExerciseWidget->setDragDropOverwriteMode(true);
        ExerciseWidget->setDragDropMode(QAbstractItemView::DropOnly);
        ExerciseWidget->setDefaultDropAction(Qt::CopyAction);
        ExerciseWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        ExerciseWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        treeWidget = new MyTreeWidget(ExerciseWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(0, 0, 191, 441));
        readBtn = new QPushButton(ExerciseWidget);
        readBtn->setObjectName(QString::fromUtf8("readBtn"));
        readBtn->setGeometry(QRect(730, 60, 75, 23));
        saveBtn = new QPushButton(ExerciseWidget);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        saveBtn->setGeometry(QRect(730, 20, 75, 23));
        if (ExerciseWidget->header()->objectName().isEmpty())

        retranslateUi(ExerciseWidget);

        QMetaObject::connectSlotsByName(ExerciseWidget);
    } // setupUi

    void retranslateUi(QTreeWidget *ExerciseWidget)
    {
        ExerciseWidget->setWindowTitle(QApplication::translate("ExerciseWidget", "ExerciseWidget", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("ExerciseWidget", "1", nullptr));
        readBtn->setText(QApplication::translate("ExerciseWidget", "read", nullptr));
        saveBtn->setText(QApplication::translate("ExerciseWidget", "save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExerciseWidget: public Ui_ExerciseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXERCISEWIDGET_H
