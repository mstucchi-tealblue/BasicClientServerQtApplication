#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QLocalServer>
#include <QLocalSocket>
#include <QDataStream>

class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = nullptr);

signals:

public slots:
    void sendWelcome();
    void sendHello();

private:
    QLocalServer *mServer;
    QLocalSocket *clientConnection;

};

#endif // SERVER_H
