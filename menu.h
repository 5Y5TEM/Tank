#ifndef MENU_H
#define MENU_H

#include <QPushButton>
#include <QWidget>
#include <QApplication>
#include <GL/gl.h>
#include <QStackedWidget>



class Menu : public QWidget
{
    Q_OBJECT
protected:

        QPushButton * continueButton;
        QPushButton * newGameButton;
        QPushButton * optionsButton;
        QPushButton * aboutButton;
        QPushButton * exitButton;

        void initializeButtons();
        bool valueContinue;
    public:
        void setContinue();

        Menu(QWidget * parent=0);
        ~Menu();

    signals:

    public slots:


    };
#endif // MENU_H
