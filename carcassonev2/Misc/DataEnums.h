#ifndef DATAENUMS_H
#define DATAENUMS_H

#include <QString>

enum ColorPallet { red, green, blue, pink, yellow, black, no_color};

inline const QString toQString(ColorPallet c) {
    switch (c) {
        case red: return QString("red");
        case green: return QString("green");
        case blue: return QString("blue");
        case pink: return QString("pink");
        case yellow: return QString("yellow");
        case black: return QString("black");
    default: return QString("");
    }
}

enum DataType {
    Chat,  // New message in chat
    IConnected, // Server responds that my own connection was succesfull
    NewUserConnected,  // New player joined the server
    UserDisconnected,  // User has disconnected
    ServerClosed, // When server is closed, everybody is disconnected and mainmenu prompted
    TilePlaced,  // Tile is placed
    FigurePlaced, // Figure is placed
    NewTurn, // New turn begins in game and server gives player in turn and current scoreboard
    EndTurn, // End your turn
    StartGame,  // Game was started
    EndGame // Final move has been played and game ends
};


#endif // DATAENUMS_H
