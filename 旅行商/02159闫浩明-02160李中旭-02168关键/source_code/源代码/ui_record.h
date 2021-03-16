/********************************************************************************
** Form generated from reading UI file 'record.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORD_H
#define UI_RECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_record
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *record)
    {
        if (record->objectName().isEmpty())
            record->setObjectName(QStringLiteral("record"));
        record->resize(1026, 709);
        record->setStyleSheet(QStringLiteral("#record{border-image: url(:/new/prefix2/record.jpg);}"));
        centralwidget = new QWidget(record);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(150, 290, 711, 192));
        tableView->setStyleSheet(QStringLiteral("border-image:none;"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(430, 220, 114, 32));
        pushButton->setStyleSheet(QStringLiteral("border-image:none;"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(440, 530, 114, 32));
        pushButton_2->setStyleSheet(QStringLiteral("border-image:none;"));
        record->setCentralWidget(centralwidget);
        pushButton->raise();
        pushButton_2->raise();
        tableView->raise();

        retranslateUi(record);

        QMetaObject::connectSlotsByName(record);
    } // setupUi

    void retranslateUi(QMainWindow *record)
    {
        record->setWindowTitle(QApplication::translate("record", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("record", "\346\237\245\347\234\213\350\256\260\345\275\225", nullptr));
        pushButton_2->setText(QApplication::translate("record", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class record: public Ui_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
