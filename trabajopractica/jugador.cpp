#include "jugador.h"
#include "mainwindow.h"
#include "Particula.h"
#include <QGraphicsScene>
#include <QLabel>
#include <QPixmap>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsView>
#include <QPushButton>

// Definir el jugador y la imagen
Jugador::Jugador(QGraphicsView *view, QGraphicsItem *im) : QGraphicsPixmapItem(im)
{
    setPixmap(QPixmap("C:/Users/JojhanSebastian/Downloads/trabajopractica/sprites.png"));
    x = 200;
    y = 200;
    setFlag(QGraphicsItem::ItemIsFocusable);
    viewRect = view->size();
    spriteSheet.load("C:/Users/JojhanSebastian/Downloads/trabajopractica/sprites.png");

    QPixmap sprite = spriteSheet.copy(spriteX, spriteY, spriteWidth, spriteHeight);
    setPixmap(sprite);
}

void Jugador::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_A:
        moveBy(-5, 0);
        setSprite(60);
        break;
    case Qt::Key_D:
        moveBy(5, 0);
        setSprite(120);
        break;
    case Qt::Key_W:
        moveBy(0, -5);
        setSprite(180);
        break;
    case Qt::Key_S:
        moveBy(0, 5);
        setSprite(0);
        break;
    default:
        QGraphicsItem::keyPressEvent(event);
    }
}

void Jugador::moveBy(int dx, int dy)
{
    qreal newX = x + dx;
    qreal newY = y + dy;
    setPos(newX, newY);

    if (newX > viewRect.width() - 50 || newX < 0) {
        newX -= dx;
    }
    if (newY > 300 || newY < 0) {
        newY -= dy;
    }

    bool collisionDetected = false;

    for (QGraphicsItem *item : collidingItems())
    {
        if (dynamic_cast<QGraphicsRectItem *>(item))
        {
            collisionDetected = true;
            break;
        }
    }

    if (collisionDetected)
    {
        setPos(x, y); // Revertir a la posición anterior
    }
    else
    {
        x = newX;
        y = newY;
    }

}
void Jugador::setSprite(int dir)
{
    spriteX = 60 * cont;
    spriteY = dir;
    QPixmap sprite = spriteSheet.copy(spriteX, spriteY, spriteWidth, spriteHeight);
    setPixmap(sprite);
    cont++;
    if (cont == 7)
    {
        cont = 0;
    }
}

void Jugador::choque(int dx, int dy, bool bandera)
{
    x += dx;
    y += dy;
    if (bandera == true)
    {
        y -= dy;
        x -= dx;
    }
    setPos(x, y);
}

