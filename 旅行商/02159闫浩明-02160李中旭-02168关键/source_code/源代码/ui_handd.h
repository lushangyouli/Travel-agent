/********************************************************************************
** Form generated from reading UI file 'handd.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDD_H
#define UI_HANDD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HandD
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *HandD)
    {
        if (HandD->objectName().isEmpty())
            HandD->setObjectName(QStringLiteral("HandD"));
        HandD->resize(726, 414);
        HandD->setStyleSheet(QStringLiteral("#HandD{border-image: url(:/new/prefix2/background1.jpg);}"));
        label = new QLabel(HandD);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 160, 311, 71));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix3/1555744701_786454.png);"));
        pushButton = new QPushButton(HandD);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 370, 131, 32));
        pushButton->setStyleSheet(QStringLiteral(""));

        retranslateUi(HandD);

        QMetaObject::connectSlotsByName(HandD);
    } // setupUi

    void retranslateUi(QWidget *HandD)
    {
        HandD->setWindowTitle(QApplication::translate("HandD", "Form", nullptr));
        label->setText(QString());
        pushButton->setText(QApplication::translate("HandD", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HandD: public Ui_HandD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDD_H
