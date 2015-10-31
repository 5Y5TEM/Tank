#include "about.h"
#include <qlabel.h>
#define W 500
#define H 500

About::About(QWidget *parent) :
    QWidget(parent)
{
    setAutoFillBackground(true);
    setFixedSize (W,H);
    QPalette p;
    p.setBrush(this->backgroundRole(),QBrush(QImage(":/menu/textures/Menu/background.jpg")));
    setPalette(p);
    initializeButtons();
    QLabel *label= new QLabel(this);
    label->setGeometry(110,100,400,400);
    label->setPixmap(QPixmap(":/menu/textures/Menu/info.png"));

}

About::~About()
{
    delete DownButton;
}

void About::initializeButtons()
{
    DownButton = new QPushButton(this);
    DownButton->setGeometry(10,10,70,70);
    DownButton->setIconSize(QSize(70, 70));
    DownButton->setIcon(QIcon(QPixmap(":/Buttons/textures/Menu/Buttons/Back/back.png")));
    DownButton->setStyleSheet(
            "QPushButton {"
                "background-color: none;"
                "border: none;"
                "}"
            "QPushButton:hover {"
                "background-color: none;"
                "image: url(:/Buttons/textures/Menu/Buttons/Back/back2.png);"
                "}"
            "QPushButton:pressed {"
                "background-color: none;"
                "image: url(:/Buttons/textures/Menu/Buttons/Back/back2.png);"
            "}"
            "QPushButton:focus { "
                "background-color: none;"
                "border: none;"
                "image: url(:/Buttons/textures/Menu/Buttons/Back/back2.png);"
                " }"
    );
    connect(DownButton, SIGNAL(clicked()), parent(), SLOT(openMenu()));

}
