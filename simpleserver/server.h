#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QLocalServer>
#include <QLocalSocket>
#include <QDataStream>

class server : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int windowHeight READ getWindowHeight WRITE setWindowHeight NOTIFY windowHeightChanged)
public:
    explicit server(QObject *parent = nullptr);
    void heightChangedHandler(int height);

    qint64 getWindowHeight() const;
    void setWindowHeight(qint64 value);

signals:
    void windowHeightChanged();


public slots:
    void sendWelcome();
    void sendHello();


private:
    QLocalServer *mServer;
    QLocalSocket *clientConnection;
    qint64 windowHeight = 0;

};

#endif // SERVER_H
