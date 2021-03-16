/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(1016, 649);
        login->setStyleSheet(QStringLiteral("#login{border-image: url(:/new/prefix2/background2.jpg);}"));
        centralwidget = new QWidget(login);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(440, 460, 114, 32));
        pushButton->setStyleSheet(QLatin1String("border-image:none;\n"
"font: 13pt \".SF NS Text\";"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(440, 510, 114, 32));
        pushButton_2->setStyleSheet(QLatin1String("border-image:none;\n"
"font: 13pt \".SF NS Text\";"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 360, 71, 21));
        label->setStyleSheet(QLatin1String("border-image:none;\n"
"font: 13pt \".SF NS Text\";"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(370, 400, 59, 16));
        label_2->setStyleSheet(QLatin1String("border-image:none;\n"
"font: 13pt \".SF NS Text\";"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(430, 360, 141, 21));
        lineEdit->setStyleSheet(QLatin1String("border-image:none;\n"
"font: 13pt \".SF NS Text\";"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(430, 400, 141, 21));
        lineEdit_2->setStyleSheet(QStringLiteral("border-image:none;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 90, 1091, 231));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix3/1555738757_806196.png);"));
        login->setCentralWidget(centralwidget);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QApplication::translate("login", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        pushButton_2->setText(QApplication::translate("login", "\346\263\250\345\206\214", nullptr));
        label->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\257\206\347\240\201</span></p></body></html>", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
