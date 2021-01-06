/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QPushButton *createServerBtn;
    QPushButton *joinServerBtn;
    QLineEdit *userNameLE;
    QLabel *usernameLabel;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(818, 274);
        MainMenu->setMinimumSize(QSize(818, 274));
        MainMenu->setMaximumSize(QSize(818, 274));
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        createServerBtn = new QPushButton(centralwidget);
        createServerBtn->setObjectName(QString::fromUtf8("createServerBtn"));
        createServerBtn->setGeometry(QRect(50, 70, 251, 91));
        joinServerBtn = new QPushButton(centralwidget);
        joinServerBtn->setObjectName(QString::fromUtf8("joinServerBtn"));
        joinServerBtn->setGeometry(QRect(490, 70, 251, 91));
        userNameLE = new QLineEdit(centralwidget);
        userNameLE->setObjectName(QString::fromUtf8("userNameLE"));
        userNameLE->setGeometry(QRect(290, 210, 251, 21));
        usernameLabel = new QLabel(centralwidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setGeometry(QRect(230, 210, 61, 20));
        MainMenu->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainMenu->setStatusBar(statusbar);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "MainWindow", nullptr));
        createServerBtn->setText(QCoreApplication::translate("MainMenu", "Create Server", nullptr));
        joinServerBtn->setText(QCoreApplication::translate("MainMenu", "Join Server", nullptr));
        userNameLE->setText(QCoreApplication::translate("MainMenu", "User", nullptr));
        usernameLabel->setText(QCoreApplication::translate("MainMenu", "Username:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
