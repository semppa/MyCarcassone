#ifndef PLAYER_H
#define PLAYER_H

#include <Misc/DataEnums.h>
#include <QString>

using PlayerID = int;

class Player
{
public:
    Player(QString nick);

    QString getNick() {return nick_;}
    void setNick(QString nick) {nick_ = nick;}

    PlayerID getID() {return id_;}
    void setID(PlayerID id) {id_ = id;}

    ColorPallet getColor() {return color_;}
    void setColor(ColorPallet color) {color_ = color;}

    void increasePoint(int newpoints) {points += newpoints;}
    void resetPoints() {points = 0;}
    int getPoints() {return points;}

    void modifyFigureCount(int di) {nFigures += di;}
    int getNFigures() {return nFigures;}

    bool operator == (Player const &other) {return id_ == other.id_;}

private:
    QString nick_;
    PlayerID id_ = -1;
    ColorPallet color_ = ColorPallet::no_color;

    int points = 0;
    int nFigures = 7;
};

#endif // PLAYER_H
