#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <Graphics/mapitem.h>
#include <Graphics/gamescene.h>
#include <Graphics/gameview.h>
#include <QDebug>
#include <Controller/networkcontroller.h>
#include "Game/tiledatabase.h"
#include <QLabel>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

    struct scoreBoardObject {
        QLabel* nickLabel;
        std::shared_ptr<Player> playerPTR;
        std::vector<QLabel*> figureLabels;
        QLabel* pointsLabel;
        int x, y;
    };

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    void setNetworkController(std::shared_ptr<NetWorkController> n) {netctrl_ = n; view_->setNetCtrl(n);};


private slots:
    void updateChat(QString msg);
    void changeTurnLabel(PlayerID id);

    void on_chatInputLE_returnPressed();
    void placeTile(std::shared_ptr<Tile> tile);
    void tileToBePlaced(GameTile tile);
    void placeFigure(std::shared_ptr<Figure> figure);
    void removeFigure(std::shared_ptr<Figure> figure);
    void updateScoreBoard();
    void endGame();

    void rotateTileView(int rotateN);

    void on_endTurnBtn_clicked();

    void resetViewBtnClicked();

signals:
    void closed();

private:
    Ui::GameWindow *ui;
    GameScene* gameScene_;
    GameView* view_;
    std::shared_ptr<NetWorkController> netctrl_;
    DataController &datactrl_ = DataController::getInstance();

    std::vector<scoreBoardObject*> scoreBoard;

    void initializeScoreBoard();
};

#endif // GAMEWINDOW_H
