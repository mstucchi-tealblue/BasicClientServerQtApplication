#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QLocalServer>
#include <QLocalSocket>
#include <QDataStream>
#include <string>

class server : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int windowHeight READ getWindowHeight WRITE setWindowHeight NOTIFY windowHeightChanged)
    Q_PROPERTY(int windowWidth READ getWindowWidth WRITE setWindowWidth NOTIFY windowWidthChanged)

public:
    explicit server(QObject *parent = nullptr);
    void heightChangedHandler(int height);
    void widthChangedHandler(int width);

    qint64 getWindowHeight() const;
    void setWindowHeight(qint64 value);

    qint64 getWindowWidth() const;
    void setWindowWidth(qint64 value);

signals:
    void windowHeightChanged();
    void windowWidthChanged();

public slots:
    void sendWelcome();
    void sendHello();


private:
    QLocalServer *mServer;
    QLocalSocket *clientConnection;
    qint64 windowHeight = 0;
    qint64 windowWidth = 0;

};

#endif // SERVER_H
