#include "jugador.h"
#include <QGraphicsScene>
#include <QLabel>
#include <QPixmap>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsView>
#include <QPushButton>

//Definir el jugador y la imgen
Jugador::Jugador(QGraphicsView *view,QGraphicsItem *im):QGraphicsPixmapItem(im)
{
    setPixmap(QPixmap("C:/Users/JojhanSebastian/Downloads/trabajopractica/sprites.png"));
    x=200;
    y=200;
    setFlag(QGraphicsItem::ItemIsFocusable); //Inicialización opcional para decir que tiene el foco para eventos del teclado
    viewRect = view->size();
    QRectF sceneRect = view->sceneRect();
    qDebug() << viewRect << " "<< sceneRect << " "<<view->size().width();
    spriteSheet.load("C:/Users/JojhanSebastian/Downloads/trabajopractica/sprites.png");

    QPixmap sprite = spriteSheet.copy(spriteX, spriteY, spriteWidth, spriteHeight);
    setPixmap(sprite);

}



void Jugador::keyPressEvent(QKeyEvent *event)
{
    //Manejo del evento de tecla
    switch(event->key()) {
    case Qt::Key_A:
        //qDebug() << "Tecla: " << event->key();
        moveBy(-5, 0);
        setSprite(60);
        break;
    case Qt::Key_D:
        //qDebug() << "Tecla: " << event->key();
        moveBy(5, 0);
        setSprite(120);
        break;
    case Qt::Key_W:
        //qDebug() << "Tecla: " << event->key();
        moveBy(0, -5);
        setSprite(180);
        break;
    case Qt::Key_S:
        //qDebug() << "Tecla: " << event->key();
        moveBy(0, 5);
        setSprite(0);
        break;
    default:
        QGraphicsItem::keyPressEvent(event);
    }
}

void Jugador::moveBy(int dx, int dy)
{
    x += dx;
    y += dy;
    qDebug() << x << " "<<y;
    //qDebug() << "Tecla: " << x << " " <<sceneRect.right()<<" "<<sceneRect.left();
    if (x>viewRect.width()-50||x<0){
        x-=dx;
    }
    if (y>300||y<0){
        y-=dy;
    }
    setPos(x, y);
}

void Jugador::setSprite(int dir)
{
    spriteX = 60*cont;
    spriteY = dir;
    QPixmap sprite = spriteSheet.copy(spriteX, spriteY, spriteWidth, spriteHeight);
    setPixmap(sprite);
    cont++;
    if(cont==7){cont=0;}
}
