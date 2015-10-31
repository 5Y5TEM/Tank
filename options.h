#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>
#include <QPushButton>
//#include <menu.h>

class Options : public QWidget
{
    Q_OBJECT
    QPushButton * DownButton;
public:
    Options(QWidget *parent = 0);
    void initializeButtons();
signals:
    
public slots:

    
};

#endif // OPTIONS_H
