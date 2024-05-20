#ifndef JUGADOR_H
#define JUGADOR_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsView>

class Jugador:public QObject,
                public QGraphicsPixmapItem //hereda de QObject (para características de objetos de Qt) y de QGraphicsPixmapItem (para objetos gráficos en una escena gráfica de Qt).
{
    Q_OBJECT
private:
    qreal x=200;
    qreal y=200;
    QSize viewRect;
    int dir=1;
    bool flag=true;
    int cont=0;
    int spriteX = 0;
    int spriteY = 120;
    int spriteWidth = 60;
    int spriteHeight = 60;
    QPixmap sprite;
    QPixmap spriteSheet;
public:
    Jugador(QGraphicsView *view,QGraphicsItem* im = 0); //se inicializa con nullptr en el constructor. Valor predeterminado que se asigna al parámetro en caso de que no se proporcione ningún valor al crear un objeto de la clase.
    void keyPressEvent(QKeyEvent *event) override;
    // Movimiento
    void moveBy(int dx, int dy);
    //Simular caminar
    void setSprite(int dir);
    void choque(int dx, int dy, bool bandera);
    void movimiento(int dx, int dy);
};
#endif // JUGADOR_H
