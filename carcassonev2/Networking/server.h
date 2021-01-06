#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include <QTcpServer>
#include <QTcpSocket>
#include "Controller/networkcontroller.h"
#include <Networking/dataencoder.h>
#include "Networking/servereventhandler.h"
#include <unordered_set>

class NetWorkController;

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(NetWorkController* netcontroller, QObject* parent = nullptr);
    void start(QString nick);

public slots:
    void newConnection();
    void readyRead();
    void disconnected();
    void closeServer();

    void echoData(QByteArray data);

private:
    NetWorkController* netctrl_;
    std::vector<std::pair<std::shared_ptr<Player>, QTcpSocket*>> clients_;
    std::shared_ptr<Player> host_;

    std::shared_ptr<DataEncoder> encoder_;
    ServerEventHandler &sEventHandler_ = ServerEventHandler::getInstance();
    std::unordered_set<DataType> serverDataTypes;
};

#endif // SERVER_H
