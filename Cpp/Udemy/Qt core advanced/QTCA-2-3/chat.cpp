#include "chat.h"

Chat::Chat(QObject *parent)
    : QObject{parent}
{
    //Want to allow multiple applications to bind on this same address
    if(!socket.bind(port,QUdpSocket::ShareAddress)){
        qInfo() << socket.errorString();
    }else{
        qInfo() << "Started on: " << socket.localAddress() << " : " << socket.localPort();
        this->connect(&socket, &QUdpSocket::readyRead, this, &Chat::readyRead);
    }
}

void Chat::command(QString value)
{
    //A slot that gets called when the command line has some sort of command
    QString message = name + ": ";
    if(name.isEmpty()){
        name = value;
        message = name + ": Joined";
        send(message);

        return;
    }

    message.append(value);
    send(message);
}

void Chat::send(QString value)
{
    QByteArray data = value.toLatin1();
    QNetworkDatagram datagram(data, QHostAddress::Broadcast, port);

    if(!socket.writeDatagram(datagram)){
        qInfo() << socket.errorString();
    }
}

void Chat::readyRead()
{
   while(socket.hasPendingDatagrams()){
       QNetworkDatagram datagram = socket.receiveDatagram();
       qInfo() << datagram.data();
   }
}
