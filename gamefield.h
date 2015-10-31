#ifndef GAMEFIELD_H
#define GAMEFIELD_H

const int indexes[4] = {0, 1, 2, 3};
const float vertexes[4][2] = {{-0.5, -0.5}, {0.5, -0.5}, {0.5, 0.5}, {-0.5, 0.5}};
const float textcoords[4][2] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};

#include <QKeyEvent>
#include <QGLWidget>
#include <QWidget>
#include <QTimer>
#include <time.h>
#include <tank.h>

class GameField : public  QGLWidget
{
    Q_OBJECT
    QTimer * paintTimer; // Таймер отрисовки игрового поля
 public:
    QVector<Tank*> tank;//вектор танков
 private:
    QVector<Bullet*> bullet;//вектор пулек
    int tankId;//id танка
    int bulletId;//id пули
    int fieldTextureId; // текстура поля
    QMap<QString, int> * textures; //словать тестур
    public:
    GameField(QWidget *parent,QMap<QString, int> * textures);
    void keyPressEvent(QKeyEvent *);//вызывается при нажатии клавиши
    void initializeGL();//инициализирует работу отрисовки
    void resizeGL(int w, int h);//изменяет размеры окна
    void paintGL();//отрисовка окна и всех объектов
    void initializeTextures();//инициализвция текстур
    void drawField();//оформление
    public slots:
    void EnemyEvent();//меняет направление противника и передвигает
    void EnemyFire();//взвает выстрел
    void updateModel();//проверяет состояние системы(столкновение и т.д)
};

#endif // GAMEFIELD_H
