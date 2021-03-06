#include "client.h"

Client::Client(QObject *parent)
    : QObject{parent}
{
    this->connect(&socket, &QTcpSocket::connected, this, &Client::connected);
    //Disconnections can happen for many reasons
    this->connect(&socket, &QTcpSocket::disconnected, this, &Client::disconnected);
    this->connect(&socket, &QTcpSocket::stateChanged, this, &Client::stateChanged);
    //Ready Read - have info from socket
    this->connect(&socket, &QTcpSocket::readyRead, this, &Client::readyRead);
    //Have to use QAbstractSocket
    //Overload -> State change doesnt auto happen
    this->connect(&socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &Client::error);
}

void Client::connectToHost(QString host, quint16 port)
{
    if(socket.isOpen()){
        disconnect();
    }

    qInfo() << "Connecting to: " << host << " on port " << port;

    //Dont use ::connect it is a qmeta object
    //With connect to host you can connect to different ip's & ports & protocols
    //Returns void
    socket.connectToHost(host, port);

}

void Client::disconnect()
{
    //Sends acknowledgement that "we no longer want to talk to you"
    socket.close();
}

void Client::connected()
{
    qInfo() << "Connected";

    //Send data to remote host
    qInfo() << "Sending";
    socket.write("Hello, World!\r\n");


}

void Client::disconnected()
{
    qInfo() << "Disconnected";
}

void Client::error(QAbstractSocket::SocketError socketError)
{
    qInfo() << "Error: " << socketError << " " << socket.errorString();
}

void Client::stateChanged(QAbstractSocket::SocketState socketState)
{
    //Once connected, whats happening, monitor state of connection
    //\/ Taking enumerator and getting the character representation (array -> name)
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    qInfo() << "State: " << metaEnum.valueToKey(socketState);
}

void Client::readyRead()
{
    //How many bites in socket to be read (bytesAvailable)
    qInfo() << "Data From: " << sender() << " bytes: " << socket.bytesAvailable();
    qInfo() << "Data: " << socket.readAll();
}
