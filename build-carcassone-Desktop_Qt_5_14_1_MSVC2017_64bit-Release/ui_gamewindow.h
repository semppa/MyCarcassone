/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *chatBox;
    QLineEdit *chatInputLE;
    QGraphicsView *tileView;
    QPushButton *endTurnBtn;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameWindow->sizePolicy().hasHeightForWidth());
        GameWindow->setSizePolicy(sizePolicy);
        GameWindow->setMinimumSize(QSize(1280, 720));
        GameWindow->setMaximumSize(QSize(1280, 720));
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        chatBox = new QPlainTextEdit(centralwidget);
        chatBox->setObjectName(QString::fromUtf8("chatBox"));
        chatBox->setGeometry(QRect(10, 570, 401, 111));
        chatBox->setReadOnly(true);
        chatInputLE = new QLineEdit(centralwidget);
        chatInputLE->setObjectName(QString::fromUtf8("chatInputLE"));
        chatInputLE->setGeometry(QRect(10, 690, 401, 21));
        chatInputLE->setMouseTracking(false);
        tileView = new QGraphicsView(centralwidget);
        tileView->setObjectName(QString::fromUtf8("tileView"));
        tileView->setGeometry(QRect(1170, 580, 100, 100));
        tileView->setSceneRect(QRectF(0, 0, 0, 0));
        endTurnBtn = new QPushButton(centralwidget);
        endTurnBtn->setObjectName(QString::fromUtf8("endTurnBtn"));
        endTurnBtn->setGeometry(QRect(1169, 690, 101, 22));
        GameWindow->setCentralWidget(centralwidget);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "MainWindow", nullptr));
        endTurnBtn->setText(QCoreApplication::translate("GameWindow", "End turn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
