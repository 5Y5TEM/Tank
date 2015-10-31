#include "gamefield.h"
#include <qlabel.h>
#include <QTimer>
#include <time.h>
#include <QPushButton>
#include <QMessageBox>
#define ENTER 16777220
GameField::GameField(QWidget *parent,
                     QMap<QString, int> * textures): QGLWidget(parent)
{
    setGeometry(25,25,400,400);
    tank.append(new Tank(40,60,1,50,50));
    tank.append(new Tank(40,60,1,100,100));
    //инициализация элементов
    this->textures = textures;
    paintTimer = new QTimer(this);
    connect(paintTimer, SIGNAL(timeout()), this, SLOT(updateGL()));
    paintTimer->start(1000 / 30); // 30 кадров в секунду

    QTimer *modelTimer = new QTimer(this);
    connect(modelTimer, SIGNAL(timeout()), this, SLOT(updateModel()));
    modelTimer->start(1);

    QTimer *FireTimer = new QTimer(this);
    connect(FireTimer, SIGNAL(timeout()), this, SLOT(EnemyFire()));
    FireTimer->start(2000);//враг стреляет раз в две секунды*/

    QTimer *MoveTimer = new QTimer(this);
    connect(MoveTimer, SIGNAL(timeout()), this, SLOT(EnemyEvent()));
    MoveTimer->start(501);

    this->updateGL();//вызовется инициалайджил
    drawField();

}

void GameField::initializeGL()
{
    //Включается полупрозрачность
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Включаем текстуры и использование массивов вертексов и текстурных координат
    glEnable(GL_TEXTURE_2D);
    initializeTextures();

    GLuint texid = bindTexture(QPixmap(QString(":/Field/textures/Gamefield/Game/tank.jpg")), GL_TEXTURE_2D);//подгружаем текстуры
        tank[0]->setTextureId(texid);
    GLuint texid2 = bindTexture(QPixmap(QString(":/Field/textures/Gamefield/Game/tank.jpg")), GL_TEXTURE_2D);
        tank[1]->setTextureId(texid2);

    qglClearColor(Qt::blue);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}
void GameField::initializeTextures()//инициализация текстур по id
{
    //bindTexture возвращает id текстуры
    fieldTextureId = bindTexture(QPixmap(":/Field/textures/Gamefield/Game/field.jpg"), GL_TEXTURE_2D);
    textures->insert("Enemy",
        bindTexture(QPixmap(":/Field/textures/Gamefield/Game/tank.jpg"), GL_TEXTURE_2D));
    textures->insert("Player",
        bindTexture(QPixmap(":/Field/textures/Gamefield/Game/tank.jpg"), GL_TEXTURE_2D));
    textures->insert("Bullet",
        bindTexture(QPixmap(":/Field/textures/Gamefield/Game/bub.jpg"), GL_TEXTURE_2D));
}

void GameField::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);//перестраивает вывод графики в окно с новыми размерами
}

void GameField::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);//задаем матрицу (для будущих действий)
    glLoadIdentity(); //загружаем единичную матрицу, чтоб в памяти мусора не было

    //размер экрана -1:1 по всем осям. В этом случае
    glOrtho(0, width(), 0, height(), -1, 1);//определяем координатную систему
    glPushMatrix();//помещаю текущую матрицу в стек
    drawField();//Нарисовать поле
    glPopMatrix();//возращаемся к старой системе координат
    glPushMatrix();//отрисовать все списки
    if(bullet.size())//если пуля существует
        for(int i = 0; i < bullet.size(); i++)
        {
            bullet[i]->paint();//отрисовываем каждую точку нашей пули
            glPopMatrix();//получаем значение матрицы, изменяем его(отрисовываем)
            glPushMatrix();// и помещаем обратно в стек измененную матрицу

        }
    if(tank.size())//если танк существует
        for(int i = 0; i < tank.size(); i++)
        {
            tank[i]->paint();//отрисовываем каждую точку танка
            glPopMatrix();//получаем значение матрицы, изменяем его(отрисовываем)
            glPushMatrix();// и помещаем обратно в стек измененную матрицу
        }
}

void GameField::drawField()//отрисовка поля
{
    glPushMatrix();//функция помещения матрицы в стек
    glScalef(400, 400, 1);//функция изменения размера по всем осям
    glBindTexture(GL_TEXTURE_2D, fieldTextureId);//возвращает id текстур
    glTexCoordPointer(2, GL_FLOAT, 0, textcoords);
    glVertexPointer(2, GL_FLOAT, 0, textcoords);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, indexes);//отрисовка
    glPopMatrix();//получения знасения матрицы
}


void GameField::keyPressEvent(QKeyEvent *event)//запуск событий, происходящих при нажатиях клавиш
{

        clock_t t;
        t = clock();
        if (event->key() == Qt::Key_Up)//нажатие клавиши вверх
            tank[0]->move(1);

        if (event->key() == Qt::Key_Left) {//нажатие клавиши влево
            tank[0]->move(3);
        }
        if (event->key() == Qt::Key_Down) {//нажатие клавиши вниз
            tank[0]->move(2);
        }
        if (event->key() == Qt::Key_Right) {//нажатие клавиши вправо
           tank[0]->move(4);
        }
        //нажатие клавиши enter
        if (event->key() == ENTER && !(event->isAutoRepeat()) && ((float)(t-tank[0]->tim)/CLOCKS_PER_SEC > 0.5)) {
            bullet.append(new Bullet((tank[0]->getX()), (tank[0]->getY()), tank[0]->getDirection(), 15, bulletId,0));
            tank[0]->tim = t;
        }
}

void GameField::EnemyEvent()//движение врага
{
    srand(time(NULL));
    int k = rand()%3+1;
    tank[1]->move(k);
}

void GameField::EnemyFire()//стрельба противника
{
    bullet.append(new Bullet(tank[1]->getX(), tank[1]->getY(), tank[1]->getDirection(), 15, bulletId,1));
}

void GameField::updateModel(){

    //проверка на столкновения пулек со стенами
   for(int i=0; i < bullet.size(); i++)
        if((bullet[i]->LeftWallCollide() == bullet[i]->direction) ||
           (bullet[i]->RightWallCollide() == bullet[i]->direction) ||
           (bullet[i]->UpWallCollide() == bullet[i]->direction) ||
           (bullet[i]->DownWallCollide() == bullet[i]->direction))  bullet.remove(i);
    //проверка на столкновения танков со стенами
    for(int i=0; i < tank.size(); i++)
        if((tank[i]->LeftWallCollide() == tank[i]->getDirection()) ||
                (tank[i]->RightWallCollide() == tank[i]->getDirection()) ||
                (tank[i]->UpWallCollide() == tank[i]->getDirection()) ||
                (tank[i]->DownWallCollide() == tank[i]->getDirection()))
           {
            /*if (i){
            tank[i]->deletetank(tank[i]->getDirection());}
            else{
                tank[i]->deletetank(tank[i]->getDirection());
                close();
            }*/
            //изменение направления движения при столкновении со стеной
            if (tank[i]->direction==4)
            { tank[i]->setDirection(2);}
            if (tank[i]->direction==3)
            { tank[i]->setDirection(1);}
            if (tank[i]->direction==2)
            { tank[1]->setDirection(4);}
            if (tank[i]->direction==1)
            { tank[i]->setDirection(3);}
        }

    for (int i = 0; i < bullet.size(); ++i) {//перебираем координаты пули
        bullet[i]->move();
    }
    //проверка на столкновения пулек и танков
    for (int j =0; j < tank.size(); ++j)//перебираем вектор танков
    {
       for (int i = 0; i < bullet.size(); ++i)//перебираем вектор пуль
        {
            if ((bullet[i]->getX() <= ((tank[j]->getX())+20))
                    && (bullet[i]->getX() >= ((tank[j]->getX())-20))
                    && (bullet[i]->getY() <= ((tank[j]->getY())+20))
                    && (bullet[i]->getY() >= ((tank[j]->getY())-20))
                    && bullet[i]->tank_id != j)
            {
                if (j == 0)
                {
                    tank[j]->deletetank(tank[j]->getDirection());//удаление танка
                    bullet.remove(i);//удаление пули
                    QMessageBox msgBox;//окно Game over
                    msgBox.setText("<strong><font color=black>GAME</font></strong><strong><font color=red> OVER</font></strong>");
                    msgBox.setWindowTitle("GAME OVER");
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.setDefaultButton(QMessageBox::Ok);
                    msgBox.exec();

                    close();
                }
                else {
                tank[j]->deletetank(tank[j]->getDirection());//удаление танка
                bullet.remove(i);//удаление пули
                QMessageBox msgBox;//окно Game over
                msgBox.setText("<strong><font color=black>GAME</font></strong><strong><font color=red> OVER</font></strong>");
                msgBox.setWindowTitle("GAME OVER");
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.setDefaultButton(QMessageBox::Ok);
                msgBox.exec();

                close();

                }
            }
        }
     }
}


