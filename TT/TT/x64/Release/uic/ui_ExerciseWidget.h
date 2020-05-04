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
#include <QtWidgets/QTreeWidget>
#include "mytreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_ExerciseWidget
{
public:
    MyTreeWidget *treeWidget;
    QTreeWidget *treeWidget_2;

    void setupUi(QTreeWidget *ExerciseWidget)
    {
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(ExerciseWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(ExerciseWidget);
        new QTreeWidgetItem(ExerciseWidget);
        new QTreeWidgetItem(ExerciseWidget);
        new QTreeWidgetItem(ExerciseWidget);
        if (ExerciseWidget->objectName().isEmpty())
            ExerciseWidget->setObjectName(QString::fromUtf8("ExerciseWidget"));
        ExerciseWidget->resize(732, 596);
        ExerciseWidget->setAutoScroll(true);
        ExerciseWidget->setTabKeyNavigation(true);
        ExerciseWidget->setDragEnabled(true);
        ExerciseWidget->setDragDropOverwriteMode(true);
        ExerciseWidget->setDragDropMode(QAbstractItemView::DropOnly);
        ExerciseWidget->setDefaultDropAction(Qt::CopyAction);
        ExerciseWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        ExerciseWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        treeWidget = new MyTreeWidget(ExerciseWidget);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem2);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(30, 190, 221, 371));
        treeWidget_2 = new QTreeWidget(ExerciseWidget);
        new QTreeWidgetItem(treeWidget_2);
        new QTreeWidgetItem(treeWidget_2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget_2);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(treeWidget_2);
        new QTreeWidgetItem(__qtreewidgetitem4);
        treeWidget_2->setObjectName(QString::fromUtf8("treeWidget_2"));
        treeWidget_2->setGeometry(QRect(330, 180, 256, 192));
        treeWidget_2->setTabKeyNavigation(true);
        treeWidget_2->setDragEnabled(true);
        treeWidget_2->setDragDropOverwriteMode(true);
        treeWidget_2->setDragDropMode(QAbstractItemView::DragDrop);
        treeWidget_2->setDefaultDropAction(Qt::MoveAction);
        treeWidget_2->setUniformRowHeights(true);
        treeWidget_2->setSortingEnabled(true);
        treeWidget_2->setAnimated(true);
        treeWidget_2->setAllColumnsShowFocus(true);
        treeWidget_2->setWordWrap(true);
        treeWidget_2->setHeaderHidden(true);
        if (ExerciseWidget->header()->objectName().isEmpty())

        retranslateUi(ExerciseWidget);

        QMetaObject::connectSlotsByName(ExerciseWidget);
    } // setupUi

    void retranslateUi(QTreeWidget *ExerciseWidget)
    {
        QTreeWidgetItem *___qtreewidgetitem = ExerciseWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("ExerciseWidget", "1", nullptr));

        const bool __sortingEnabled = ExerciseWidget->isSortingEnabled();
        ExerciseWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = ExerciseWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("ExerciseWidget", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("ExerciseWidget", "\346\226\260\345\273\272\345\255\220\351\241\271\347\233\256", nullptr));
        ExerciseWidget->setSortingEnabled(__sortingEnabled);

        ExerciseWidget->setWindowTitle(QApplication::translate("ExerciseWidget", "ExerciseWidget", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget_2->headerItem();
        ___qtreewidgetitem3->setText(0, QApplication::translate("ExerciseWidget", "1", nullptr));

        const bool __sortingEnabled1 = treeWidget_2->isSortingEnabled();
        treeWidget_2->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget_2->topLevelItem(0);
        ___qtreewidgetitem4->setText(0, QApplication::translate("ExerciseWidget", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget_2->topLevelItem(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("ExerciseWidget", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = treeWidget_2->topLevelItem(2);
        ___qtreewidgetitem6->setText(0, QApplication::translate("ExerciseWidget", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = treeWidget_2->topLevelItem(3);
        ___qtreewidgetitem7->setText(0, QApplication::translate("ExerciseWidget", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        treeWidget_2->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class ExerciseWidget: public Ui_ExerciseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXERCISEWIDGET_H
