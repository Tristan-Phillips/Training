#include <QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QFile>

//Serialization
bool saveFile(QString path){
    QFile file(path);

    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_15);

    QString title = "The answer is ";
    qint64 num = 42;

    out << title;
    out << num;

    file.flush();
    file.close();

    return true;
}

bool readFile(QString path){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QDataStream in(&file);
    if(in.version() != QDataStream::Qt_5_15){
        qCritical() << "Use Version 5.15";
        file.close();
        return false;
    }

    QString title;
    qint64 num;

    in >> title;
    in >> num;

    qInfo() << title;
    qInfo() << num;

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString file = "test.txt";

    if(saveFile("test.txt")){
        qInfo() << "Saved";
        readFile(file);
    }

    return a.exec();
}
