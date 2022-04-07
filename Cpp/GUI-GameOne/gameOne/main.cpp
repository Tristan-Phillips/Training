#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "myrect.h"
//Following: https://www.youtube.com/watch?v=8ntEQpg7gck&list=PLyb40eoxkelOa5xCB9fvGrkoBf8JzEwtV

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Create a scene
    QGraphicsScene *scene = new QGraphicsScene();
    //Create an item to put into the scene
    MyRect *rect = new MyRect();
    rect->setRect(0,0,100,100); //position, width, height
    //Add the item to the scene
    scene->addItem(rect);
    //Make Rect Focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    //Add a view
    QGraphicsView *view = new QGraphicsView(scene);
    //view->setScene(scene); You could do this instead of ^
    //The view is a widget
    view->show();
    return a.exec();
}
