#include "Particula.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>

Particula::Particula(QGraphicsItem *parent) : QGraphicsItem(parent), posX(200), posY(200)
{
    setFlag(QGraphicsItem::ItemIsFocusable); //Inicialización opcional para decir que tiene el foco para eventos del teclado

}

QRectF Particula::boundingRect() const
{
    return QRectF(-5, -5, 10, 10); // Xoordenadas iniciales del rect (sobre el origen del punto), unidades a la derecha y unidades abajo
}

void Particula::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(-5, -5, 10, 10); // Adjust as needed
}

void Particula::keyPressEvent(QKeyEvent *event)
{

    //Manejo del evento de tecla
    switch(event->key()) {
    case Qt::Key_Up:
        moveBy(0, -5);
        break;
    case Qt::Key_Down:
        moveBy(0, 5);
        break;
    case Qt::Key_A:
        qDebug() << "Tecla: " << event->key();
        moveBy(-5, 0);
        break;
    case Qt::Key_D:
        qDebug() << "Tecla: " << event->key();
        moveBy(5, 0);
        break;
    case Qt::Key_W:
        qDebug() << "Tecla: " << event->key();
        moveBy(0, -5);
        break;
    case Qt::Key_S:
        qDebug() << "Tecla: " << event->key();
        moveBy(0, 5);
        break;
    default:
        QGraphicsItem::keyPressEvent(event);
    }
}

void Particula::moveBy(int dx, int dy)
{
    posX += dx;
    posY += dy;
    qDebug() << posX << " "<<posY;
    //qDebug() << "Tecla: " << x << " " <<sceneRect.right()<<" "<<sceneRect.left();
    if (posX>800||posX<0){
        posX-=dx;
    }
    if (posY>350||posY<0){
        posY-=dy;
    }
    setPos(posX, posY);
}

void Particula::movimiento()
{
    static int direction = 1;
    //posY += direction * 5;
    posX += direction * 5;
    setPos(posX, posY);


    if (posY <= 0 || posY >= 300) {
        direction *= -1;
    }
    if(posX <= 0 || posX >= 800){
        direction *= -100;
    }
}
void Particula::choque(int dx, int dy)
{
    posX += dx;
    posY += dy;
    qDebug() << posX << " "<<posY;
    //qDebug() << "Tecla: " << x << " " <<sceneRect.right()<<" "<<sceneRect.left();
    posX-=dx;
    posY-=dy;

    setPos(posX, posY);
}
