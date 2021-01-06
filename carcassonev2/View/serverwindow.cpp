#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWindow),
    parent_(parent)
{
    ui->setupUi(this);
    setWindowTitle("Carcassone - Server Window");
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

bool ServerWindow::joinServer(QString hostname, qint16 port, QString nick)
{
    ui->closeServer->setText(QString("Leave server"));
    ui->StartGameBtn->setDisabled(true);
    return netctrl_->joinServer(hostname, port, nick);
}

void ServerWindow::on_closeServer_clicked()
{
    netctrl_->leaveServer();
    closeServerWindow();
}

void ServerWindow::on_chatSendLE_returnPressed()
{
    QString message = ui->chatSendLE->text();
    QString sender = datactrl_.getPlayerPTR()->getNick();

    netctrl_->sendMessage(sender, message);
    ui->chatSendLE->setText("");
}

void ServerWindow::updateChat(QString msg)
{
    ui->chatWindow->appendPlainText(msg);
}

void ServerWindow::addNewPlayer(QString player)
{
    ui->playersList->addItem(player);
}

void ServerWindow::removePlayer(QString player)
{
    int rows = ui->playersList->count();

    for (int i = 0; i < rows; i++) {
        if (ui->playersList->item(i)->text() == player){
            ui->playersList->takeItem(i);
            break;;
        }
    }
}

void ServerWindow::closeServerWindow()
{
    parent_->show();
    close();
}

void ServerWindow::on_StartGameBtn_clicked()
{
    netctrl_->startGame();
}

void ServerWindow::openGameWindow()
{
    gw = new GameWindow(this);
    gw->show();
    gw->setNetworkController(netctrl_);
    hide();

    connect(netctrl_.get(), SIGNAL(newMessage(QString)), gw, SLOT(updateChat(QString)));
    connect(netctrl_.get(), SIGNAL(changeInTurnLabel(PlayerID)), gw, SLOT(changeTurnLabel(PlayerID)));
    connect(netctrl_.get(), SIGNAL(placeTile(std::shared_ptr<Tile>)), gw, SLOT(placeTile(std::shared_ptr<Tile>)));
    connect(netctrl_.get(), SIGNAL(tileToBePlaced(GameTile)), gw, SLOT(tileToBePlaced(GameTile)));
    connect(netctrl_.get(), SIGNAL(placeFigure(std::shared_ptr<Figure>)), gw, SLOT(placeFigure(std::shared_ptr<Figure>)));
    connect(netctrl_.get(), SIGNAL(removeFigure(std::shared_ptr<Figure>)), gw, SLOT(removeFigure(std::shared_ptr<Figure>)));
    connect(netctrl_.get(), SIGNAL(updateScoreBoard()), gw, SLOT(updateScoreBoard()));
    connect(netctrl_.get(), SIGNAL(endGame()), gw, SLOT(endGame()));
}
