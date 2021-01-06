#include "View/mainmenu.h"
#include "View/gamewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<MainMenu> w = std::make_shared<MainMenu>();
    std::shared_ptr<NetWorkController> n = std::make_shared<NetWorkController>();
    DataController& d = DataController::getInstance();
    std::shared_ptr<Player> player = std::make_shared<Player>(QString("User"));

    d.setPlayerPTR(player);
    w->setNetworkController(n);


    w->show();
    return a.exec();
}
