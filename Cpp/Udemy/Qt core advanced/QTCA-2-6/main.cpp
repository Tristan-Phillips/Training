#include <QCoreApplication>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    //client.connectToHost("www.tristanphillips.dev",80); //Not Encrypted port 80 is normal HTTP
    //Port 443 is standard for Ssl
    client.connectToHost("httpbin.org",443);

    return a.exec();
}
