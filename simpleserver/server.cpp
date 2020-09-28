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

qint64 server::getWindowWidth() const
{
    return windowWidth;
}

void server::setWindowWidth(qint64 value)
{
    windowWidth = value;
    emit windowHeightChanged();
}

void server::heightChangedHandler(int height)
{
    setWindowHeight(height);

    QByteArray qByteHeight;
    QByteArray qBytePrefix;

    qByteHeight.setNum(height);
    qBytePrefix = "h";
    clientConnection->write(qBytePrefix + qByteHeight);
    clientConnection->flush();

}

void server::widthChangedHandler(int width)
{
    setWindowWidth(width);

    QByteArray qByteWidth;
    QByteArray qBytePrefix;

    qByteWidth.setNum(width);
    qBytePrefix = "w";
    clientConnection->write(qBytePrefix + qByteWidth);
    clientConnection->flush();
}

qint64 server::getWindowHeight() const
{
    qDebug() << "get went fine " ;
    return windowHeight;
}

void server::setWindowHeight(qint64 value)
{    
    if (value != windowHeight) {
        windowHeight = value;
        emit windowHeightChanged();
    }
}


