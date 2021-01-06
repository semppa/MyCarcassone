/********************************************************************************
** Form generated from reading UI file 'serverwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWINDOW_H
#define UI_SERVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWindow
{
public:
    QWidget *centralwidget;
    QPushButton *closeServer;
    QLineEdit *chatSendLE;
    QPlainTextEdit *chatWindow;
    QListWidget *playersList;
    QPushButton *StartGameBtn;

    void setupUi(QMainWindow *ServerWindow)
    {
        if (ServerWindow->objectName().isEmpty())
            ServerWindow->setObjectName(QString::fromUtf8("ServerWindow"));
        ServerWindow->resize(800, 591);
        ServerWindow->setMinimumSize(QSize(800, 591));
        ServerWindow->setMaximumSize(QSize(800, 591));
        centralwidget = new QWidget(ServerWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        closeServer = new QPushButton(centralwidget);
        closeServer->setObjectName(QString::fromUtf8("closeServer"));
        closeServer->setGeometry(QRect(590, 540, 201, 41));
        chatSendLE = new QLineEdit(centralwidget);
        chatSendLE->setObjectName(QString::fromUtf8("chatSendLE"));
        chatSendLE->setGeometry(QRect(20, 550, 561, 21));
        chatWindow = new QPlainTextEdit(centralwidget);
        chatWindow->setObjectName(QString::fromUtf8("chatWindow"));
        chatWindow->setGeometry(QRect(20, 390, 561, 151));
        chatWindow->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        playersList = new QListWidget(centralwidget);
        playersList->setObjectName(QString::fromUtf8("playersList"));
        playersList->setGeometry(QRect(10, 10, 781, 371));
        StartGameBtn = new QPushButton(centralwidget);
        StartGameBtn->setObjectName(QString::fromUtf8("StartGameBtn"));
        StartGameBtn->setGeometry(QRect(590, 490, 201, 41));
        ServerWindow->setCentralWidget(centralwidget);

        retranslateUi(ServerWindow);

        QMetaObject::connectSlotsByName(ServerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ServerWindow)
    {
        ServerWindow->setWindowTitle(QCoreApplication::translate("ServerWindow", "MainWindow", nullptr));
        closeServer->setText(QCoreApplication::translate("ServerWindow", "Close server", nullptr));
        chatWindow->setPlainText(QCoreApplication::translate("ServerWindow", "This is the famous chat everybody talks about", nullptr));
        StartGameBtn->setText(QCoreApplication::translate("ServerWindow", "Start Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWindow: public Ui_ServerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
