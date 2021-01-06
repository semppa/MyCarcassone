#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    QRegExp re("[A-Ö]{1,15}[0-9]{1,15}");
    QRegExpValidator *val = new QRegExpValidator(re, this);
    ui->userNameLE->setValidator(val);

    setWindowTitle("Carcassone - Main menu");
    setWindowIcon(QIcon("sprites/figure-red-transparent.png"));
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_joinServerBtn_clicked()
{
    bool ok;
    QInputDialog dialog;
    QString ip = dialog.getText(this, tr(""), tr("Ip to server: "),
                                       QLineEdit::Normal, tr(""), &ok);
    if (!ok) {
        return;
    }

    if (ip == "") {
        ip = "127.0.0.1";
    }

    if(sw != nullptr) {
        delete sw;
        sw = nullptr;
    }
    sw = new ServerWindow(this);
    sw->show();
    sw->setNetworkController(netctrl_);
    hide();
    if (!sw->joinServer(ip, 13370, ui->userNameLE->text())) {
        sw->close();
        show();
        QMessageBox msgBox;
        msgBox.setText("Couldn't connect to given ip");
        msgBox.exec();
    } else {
        connectSlots(sw);
    }
}

void MainMenu::on_createServerBtn_clicked()
{
    if(sw != nullptr) {
        delete sw;
        sw = nullptr;
    }
    sw = new ServerWindow(this);
    sw->setNetworkController(netctrl_);
    sw->show();
    hide();
    connectSlots(sw);
    netctrl_->createServer(ui->userNameLE->text());
}

void MainMenu::connectSlots(ServerWindow *sw)
{
    connect(netctrl_.get(), SIGNAL(newMessage(QString)), sw, SLOT(updateChat(QString)));
    connect(netctrl_.get(), SIGNAL(newPlayer(QString)), sw, SLOT(addNewPlayer(QString)));
    connect(netctrl_.get(), SIGNAL(playerDisconnected(QString)), sw, SLOT(removePlayer(QString)));
    connect(netctrl_.get(), SIGNAL(closeServerWindow()), sw, SLOT(closeServerWindow()));
    connect(netctrl_.get(), SIGNAL(openGameWindow()), sw, SLOT(openGameWindow()));
}
