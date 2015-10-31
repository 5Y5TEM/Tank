#include "menu.h"
#include <QApplication>
#include <QBrush>

#define W 500
#define H 500



Menu::Menu(QWidget * parent) :
    QWidget(parent)
{
    setAutoFillBackground(true);
    setFixedSize (W,H);
    QPalette p;
    p.setBrush(this->backgroundRole(),QBrush(QImage(":/menu/textures/Menu/background.jpg")));
    setPalette(p);
    initializeButtons();
}

void Menu::setContinue()
{
    continueButton->show();
}

Menu::~Menu()
{
    delete newGameButton;
    delete optionsButton;
    delete aboutButton;
    delete exitButton;
}


void Menu::initializeButtons() {
        continueButton = new QPushButton(this);
        continueButton->hide();
        continueButton->setIconSize(QSize(130,20));
        continueButton->setIcon(QIcon(QPixmap(":/Buttons/textures/Menu/Buttons/Continue/continue.png")));
        continueButton->setGeometry(326,210,130,20);
        continueButton->setStyleSheet(
                   "QPushButton {"
                       "background-color: none;"
                       "border: none;"
                       "}"
                   "QPushButton:hover {"
                       "background-color: none;"
                       "image: url(:/Buttons/textures/Menu/Buttons/Continue/continue2.png);"
                       "}"
                   "QPushButton:pressed {"
                       "background-color: none;"
                       "border: none;"
                       "image: url(:/Buttons/textures/Menu/Buttons/Continue/continue1.png);"
                   "}"
                   "QPushButton:focus { "
                       "background-color: none;"
                       "border: none;"
                       "image: url(:/Buttons/textures/Menu/Buttons/Continue/continue2.png);"
                       " }"
            );
        connect(continueButton, SIGNAL(clicked()), parent(), SLOT(openGame()));


    newGameButton = new QPushButton(this);

    optionsButton = new QPushButton(this);

    aboutButton = new QPushButton(this);

    exitButton = new QPushButton(this);


    newGameButton->setIconSize(QSize(140, 20));
    newGameButton->setIcon(QIcon(QPixmap(":/Buttons/textures/Menu/Buttons/Game/Game.png")));

    optionsButton->setIconSize(QSize(120,40));
    optionsButton->setIcon(QIcon(QPixmap(":/Buttons/textures/Menu/Buttons/Option/option.png")));

    aboutButton->setIconSize(QSize(90,20));
    aboutButton->setIcon(QIcon(QPixmap(":/Buttons/textures/Menu/Buttons/About/about.png")));

    exitButton->setIconSize(QSize(120,40));
    exitButton->setIcon(QIcon(QPixmap(":/Buttons/textures/Menu/Buttons/Exit/exit.png")));

    newGameButton->setGeometry(315,240,140,20);
    optionsButton->setGeometry(340,260,120,40);
    aboutButton->setGeometry(365,300,90,20);
    exitButton->setGeometry(395,330,60,20);

    newGameButton->setStyleSheet(
               "QPushButton {"
                   "background-color: none;"
                   "border: none;"
                   "image: url(:/Buttons/textures/Menu/Buttons/Game/Game.png);"
                   "}"
               "QPushButton:hover {"
                   "background-color: none;"
                   "image: url(:/Buttons/textures/Menu/Buttons/Game/Game2.png);"
                   "}"
               "QPushButton:pressed {"
                   "background-color: none;"
                    "border: none;"
                   "image: url(:/Buttons/textures/Menu/Buttons/Game/Game2.png);"
               "}"
               "QPushButton:focus { "
                   "background-color: none;"
                   "border: none;"
                   "image: url(:/Buttons/textures/Menu/Buttons/Game/Game2.png);"
                   " }"
        );

    optionsButton->setStyleSheet(
               "QPushButton {"
                   "background-color: none;"
                   "border: none;"
                   "}"
               "QPushButton:hover {"
                   "background-color: none;"
                   "image: url(:/Buttons/textures/Menu/Buttons/Option/option2.png);"
                   "}"
               "QPushButton:pressed {"
                   "background-color: none;"
                    "border: none;"
                   "image: url(:/Buttons/textures/Menu/Buttons/Option/option2.png);"
               "}"
               "QPushButton:focus { "
                   "background-color: none;"
                   "border: none;"
                   "image: url(:/Buttons/textures/Menu/Buttons/Option/option2.png);"
                   " }"
        );

     aboutButton->setStyleSheet(
               "QPushButton {"
                   "background-color: none;"
                   "border: none;"
                   "}"
               "QPushButton:hover {"
                   "background-color: none;"
                   "image: url(:/Buttons/textures/Menu/Buttons/About/about2.png);"
                   "}"
               "QPushButton:pressed {"
                   "background-color: none;"
                    "border: none;"
                   "image: url(:/Buttons/textures/Menu/Buttons/About/about2.png);"
               "}"
               "QPushButton:focus { "
                   "background-color: none;"
                   "border: none;"
                   "image: url(:/Buttons/textures/Menu/Buttons/About/about2.png);"
                   " }"
        );

     exitButton->setStyleSheet(
               "QPushButton {"
                   "background-color: none;"
                   "border: none;"
                   "}"
               "QPushButton:hover {"
                   "background-color: none;"
                   "image: url(:/Buttons/textures/Menu/Buttons/Exit/exit2.png);"
                   "}"
               "QPushButton:pressed {"
                   "background-color: none;"
                    "border: none;"
                   "image: url(:/Buttons/textures/Menu/Buttons/Exit/exit2.png);"
               "}"
               "QPushButton:focus { "
                   "background-color: none;"
                   "border: none;"
                   "image: url(:/Buttons/textures/Menu/Buttons/Exit/exit2.png);"
                   " }"
        );
      newGameButton->setFocusPolicy(Qt::NoFocus);
      exitButton->setFocusPolicy(Qt::NoFocus);
      optionsButton->setFocusPolicy(Qt::NoFocus);
      aboutButton->setFocusPolicy(Qt::NoFocus);

    connect(newGameButton, SIGNAL(clicked()), parent(), SLOT(pushNewGameButton()));
    connect(exitButton, SIGNAL(clicked()), parent(), SLOT(pushExitButton()));
    connect(optionsButton, SIGNAL(clicked()), parent(), SLOT(pushOptionsButton()));
    connect(aboutButton, SIGNAL(clicked()), parent(), SLOT(pushAboutButton()));
}

