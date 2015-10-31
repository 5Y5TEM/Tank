#include "options.h"
#include <qpixmap.h>
#include <qicon>
#include <qlabel.h>
#include <mainwindow.h>

#define W 500
#define H 500

Options::Options(QWidget *parent) :
    QWidget(parent)
{
    setAutoFillBackground(true);
    setGeometry(0,0,500,500);
    QPalette p;
    p.setBrush(this->backgroundRole(),QBrush(QImage(":/menu/textures/Menu/background.jpg")));
    setPalette(p);
    QLabel *label= new QLabel(this);
    label->setGeometry(55,200,390,190);
    label->setPixmap(QPixmap("D:\\University\\Game\\panzer\\textures\\op.png"));
    initializeButtons();

}


void Options::initializeButtons()
{
        DownButton = new QPushButton(this);
        DownButton->setDown(false);
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
        DownButton->setCheckable(true);
        DownButton->setChecked(true);
        DownButton->setFocus();
        DownButton->setDown(true);
        DownButton->setCheckable(false);
}



