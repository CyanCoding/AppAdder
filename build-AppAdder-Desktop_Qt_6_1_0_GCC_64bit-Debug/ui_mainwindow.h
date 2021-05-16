/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *iconBox;
    QLabel *label;
    QPushButton *locateIcon;
    QPushButton *locateApp;
    QLabel *label_2;
    QLineEdit *appBox;
    QLabel *label_3;
    QLineEdit *iconBox_3;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(310, 348);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        iconBox = new QLineEdit(centralwidget);
        iconBox->setObjectName(QString::fromUtf8("iconBox"));
        iconBox->setGeometry(QRect(40, 190, 131, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 160, 41, 21));
        locateIcon = new QPushButton(centralwidget);
        locateIcon->setObjectName(QString::fromUtf8("locateIcon"));
        locateIcon->setGeometry(QRect(180, 190, 41, 21));
        locateApp = new QPushButton(centralwidget);
        locateApp->setObjectName(QString::fromUtf8("locateApp"));
        locateApp->setGeometry(QRect(180, 120, 41, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 90, 131, 21));
        appBox = new QLineEdit(centralwidget);
        appBox->setObjectName(QString::fromUtf8("appBox"));
        appBox->setGeometry(QRect(40, 120, 131, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 20, 131, 21));
        iconBox_3 = new QLineEdit(centralwidget);
        iconBox_3->setObjectName(QString::fromUtf8("iconBox_3"));
        iconBox_3->setGeometry(QRect(40, 50, 181, 21));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(40, 230, 181, 23));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 270, 89, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 310, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "AppAdder", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Icon:", nullptr));
        locateIcon->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        locateApp->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "App/command file", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "App name", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Open in terminal", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
