#include <QCoreApplication>
#include <QString>
#include <QDebug>

void division(int i){
    try{
        if(!i){
            throw QString("Division by zero!");
        }

        double value = (double)i/2;
        qInfo() << "Value: " << value;
    }
    catch (QString e){
        qInfo() << "Input is invalid: " << e;
    } catch(...){
        qInfo() << "Unknown Error";
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    division(1);
    division(0);
    return a.exec();
}
