#include "mainwindow.h"
#include <QApplication>


#define W 500
#define H 500

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    w = new QStackedWidget(this);
    game = new Game(this);
    menu = new Menu(this);
    options=new Options(this);
    about=new About(this);
    w->addWidget(about);
    w->addWidget(options);
    w->addWidget(game);
    w->addWidget(menu);
    w->setCurrentWidget(menu);
    setCentralWidget(w);

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    game->keyPressEvent(event);
}

MainWindow::~MainWindow()
{

}

void MainWindow::pushNewGameButton()
{
    menu->setContinue();
    delete game;
    game = new Game(this);
    w->addWidget(game);
    w->setCurrentWidget(game);
}

void MainWindow::pushExitButton()
{
    close();
}

void MainWindow::pushOptionsButton()
{
    w->setCurrentWidget(options);
}
void MainWindow::pushAboutButton()
{
    w->setCurrentWidget(about);
}

void  MainWindow::openGame()
{
    w->setCurrentWidget(game);
}

void MainWindow::openMenu()
{
    w->setCurrentWidget(menu);
}

