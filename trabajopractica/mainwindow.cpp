#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Particula.h"
#include "Jugador.h"
#include <qdebug.h>
#include <QLabel>
#include <QPixmap>
#include <QGraphicsView>
#include <QPushButton>
#include <QObject>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) //La interfaz diseñada en Qt Designer
{
    ui->setupUi(this); //This hace referencia a la clase MainWindow, configura la interfaz de usuario definida en el Qt designer
    //bool clic = true; //No hay necesidad de declararla de nuevo
    QGraphicsScene *scene = new QGraphicsScene(this); // se debe crear una escena para manejar elementos gráficos
    scene->setSceneRect(0, 0, 800, 350);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(800 + 2 * ui->graphicsView->frameWidth(), 800 + 2 * ui->graphicsView->frameWidth());//manejar la relación de aspecto

    QPixmap backgroundImage("C:/Users/JojhanSebastian/Downloads/trabajopractica/background.jpg");
    QGraphicsPixmapItem *background = scene->addPixmap(backgroundImage);



    QTimer *bgTimer = new QTimer(this);
    connect(bgTimer, &QTimer::timeout, [=]() {

        QPointF newPos = background->pos() - QPointF(1, 0); // Se ajustan las coordenadas del bg
        background->setPos(newPos);
        qDebug() << newPos << " " << scene->width() << background->pos().x() + background->pixmap().width();


        if (background->pos().x() + background->pixmap().width() <= scene->width())
            background->setPos(QPointF(0, 0)); // Volver al principio de la imagen
    });
    bgTimer->start(100);

    //Particula *bola = new Particula();
    //scene->addItem(bola);
    //bola->setFocus();

    Jugador *jug1 = new Jugador(ui->graphicsView);
    scene -> addItem(jug1);
    qDebug() << "Posición del jugador después de agregarlo a la escena:" << jug1->pos();
    jug1->setPos(200,200);
    jug1->setFocus();
    qDebug() << "Posición inicial del jugador:" << jug1->pos();
    qDebug() << ui->graphicsView->size()<<" "<<scene->sceneRect();


    timer = new QTimer;
    //connect(timer,SIGNAL(timeout()),this,SLOT(hmov(*bola)));
    connect(timer, &QTimer::timeout, [=]() {
        hmov(jug1);

    });
    timer->stop();
    r1 = scene->addRect(0, 100, 100, 100, QPen(Qt::black), QBrush(Qt::blue));
    obst.append(r1);
    for(int i=0;i<3; i++){
        obst.append(scene->addRect(100+(i*100),300,40,40,QPen(Qt::black), QBrush(Qt::black)));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    if (clic){
        ui->pushButton->setText("Hizo click");
        clic = false;
    }
    else{
        ui->pushButton->setText("Haga clic");
        clic = true;
    }
    if (timer->isActive()) timer->stop();
    else timer->start(100);

}

void MainWindow::hmov(Jugador *jug1)
{
    bool bandera = false;
    for(int i=0;i<obst.length();i++){
        if(jug1->collidesWithItem(obst.at(i))){
            bool bandera=true;           
            break;
        }
    }
}
