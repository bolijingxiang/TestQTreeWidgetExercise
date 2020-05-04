/********************************************************************************
** Form generated from reading UI file 'TT.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TT_H
#define UI_TT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "CTreeWidget.h"
#include "testtreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_TTClass
{
public:
    TestTreeWidget *treeWidget;
    CTreeWidget *treeWidget_2;

    void setupUi(QWidget *TTClass)
    {
        if (TTClass->objectName().isEmpty())
            TTClass->setObjectName(QString::fromUtf8("TTClass"));
        TTClass->resize(833, 619);
        treeWidget = new TestTreeWidget(TTClass);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(420, 130, 411, 441));
        treeWidget_2 = new CTreeWidget(TTClass);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        treeWidget_2->setHeaderItem(__qtreewidgetitem1);
        treeWidget_2->setObjectName(QString::fromUtf8("treeWidget_2"));
        treeWidget_2->setGeometry(QRect(40, 70, 321, 251));

        retranslateUi(TTClass);

        QMetaObject::connectSlotsByName(TTClass);
    } // setupUi

    void retranslateUi(QWidget *TTClass)
    {
        TTClass->setWindowTitle(QApplication::translate("TTClass", "TT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TTClass: public Ui_TTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TT_H
