#include <tank.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define FIRE 5
using namespace std;

void T_Obj::paint(){
GLfloat vertexes[][2] = {{-0.5,-0.5},{-0.5,0.5},{0.5,0.5},{0.5,-0.5}};//массив с координатами
GLuint indices[] = {0,1,2,3};//индексы
GLfloat texcoords[][2] = {{0,0},{0,1},{1,1},{1,0}};
glTranslatef(x, y, 0);//Устанавливаем позицию, куда будет сдвинут
glScalef(size, size, 0);//Масштабируем систему координаn по x,y
glVertexPointer(2, GL_FLOAT, 0, vertexes);//Установка массива для вершинных координат;
//на одну вершину идет 2 координаты, тип координат GL_FLOAT, 0- шаг в байтах между данными с
//координатами для каждой вершины( координаты лежат плотно друг за другом),указатель на массив с координатами
glTexCoordPointer(2, GL_FLOAT, 0, texcoords);//указываем текстурные координаты
GLenum drawMode;
glBindTexture(GL_TEXTURE_2D, texture_id);//устанавливает связь texture_id с объект GL_TEXTURE_2D. текстура принимает размерность- 2-мерная
drawMode = GL_POLYGON;
glDrawElements(drawMode, 4, GL_UNSIGNED_INT, indices);//выводит индексные примитивы из массивов вершинных данных

}

//запись id тексткры
void T_Obj::setTextureId(GLuint id)
{
this->texture_id = id;
}
//проверка на столкновение с левой стеной
int T_Obj::LeftWallCollide()
{

if((this->x-this->size)<0)//если разность значениий координаты х танка или пули и размера меньше 0
return LEFT;//столкновение произошло

return 0;//иначе нет
}
//проверка на столкновение с правой стеной
int T_Obj::RightWallCollide()
{
if((this->x+this->size)>500)//если сумма значениий координаты х танка или пули и размера больше 500
return RIGHT;//столкновение произошло

return 0;//иначе нет
}

//проверка на столкновение с верхней стеной
int T_Obj::UpWallCollide()
{

if((this->y+this->size)>500)//если сумма значениий координаты у танка или пули и размера больше 500
return UP;//столкновение произошло

return 0;//иначе нет
}
//получение координаты х
float T_Obj::getX(){
return this->x;
}

//получение координаты у
float T_Obj::getY(){
return this->y;
}
//проверка на столкновение с нижней стеной
int T_Obj::DownWallCollide(){

if((this->y-this->size)<0)//если разность значениий координаты у танка или пули и размера меньше 0
return DOWN;//столкновение произошло

return 0;//иначе нет
}
//конструктор
Tank::Tank(float size, float speed, int direction, float x, float y){
this->size=size;//задаем размер
this->speed=speed;//задаем скорость
this->direction=direction;//задаем направление
this->x=x;//задаем координаты х
this->y=y;//задаем координату у
obj_id=1;//задаем id танка
tim = clock();//задаем таймер стредьбы
}
//отрисовка танка
void Tank::paint(){
GLfloat vertexes[][2] = {{-0.5,-0.5},{-0.5,0.5},{0.5,0.5},{0.5,-0.5}};//массив с координатами
GLuint indices[] = {0,1,2,3};//индексы
GLfloat texcoords[][2] = {{0,0},{0,1},{1,1},{1,0}};
GLfloat angle=0;//угол
switch(direction){//получение направления
case 2: angle=180; break;//вниз
case 3: angle=90; break;//вправо
case 4: angle=270; break;//влево
};
glTranslatef(x, y, 0);//Устанавливаем позицию, куда будет сдвинут
glRotatef(angle, 0.0f, 0.0f, 1.0f);
glScalef(size, size, 0);//Масштабируем систему координаn по x,y
glVertexPointer(2, GL_FLOAT, 0, vertexes);//Установка массива для вершинных координат;
//на одну вершину идет 2 координаты, тип координат GL_FLOAT, 0- шаг в байтах между данными с
//координатами для каждой вершины( координаты лежат плотно друг за другом),указатель на массив с координатами
glTexCoordPointer(2, GL_FLOAT, 0, texcoords);//указываем текстурные координаты
GLenum drawMode;
glBindTexture(GL_TEXTURE_2D, texture_id);//устанавливает связь texture_id с объект GL_TEXTURE_2D. текстура принимает размерность- 2-мерная
drawMode = GL_POLYGON;
glDrawElements(drawMode, 4, GL_UNSIGNED_INT, indices);//выводит индексные примитивы из массивов вершинных данных

}

//функция движения танка
void Tank::move(int tmp_drct){//передаем направление
switch(tmp_drct){//проверяем значение переменной и выполняем движение в нужную сторону с шагом 0.1
case UP: if (y>=-0.5 || y<=0.5) y+=0.1*speed; direction=tmp_drct; break;
case DOWN: if (y>=-0.5 || y<=0.5) y-=0.1*speed; direction=tmp_drct; break;
case LEFT: if (x>=-0.5 || x<=0.5) x-=0.1*speed; direction=tmp_drct; break;
case RIGHT: if (x>=-0.5 || x<=0.5) x+=0.1*speed; direction=tmp_drct; break;
}
}

float Tank::getDirection(){
return this->direction;
}

void Tank::setSpeed(float speed){
this->speed = speed;
}
void Tank::setX(float x)
{
this->x=x;
}
void Tank::setY(float y)
{
this->y = y;
}
void Tank::setDirection(int direction)
{
this->direction=direction;
}

void Tank::deletetank(int direction)
{
for (int k=0; k<1000;++k)
this->move(direction);

}
Tank::~Tank()
{
delete this;
}
//конструктор пули
Bullet::Bullet(float x, float y, int direction, float size, int texture_id , int tankid){
obj_id=2;//задаем id пули
this->x=x;//задаем координаты х
this->y=y;//задаем координаты y
this->direction=direction;//задаем направление
this->size=size;//задаем размер
this->texture_id=texture_id;//задаем id текстуры
this->tank_id=tankid;//задаем id танка
}

void Bullet::paint(){
GLfloat vertexes[][2] = {{-0.5,-0.5},{-0.5,0.5},{0.5,0.5},{0.5,-0.5}};//массив с координатами
GLuint indices[] = {0,1,2,3};//индексы
GLfloat texcoords[][2] = {{0,0},{0,1},{1,1},{1,0}};

glTranslatef(x, y, 0);//Устанавливаем позицию, куда будет сдвинут

glScalef(size, size, 0);//Масштабируем систему координаn по x,y
glVertexPointer(2, GL_FLOAT, 0, vertexes);//Установка массива для вершинных координат;
//на одну вершину идет 2 координаты, тип координат GL_FLOAT, 0- шаг в байтах между данными с
//координатами для каждой вершины( координаты лежат плотно друг за другом),указатель на массив с координатами
glTexCoordPointer(2, GL_FLOAT, 0, texcoords);//указываем текстурные координаты
GLenum drawMode;
if (texture_id != 0) {
glBindTexture(GL_TEXTURE_2D, texture_id);//устанавливает связь texture_id с объект GL_TEXTURE_2D. текстура принимает размерность- 2-мерная
drawMode = GL_POLYGON;
} else {
glColor3f(1, 0, 0);
drawMode = GL_LINE_LOOP;
}
glDrawElements(drawMode, 4, GL_UNSIGNED_INT, indices);//выводит индексные примитивы из массивов вершинных данных

}
//функция движения пули
void Bullet::move(){
switch(direction){//определяем сторону движения
case UP: if (y>=-0.5 || y<=0.5) y+=0.3; break;//если поле существует, то пуля двигается вверх с шагом 0.3
case DOWN: if (y>=-0.5 || y<=0.5) y-=0.3; break;//если поле существует, то пуля двигается вниз с шагом 0.3
case LEFT: if (x>=-0.5 || x<=0.5) x-=0.3; break;//если поле существует, то пуля двигается влево с шагом 0.3
case RIGHT: if (x>=-0.5 || x<=0.5) x+=0.3; break;//если поле существует, то пуля двигаетсявправо с шагом 0.3
}
}
