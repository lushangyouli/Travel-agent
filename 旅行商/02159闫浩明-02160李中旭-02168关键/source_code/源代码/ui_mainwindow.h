/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLCDNumber *lcdNumber;
    QLabel *label_4;
    QLCDNumber *lcdNumber_2;
    QLabel *label_6;
    QLCDNumber *lcdNumber_3;
    QLabel *label_7;
    QPushButton *pushButton_4;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1016, 649);
        MainWindow->setStyleSheet(QStringLiteral("#MainWindow{border-image: url(:/new/prefix2/background2.jpg);}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 260, 121, 121));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix3/IMG_1661.PNG);"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 200, 261, 241));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix3/IMG_1662.PNG);"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(670, 220, 251, 201));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix3/IMG_1664.PNG);"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(410, 430, 381, 71));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix3/1555739344_414852.png);"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(730, 430, 301, 71));
        pushButton_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix3/1555739303_415953.png);"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(50, 420, 351, 71));
        pushButton_3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix3/1555739331_954795.png);"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(600, 50, 61, 23));
        lcdNumber->setStyleSheet(QLatin1String("border-image:none;\n"
"\n"
""));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(670, 50, 59, 16));
        label_4->setStyleSheet(QLatin1String("border-image:none;\n"
"font: 13pt \".SF NS Text\";"));
        lcdNumber_2 = new QLCDNumber(centralWidget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(700, 50, 64, 23));
        lcdNumber_2->setStyleSheet(QStringLiteral("border-image:none;"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(780, 50, 59, 16));
        label_6->setStyleSheet(QStringLiteral("border-image:none;"));
        lcdNumber_3 = new QLCDNumber(centralWidget);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(820, 50, 64, 23));
        lcdNumber_3->setStyleSheet(QStringLiteral("border-image:none;"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(900, 50, 59, 16));
        label_7->setStyleSheet(QStringLiteral("border-image:none;"));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(420, 540, 114, 32));
        pushButton_4->setStyleSheet(QStringLiteral("border-image:none;"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(660, 100, 141, 61));
        label_8->setStyleSheet(QLatin1String("border-image:none;\n"
""));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(820, 100, 171, 61));
        label_9->setStyleSheet(QLatin1String("border-image:none;\n"
""));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\244\251</span></p></body></html>", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\260\217\346\227\266</span></p></body></html>", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\210\206\351\222\237</span></p></body></html>", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\347\231\273\345\207\272", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:24pt; color:#ffffff;\">\345\275\223\345\211\215\347\231\273\345\275\225\350\200\205\357\274\232</span></p></body></html>", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:24pt; color:#ffffff;\">qqq</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
