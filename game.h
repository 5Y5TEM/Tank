#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QKeyEvent>
#include "statusbar.h"
#include <menu.h>
#include <gamefield.h>

class Game : public QWidget
{
    Q_OBJECT

    StatusBar *bar;
    GameField *field;
    QMap<QString, int> * textures;
    void initializeGame();
public:
    explicit Game(QWidget *parent = 0);
    ~Game();
    GameField* getfield();

    void keyPressEvent(QKeyEvent *);
    void doSignal(){linkSingnal();}

signals:
    void linkSingnal();

public slots:
    void pushPauseButton();

};

#endif // GAME_H
