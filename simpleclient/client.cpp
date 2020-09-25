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
    setStatusLabel(socket->readAll());
    qDebug() << statusLabel;
}

QString client::getStatusLabel()
{
    qDebug() << "Call get went fine";
    return statusLabel;
}

void client::setStatusLabel(const QString sl)
{
    if (sl != statusLabel) {
        statusLabel = sl;
        emit statusLabelChanged();
    }
}




