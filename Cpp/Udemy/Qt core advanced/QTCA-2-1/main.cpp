#include <QCoreApplication>

#include <QDebug>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QAbstractSocket>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //List of all network interfaces
    QList<QHostAddress> list = QNetworkInterface::allAddresses();

    for(int i = 0; i < list.count(); i++){
        QHostAddress address = list.at(i);
        qInfo() << address.toString();

        //Never leaves the machine (Local Address)
        qInfo() << "\t Loopback: " << address.isLoopback();

        //Sent to many
        qInfo() << "\t Multicast: " << address.isMulticast();

        switch (address.protocol()){
        case QAbstractSocket::UnknownNetworkLayerProtocol:
            qInfo() << "\t Protocol: Unknown";
            break;
        case QAbstractSocket::AnyIPProtocol:
            qInfo() << "\t Protocol: Any";
            break;
        case QAbstractSocket::IPv4Protocol:
            qInfo() << "\t Protocol: IPV4";
            break;
        case QAbstractSocket::IPv6Protocol:
            qInfo() << "\t Protocol: IPV6";
            break;
        }
    }

    return a.exec();
}
