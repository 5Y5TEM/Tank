#ifndef ABOUT_H
#define ABOUT_H

#include <QPushButton>
#include <QWidget>

class About : public QWidget
{
    Q_OBJECT
    QPushButton * DownButton;
public:
    explicit About(QWidget *parent = 0);
    ~About();
    void initializeButtons();
signals:
    
public slots:

};

#endif // ABOUT_H
