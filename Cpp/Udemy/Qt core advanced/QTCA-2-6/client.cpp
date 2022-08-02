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

    //Ssl
    this->connect(&socket,&QSslSocket::encrypted, this, &Client::encrypted);
    this->connect(&socket, &QSslSocket::encryptedBytesWritten, this, &Client::encryptedBytesWritten);
    this->connect(&socket, &QSslSocket::modeChanged, this, &Client::modeChanged);
    this->connect(&socket, &QSslSocket::peerVerifyError, this, &Client::peerVerifyError);
    this->connect(&socket, &QSslSocket::preSharedKeyAuthenticationRequired, this, &Client::preSharedKeyAuthenticationRequired);
    //idk\/
    this->connect(&socket, QOverload<const QList<QSslError> &>::of(&QSslSocket::sslErrors), this, &Client::sslErrors);


    QNetworkProxy proxy(QNetworkProxy::HttpProxy, "204.199.174.74", 999);
    /*Set Authentication
    proxy.setUser("Username");
    proxy.setPassword("Password");*/

    /*Per Application
    QNetworkProxy::setApplicationProxy(proxy);*/

    //Per Socket
    //This socket and this socket only will use the proxy
    socket.setProxy(proxy);
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
    //socket.connectToHost(host, port); <-Normal TCP

    socket.ignoreSslErrors(); //NOT SECURE!!
    socket.setProtocol(QSsl::AnyProtocol); //Many different protocols exist
    socket.connectToHostEncrypted(host,port);
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
    //socket.write("Hello, World!\r\n");

    QByteArray data;
    data.append("GET /get HTTP/1.1\r\n");
    //Impersonate Firefox and Windows
    data.append("User-Agent: Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.0; Trident/4.0)\r\n");
    //Who we are
    data.append("Host: local\r\n");
    //When done close
    data.append("Connection: Close\r\n");
    //Protocol requires a double hard return line feed
    //Tells the webserver, that is our request
    data.append("\r\n");
    socket.write(data);
    //data.append() <- If you wanted to post something

    socket.waitForBytesWritten();
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

void Client::encrypted()
{
    qInfo() << "Encrypted";
}

void Client::encryptedBytesWritten(qint64 written)
{
    qInfo() << "Encrypted Bytes Written: " << written;
}

void Client::modeChanged(QSslSocket::SslMode mode)
{
    /*Qt does not support this
     * QMetaEnum metaEnum = QMetaEnum::fromType<QSslSocket::SslMode>();
     * qDebug() << "Ssl Mode: " << metaEnum.valueToKey(mode);
     * */

    qInfo() << "Ssl Mode: " << mode;
}

void Client::peerVerifyError(const QSslError &error)
{
    //If you dont trust the cert, why?
    qInfo() << "Peer Verify Error: " << error.errorString();
}

void Client::preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenricator)
{
    //If website requires auth
    qInfo() << "Preshared key required";
    //Where you would setup your auth if needed
}

void Client::sslErrors(const QList<QSslError> &errors)
{
    qInfo() << "Ssl Error!";
    foreach(QSslError e, errors){
        qInfo() << e.errorString();
    }
}
