#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <menu.h>
#include "game.h"
#include <statusbar.h>
#include <gamefield.h>
#include <options.h>
#include <about.h>
#include <qstackedwidget.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Menu *menu;
    Game *game;
    Options *options;
    About *about;
    QStackedWidget *w;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *);

public slots:
    void pushNewGameButton();
    void pushExitButton();
    void pushOptionsButton();
    void pushAboutButton();
    void openGame();
    void openMenu();
};

#endif // MAINWINDOW_H
