#ifndef TANK_H
#define TANK_H

#include <QWidget>
#include <QGLWidget>
#include <QWidget>
#include <QTimer>
#include <time.h>

class T_Obj{//базовый класс
protected://доступ открыт классам, производным от данного
int obj_id;//id объектов 1-танк, 2-пуля
float x,y;//координаты
float size;//размер
GLuint texture_id;//id текстуры
public:
virtual void paint();//виртуальная функция отрисовки. метод класса, который может быть переопределён в классах-наследниках
// конкретная реализация метода для вызова будет определяться во время исполнения
void setTextureId(GLuint id);//запись id тексткры
int collide(T_Obj*);//проверка на столкговение
int LeftWallCollide();//проверка на столкновение с левой стеной
int RightWallCollide();//проверка на столкновение с правой стеной
int UpWallCollide();//проверка на столкновение с верхней стеной
int DownWallCollide();//проверка на столкновение с нижней стеной
float getX();//получение координаты х
float getY();//получение координаты y

};

class Bullet: public T_Obj{

public:
int direction;//направлние движения
int tank_id;// id танка
Bullet(float, float, int, float, int, int);//параметры: x, y, direction, size,bullet_id, tank_id
void move();//функция движения
void paint();//функция отрисовки

};

class Tank: public T_Obj{

float speed;//скорость танка
int bulletId;//id  пули
QVector<Bullet*> bullet;//выделяется память для массива пуль
public:
int direction;//направление танка
clock_t tim;//таймер стрельбы
Tank(float, float, int, float, float);//конструктор(size, speed, direction, x, y)
~Tank();//деструктор
void move(int);//передается направление движения
void paint();//отрисовка танка
void deletetank(int);//удаление танка
float getDirection();//получение направление танка
void setSpeed(float);
void setX(float);//помещаем новую координату х
void setY(float);//помещаем новую координату у
void setDirection(int);//задаем направление

};

#endif
