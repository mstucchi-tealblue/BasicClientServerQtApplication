#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QLocalSocket>
#include <QDataStream>
#include <QTimer>
#include <typeinfo>


class client : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString receivedFromSever READ getReceivedFromServer WRITE setReceivedFromServer NOTIFY receivedFromServerChanged)
    Q_PROPERTY(int windowHeight READ getWindowHeight WRITE setWindowHeight NOTIFY windowHeightChanged)
    Q_PROPERTY(int windowWidth READ getWindowWidth WRITE setWindowWidth NOTIFY windowWidthChanged)

public:
    explicit client(QObject *parent = nullptr);

    QString getReceivedFromServer() ;
    void setReceivedFromServer(QString fromServer) ;

    qint64 getWindowHeight() const;
    void setWindowHeight(const qint64 &value);

    qint64 getWindowWidth() const;
    void setWindowWidth(const qint64 &value);

signals:
    void receivedFromServerChanged();
    void windowHeightChanged();
    void windowWidthChanged();

public slots:
    void readWelcome();

private:
    QLocalSocket *socket;
    QString receivedFromSever;
    qint64 windowHeight = 480;
    qint64 windowWidth = 640;

};

#endif // CLIENT_H
