#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QLocalSocket>
#include <QDataStream>
#include <QTimer>


class client : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString statusLabel READ getStatusLabel WRITE setStatusLabel NOTIFY statusLabelChanged)

public:
    explicit client(QObject *parent = nullptr);

    QString getStatusLabel() ;
    void setStatusLabel(const QString sl) ;

signals:
    void statusLabelChanged();

public slots:
    void readWelcome();

private:
    QLocalSocket *socket;
    QString statusLabel;

};

#endif // CLIENT_H
