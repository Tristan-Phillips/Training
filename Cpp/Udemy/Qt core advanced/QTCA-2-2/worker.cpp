#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{
    this->connect(&timer, &QTimer::timeout, this, &Worker::timeout);
    this->connect(&socket, &QUdpSocket::readyRead, this, &Worker::readyRead);
    timer.setInterval(1000);
}

void Worker::start()
{
    if(!socket.bind(port)){
        qInfo() << socket.errorString();
        return;
    }

    qInfo() << "Started UDP on " << socket.localAddress() << ":" << socket.localPort();

    broadcast();
}

void Worker::stop()
{
    timer.stop();
    socket.close();
    qInfo() << "Stopped";
}

void Worker::timeout()
{
    QString date = QDateTime::currentDateTime().toString();
    QByteArray data = date.toLatin1(); //just the byte array

    QNetworkDatagram datagram(data, QHostAddress::Broadcast, port);
    //UDP has a special protocol which requires us to put "info" into a network datagram
    //Uses bytearray data, then we want to braodcast on a specific port

    qInfo() << "Send: " << data;
    socket.writeDatagram(datagram);
    //Push the datagram into a bytestring onto the network card and out through the network
}

void Worker::readyRead()
{
    while(socket.hasPendingDatagrams()){
        //Meaning the socket has read data in
        QNetworkDatagram datagram = socket.receiveDatagram();
        qInfo() << "Read: " << datagram.data() << " From " << datagram.senderAddress() << ":" << datagram.senderPort();
    }
}

void Worker::broadcast()x
{
    qInfo() << "Broadcasting...";
    timer.start();
}
