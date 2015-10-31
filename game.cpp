#include "game.h"
#include <gamefield.h>
#include <QMainWindow>
#include <qlabel.h>
#define W 500
#define H 500

#define OBSTN 21
#define PARAMS 5

Game::Game(QWidget *parent) :
    QWidget(parent)
{
        textures = new QMap<QString, int>;
        initializeGame();
        setAutoFillBackground(true);
        setFixedSize (W,H);
        QPalette p;
        p.setBrush(this->backgroundRole(),QBrush(QImage(":/GameField/textures/Gamefield/ramka.png")));
        setPalette(p);
}
void Game::initializeGame()
{
    bar = new StatusBar(this);
    field = new GameField(this,textures);
    connect(this, SIGNAL(linkSingnal()), parent(), SLOT(openMenu()));

}
Game::~Game()
{
    delete bar;
    delete field;
}
GameField* Game::getfield()
{
    return field;
}
void Game::keyPressEvent(QKeyEvent *event)
{
    field->keyPressEvent(event);
}
void Game::pushPauseButton()
{
    doSignal();
}


