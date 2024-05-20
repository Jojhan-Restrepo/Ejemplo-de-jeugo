#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Particula.h"
#include "jugador.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool clic;

private slots:
    void on_pushButton_clicked(); //Se crea una vez vamos al slot
    void hmov(Jugador *jug1);


private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsRectItem *r1;
    QList<QGraphicsRectItem*> obst;
};
#endif // MAINWINDOW_H

