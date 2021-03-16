/********************************************************************************
** Form generated from reading UI file 'regist.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIST_H
#define UI_REGIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_regist
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *regist)
    {
        if (regist->objectName().isEmpty())
            regist->setObjectName(QStringLiteral("regist"));
        regist->resize(1026, 709);
        regist->setStyleSheet(QStringLiteral("#regist{border-image: url(:/new/prefix2/login.jpg);}"));
        centralwidget = new QWidget(regist);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(430, 310, 114, 32));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 370, 114, 32));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 140, 59, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 200, 59, 16));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(420, 140, 151, 21));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(420, 200, 151, 21));
        regist->setCentralWidget(centralwidget);
        menubar = new QMenuBar(regist);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1026, 22));
        regist->setMenuBar(menubar);
        statusbar = new QStatusBar(regist);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        regist->setStatusBar(statusbar);

        retranslateUi(regist);

        QMetaObject::connectSlotsByName(regist);
    } // setupUi

    void retranslateUi(QMainWindow *regist)
    {
        regist->setWindowTitle(QApplication::translate("regist", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("regist", "\346\263\250\345\206\214", nullptr));
        pushButton_2->setText(QApplication::translate("regist", "\350\277\224\345\233\236", nullptr));
        label->setText(QApplication::translate("regist", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QApplication::translate("regist", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class regist: public Ui_regist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIST_H
