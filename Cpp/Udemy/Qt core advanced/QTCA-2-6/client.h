#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QMetaEnum>
#include <QNetworkProxy>

#include <QSslSocket>
#include <QSslPreSharedKeyAuthenticator>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

signals:

public slots:
    void connectToHost(QString host, quint16 port);
    void disconnect();

private slots:
    void connected();
    void disconnected();
    void error(QAbstractSocket::SocketError socketError);
    void stateChanged(QAbstractSocket::SocketState socketState);
    void readyRead();

    //Ssl
    //Starting Encryption
    void encrypted();
    //When Writing secure bytes
    void encryptedBytesWritten(qint64 written);
    //SSl mode
    void modeChanged(QSslSocket::SslMode mode);
    void peerVerifyError(const QSslError &error);
    void preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenricator);
    void sslErrors(const QList<QSslError> &errors);

private:
    /*Change from QTcpSocket to QSslSocket
    QTcpSocket socket;*/
    QSslSocket socket;
};

#endif // CLIENT_H
