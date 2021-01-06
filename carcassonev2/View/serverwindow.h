#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <Controller/networkcontroller.h>
#include <Controller/datacontroller.h>
#include <memory>
#include "View/gamewindow.h"

namespace Ui {
class ServerWindow;
}

class ServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerWindow(QWidget *parent = nullptr);
    ~ServerWindow();

    bool joinServer(QString hostname, qint16 port, QString nick);
    void setNetworkController(std::shared_ptr<NetWorkController> n) {netctrl_ = n;};

private slots:
    void on_closeServer_clicked();
    void on_chatSendLE_returnPressed();
    void updateChat(QString msg);
    void addNewPlayer(QString player);
    void removePlayer(QString player);
    void closeServerWindow();
    void on_StartGameBtn_clicked();

    void openGameWindow();

signals:
    void swWindowClosed();

private:
    Ui::ServerWindow *ui;
    QWidget* parent_;
    std::shared_ptr<NetWorkController> netctrl_ = nullptr;
    DataController &datactrl_ = DataController::getInstance();

    GameWindow* gw;
};

#endif // SERVERWINDOW_H
