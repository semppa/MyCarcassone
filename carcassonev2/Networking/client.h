#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QObject>
#include "Controller/networkcontroller.h"

class NetWorkController;

class Client : public QObject
{
    Q_OBJECT
public:
    Client(NetWorkController* controller);

    bool connect(QString hostname, qint16 port, QString nick);

signals:
    void newMessage(QString from, QString msg);

public slots:
    void readyRead();
    void sendData(QByteArray data);
    void disconnectServer();

private:
    NetWorkController* controller_;
    QTcpSocket* socket;
};

#endif // CLIENT_H
