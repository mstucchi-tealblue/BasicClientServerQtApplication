#include "server.h"

server::server(QObject *parent) : QObject(parent)
{
    mServer = new QLocalServer(this);

    if (!mServer->listen("ServerName")) {
        qDebug() << "Server could not start!";
        qDebug() << mServer->errorString();
        return;

    } else {
        qDebug() << "Server started";
    }

    connect(mServer, &QLocalServer::newConnection, this, &server::sendWelcome);


}

void server::sendWelcome()
{
    clientConnection = mServer->nextPendingConnection();
//    connect(clientConnection, &QLocalSocket::disconnected,
//            clientConnection, &QLocalSocket::deleteLater);

    clientConnection->write("Welcome client");
    clientConnection->flush();

}

void server::sendHello()
{
    qDebug() << "sendHello is working";
    clientConnection->write("Hello client");
    clientConnection->flush();
}
