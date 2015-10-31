#include "statusbar.h"
#include <qnamespace.h>
#include <qlabel.h>

StatusBar::StatusBar(QWidget *parent) :
    QWidget(parent)
{
    setAutoFillBackground(true);
    setGeometry(450,0,50,500);
    QPalette p;
    p.setColor(QPalette::Window, Qt::green); //фон
    setPalette(p);
    QLabel *label= new QLabel(this);
    label->setGeometry(0,0,450,500);
    label->setPixmap(QPixmap(":/GameField/textures/Gamefield/statusbar.png"));
    initializeButtons();

}

StatusBar::~StatusBar()
{
    delete pauseButton;
}

void StatusBar::initializeButtons()
{
    pauseButton = new QPushButton(this);
    pauseButton->setGeometry(0,0,50,50);
    pauseButton->setIconSize(QSize(50, 50));
    pauseButton->setIcon(QIcon(QPixmap(":/Buttons/textures/Gamefield/Buttons/Pause/pause.png")));
    pauseButton->setStyleSheet(
               "QPushButton {"
                   "background-color: none;"
                   "border: none;"
                   "}"
               "QPushButton:hover {"
                   "background-color: none;"
                   "image: url(:/Buttons/textures/Gamefield/Buttons/Pause/pause2.png);"
                   "}"
               "QPushButton:pressed {"
                   "background-color: none;"
                   "image: url(:/Buttons/textures/Gamefield/Buttons/Pause/pause2.png);"
               "}"
               "QPushButton:focus { "
                   "background-color: none;"
                   "border: none;"
                   "image: url(:/Buttons/textures/Gamefield/Buttons/Pause/pause2.png);"
                   " }"
        );
    pauseButton->setFocusPolicy(Qt::NoFocus);
    connect(pauseButton, SIGNAL(clicked()), parent(), SLOT(pushPauseButton()));
}

