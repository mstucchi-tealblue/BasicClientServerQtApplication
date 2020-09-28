#include "client.h"

client::client(QObject *parent) : QObject(parent)
{
    // connect(getFortuneButton, &QPushButton::clicked,this, &Client::requestNewFortune);
    socket = new QLocalSocket(this);
    connect(socket, &QLocalSocket::readyRead, this, &client::readWelcome);

    socket->connectToServer("ServerName");
}


void client::readWelcome()
{
    setReceivedFromServer(socket->readAll());
    qDebug() << receivedFromSever;
}

qint64 client::getWindowWidth() const
{
    return windowWidth;
}

void client::setWindowWidth(const qint64 &value)
{
    windowWidth = value;
    emit windowWidthChanged();
}

qint64 client::getWindowHeight() const
{
    return windowHeight;
}

void client::setWindowHeight(const qint64 &value)
{
    windowHeight = value;
    emit windowHeightChanged();
}

QString client::getReceivedFromServer()
{
    return receivedFromSever;
}

void client::setReceivedFromServer(QString fromServer)
{
    qDebug() << typeid(fromServer).name();

    //if(fromServer.length()>=1 && fromServer.length()<=3)
    if(fromServer.at(0) == "h")
    {
        fromServer.remove(0,1);
        setWindowHeight(fromServer.toInt());
        return;
    }

    if(fromServer.at(0) == "w")
    {
        fromServer.remove(0,1);
        setWindowWidth(fromServer.toInt());
        return;
    }

    if (fromServer != receivedFromSever) {
        receivedFromSever = fromServer;
        emit receivedFromServerChanged();
    }
}




