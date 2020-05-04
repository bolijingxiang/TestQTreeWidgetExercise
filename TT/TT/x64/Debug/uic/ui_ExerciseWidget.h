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
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        ExerciseWidget->setHeaderItem(__qtreewidgetitem);
        if (ExerciseWidget->objectName().isEmpty())
            ExerciseWidget->setObjectName(QString::fromUtf8("ExerciseWidget"));
        ExerciseWidget->resize(742, 596);
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
        treeWidget->setGeometry(QRect(140, 110, 191, 441));
        treeWidget_2 = new QTreeWidget(ExerciseWidget);
        new QTreeWidgetItem(treeWidget_2);
        new QTreeWidgetItem(treeWidget_2);
        new QTreeWidgetItem(treeWidget_2);
        new QTreeWidgetItem(treeWidget_2);
        new QTreeWidgetItem(treeWidget_2);
        new QTreeWidgetItem(treeWidget_2);
        new QTreeWidgetItem(treeWidget_2);
        new QTreeWidgetItem(treeWidget_2);
        treeWidget_2->setObjectName(QString::fromUtf8("treeWidget_2"));
        treeWidget_2->setGeometry(QRect(430, 320, 256, 192));
        if (ExerciseWidget->header()->objectName().isEmpty())

        retranslateUi(ExerciseWidget);

        QMetaObject::connectSlotsByName(ExerciseWidget);
    } // setupUi

    void retranslateUi(QTreeWidget *ExerciseWidget)
    {
        ExerciseWidget->setWindowTitle(QApplication::translate("ExerciseWidget", "ExerciseWidget", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("ExerciseWidget", "1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget_2->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("ExerciseWidget", "1", nullptr));

        const bool __sortingEnabled = treeWidget_2->isSortingEnabled();
        treeWidget_2->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget_2->topLevelItem(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("ExerciseWidget", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget_2->topLevelItem(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("ExerciseWidget", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget_2->topLevelItem(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("ExerciseWidget", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget_2->topLevelItem(3);
        ___qtreewidgetitem5->setText(0, QApplication::translate("ExerciseWidget", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = treeWidget_2->topLevelItem(4);
        ___qtreewidgetitem6->setText(0, QApplication::translate("ExerciseWidget", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = treeWidget_2->topLevelItem(5);
        ___qtreewidgetitem7->setText(0, QApplication::translate("ExerciseWidget", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget_2->topLevelItem(6);
        ___qtreewidgetitem8->setText(0, QApplication::translate("ExerciseWidget", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem9 = treeWidget_2->topLevelItem(7);
        ___qtreewidgetitem9->setText(0, QApplication::translate("ExerciseWidget", "11", nullptr));
        treeWidget_2->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class ExerciseWidget: public Ui_ExerciseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXERCISEWIDGET_H
