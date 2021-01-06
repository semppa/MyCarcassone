#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "View/serverwindow.h"
#include <QInputDialog>
#include <QRegExp>
#include <QRegExpValidator>
#include <memory>
#include <QMessageBox>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

    void setNetworkController(std::shared_ptr<NetWorkController> n) {netctrl_ = n;};

private slots:
    void on_joinServerBtn_clicked();

    void on_createServerBtn_clicked();


private:
    Ui::MainMenu *ui;

    void connectSlots(ServerWindow* sw);

    ServerWindow* sw = nullptr;

    std::shared_ptr<NetWorkController> netctrl_ = nullptr;
};

#endif // MAINMENU_H
