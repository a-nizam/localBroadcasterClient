#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>
#include <QBuffer>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);

signals:

public slots:
    void connected();
    void error(QAbstractSocket::SocketError);
    void disconnected();

private:
    QTcpSocket *socket;
    int connectStatus;

public:
    int connect();
    int sendMessage(QString _message) const;

    enum MessageType { sendId };
};

#endif // CLIENT_H
