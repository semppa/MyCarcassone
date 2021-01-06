#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    gameScene_ = new GameScene(this, 50);
    view_ = new GameView(this, gameScene_);;
    gameScene_->setGameView(view_);

    QGraphicsScene* scene = new QGraphicsScene(1,1,98,98);
    ui->tileView->setScene(scene);

    connect(view_, SIGNAL(rotateTileView(int)), this, SLOT(rotateTileView(int)));

    setWindowTitle("Carcassone - Game Window");
    initializeScoreBoard();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::updateChat(QString msg)
{
    ui->chatBox->appendPlainText(msg);
}

void GameWindow::changeTurnLabel(PlayerID id)
{
    for(auto sbObject : scoreBoard) {
        sbObject->nickLabel->setText(sbObject->playerPTR->getNick());
        if(sbObject->playerPTR->getID() == id) {
            sbObject->nickLabel->setText("--- IN TURN --- " + sbObject->playerPTR->getNick());
        }
    }
}

void GameWindow::on_chatInputLE_returnPressed()
{
    QString message = ui->chatInputLE->text();
    QString sender = datactrl_.getPlayerPTR()->getNick();

    netctrl_->sendMessage(sender, message);
    ui->chatInputLE->setText("");
}

void GameWindow::placeTile(std::shared_ptr<Tile> tile)
{
    if (!datactrl_.myTurn()) { // Tile should be already drawn
        gameScene_->drawItem(tile);
    }
}

void GameWindow::tileToBePlaced(GameTile tile)
{
    ui->tileView->scene()->clear();
    MapItem *gItem = new MapItem(std::make_shared<Tile>(QPoint(0,0), tile, 0), ui->tileView->width());
    ui->tileView->scene()->addItem(gItem);
    ui->tileView->resetTransform();

    if (datactrl_.myTurn()) {
        view_->initializeMyTurn();
    }
}

void GameWindow::placeFigure(std::shared_ptr<Figure> figure)
{
    if (!datactrl_.myTurn()) { // Figure should be already placed
        gameScene_->drawFigure(figure);
    } else {
        /*
         * Since the figure is already drawn, there exists a FigureGraphicsItem that has a shared_ptr for some figure class.
         * Because networkcontroller created a new figure, there now exists 2 pointers to basically the same figure class. Other
         * pointer can be accessed from tile->getFig and other is on the FigureGraphicsItem. Since the primary way of getting
         * pointer to figure is from coordinates->tile->getFig, we want to keep the one that locates on tiles and update the one
         * that is stored in figuregraphicsitem
        */
        gameScene_->updateFigPTR(figure);
    }
    updateScoreBoard();
}

void GameWindow::removeFigure(std::shared_ptr<Figure> figure)
{
    gameScene_->removeFigure(figure);
}

void GameWindow::updateScoreBoard()
{
    for(auto obj : scoreBoard) {
        obj->pointsLabel->setText("Score: " + QString::fromStdString(std::to_string(obj->playerPTR->getPoints())));

        if (obj->playerPTR->getNFigures() != int(obj->figureLabels.size())) {
            for(auto label : obj->figureLabels) {
                delete label;
            }
            QString sprite = "sprites/figure-" + toQString(obj->playerPTR->getColor()) + "-transparent.png";
            QPixmap pixmap(sprite);
            QPixmap scaled = pixmap.scaled(20,20);

            std::vector<QLabel*> figureLabels;
            for (int i = 0; i < obj->playerPTR->getNFigures(); i++) {
                QLabel* figlbl = new QLabel(this);
                figlbl->setPixmap(scaled);
                figlbl->setGeometry(obj->x + i*20, obj->y+20, 20, 20);
                figlbl->show();
                figureLabels.push_back(figlbl);
            }
            obj->figureLabels = figureLabels;
        }
    }
}

void GameWindow::endGame()
{
    int max = 0;
    int playerPoints;
    std::unordered_set<PlayerID> winners;
    for(auto obj : scoreBoard) {
        playerPoints = obj->playerPTR->getPoints();
        obj->pointsLabel->setText("Score: " + QString::fromStdString(std::to_string(playerPoints)));

        if (playerPoints > max) {
            winners = {obj->playerPTR->getID()};
            max = playerPoints;
        } else if (playerPoints == max) {
            winners.insert(obj->playerPTR->getID());
        }
    }

    for(auto obj : scoreBoard) {
        if(winners.find(obj->playerPTR->getID()) != winners.end()) {
            obj->nickLabel->setText("--WINNER-- " + obj->playerPTR->getNick() + " --WINNER--");
        }
    }

    ui->tileView->scene()->clear();
}

void GameWindow::rotateTileView(int rotateN)
{
    ui->tileView->resetTransform();
    ui->tileView->rotate(90 * rotateN);
}


void GameWindow::on_endTurnBtn_clicked()
{
    if (datactrl_.myTurn()) {
        view_->endTurnCleanup(); // Cleaning up for example removing placeholder figures if one was not placed
        netctrl_->endTurn();
    }
}

void GameWindow::initializeScoreBoard()
{
    QString nick = datactrl_.getPlayerPTR()->getNick();
    int nFigures = datactrl_.getPlayerPTR()->getNFigures();
    int points = datactrl_.getPlayerPTR()->getPoints();

    int wWidth = 150; int wHeight = 80;
    int x = 430; int y = 570;

    scoreBoardObject* sbObj = new scoreBoardObject;
    sbObj->x = x;
    sbObj->y = y;
    sbObj->playerPTR = datactrl_.getPlayerPTR();

    QLabel* nicklbl = new QLabel(this);
    nicklbl->setText(nick);
    nicklbl->setGeometry(x, y, wWidth-10, (wHeight - 20) / 3);
    sbObj->nickLabel = nicklbl;

    QString sprite = "sprites/figure-" + toQString(datactrl_.getPlayerPTR()->getColor()) + "-transparent.png";
    QPixmap pixmap(sprite);
    QPixmap scaled = pixmap.scaled(20,20);

    std::vector<QLabel*> figureLabels;
    for (int i = 0; i < nFigures; i++) {
        QLabel* figlbl = new QLabel(this);
        figlbl->setPixmap(scaled);
        figlbl->setGeometry(x + i*20, y+20, 20, 20);
        figureLabels.push_back(figlbl);
    }
    sbObj->figureLabels = figureLabels;

    QLabel* pointlbl = new QLabel(this);
    pointlbl->setText("Score: " + QString::fromStdString(std::to_string(points)));
    pointlbl->setGeometry(x, y+40, wWidth-10, (wHeight - 20) / 3);
    sbObj->pointsLabel = pointlbl;

    scoreBoard.push_back(sbObj);

    int xp = 0;
    int yp = 1;
    int i = 0;
    for(auto peer : datactrl_.getPeers()) {
        scoreBoardObject* sbObj = new scoreBoardObject;
        x = x + (xp * wWidth);
        y = y + (yp * wHeight);
        nick = peer->getNick();
        nFigures = peer->getNFigures();
        points = peer->getPoints();

        sbObj->x = x;
        sbObj->y = y;
        sbObj->playerPTR = peer;

        QLabel* nicklbl = new QLabel(this);
        nicklbl->setText(nick);
        nicklbl->setGeometry(x, y, wWidth-10, (wHeight - 20) / 3);
        sbObj->nickLabel = nicklbl;

        QString sprite = "sprites/figure-" + toQString(peer->getColor()) + "-transparent.png";
        QPixmap pixmap(sprite);
        QPixmap scaled = pixmap.scaled(20,20);

        std::vector<QLabel*> figureLabels;
        for (int i = 0; i < nFigures; i++) {
            QLabel* figlbl = new QLabel(this);
            figlbl->setPixmap(scaled);
            figlbl->setGeometry(x + i*20, y+20, 20, 20);
            figureLabels.push_back(figlbl);
        }
        sbObj->figureLabels = figureLabels;

        QLabel* pointlbl = new QLabel(this);
        pointlbl->setText("Score: " + QString::fromStdString(std::to_string(points)));
        pointlbl->setGeometry(x, y+40, wWidth-10, (wHeight - 20) / 3);
        sbObj->pointsLabel = pointlbl;

        scoreBoard.push_back(sbObj);

        i++;
        xp = i % 2; // "osctillating number between 0 and 1
        yp = 1 - (i % 2) * 2; // "oscillating" number between -1 and 1
    }

}
