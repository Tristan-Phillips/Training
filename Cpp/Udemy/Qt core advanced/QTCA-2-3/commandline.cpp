#include "commandline.h"

Commandline::Commandline(QObject *parent, FILE *fileHandle)
    : QObject{parent},
      cin{fileHandle}
{

}

void Commandline::monitor()
{
    while (true){
        QString value = cin.readLine();
        emit command(value);
    }
}
