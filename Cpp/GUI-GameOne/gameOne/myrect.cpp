#include "myrect.h"
#include "bullet.h"
#include <QDebug>

MyRect::MyRect(){
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key pressed=";
    if(event->key() == Qt::Key_Left){
        setPos(x()-10,y());
        qDebug() << "Left";
    }
    else if(event->key() == Qt::Key_Right){
        setPos(x()+10,y());
        qDebug() << "Right";
    }
    else if(event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
        qDebug() << "Up";
    }
    else if(event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
        qDebug() << "Down";
    }else if(event->key() == Qt::Key_Space){
        //Create bullet
        Bullet *bullet = new Bullet();
        qDebug() << "Space";

        scene()->addItem(bullet);
    }
}
