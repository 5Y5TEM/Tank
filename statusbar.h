#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QWidget>
#include <QPushButton>
#include <menu.h>

class StatusBar : public QWidget
{
    Q_OBJECT
    QPushButton * exitButton;
    QPushButton * pauseButton;
    QPushButton * swapButton;
    void initializeButtons();

public:
    explicit StatusBar(QWidget *parent = 0);
    ~StatusBar();
signals:
    
public slots:

    
};

#endif // STATUSBAR_H
