#include "client.h"

Client::Client(QObject *parent) : QObject(parent), connectStatus(0) {

}

int Client::connect() {
    if (!connectStatus) {
        socket = new QTcpSocket();
        socket->connectToHost("localhost", 41017);

        QObject::connect(socket, SIGNAL(connected()), this, SLOT(connected()));
        QObject::connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error(QAbstractSocket::SocketError)));
        QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    }

    return 0;
}

int Client::sendMessage(QString _message) const {
    if (socket->isOpen()) {
//        QByteArray data = _message.toUtf8();
//        socket->write(data);
        QDataStream out(socket);
        out << _message.toUtf8();
    }
    return 0;
}

void Client::connected() {
    qDebug() << "Соединение установлено";
    connectStatus = 1;

    QString name = "Nizam";
    QDataStream io(socket);
    io.setVersion(QDataStream::Qt_5_8);
    io << static_cast<quint8>(MessageType::sendId) << static_cast<quint8>(name.size()) << name.toUtf8();
}

void Client::error(QAbstractSocket::SocketError) {
    qDebug() << "Ошибка установки соединения";
}

void Client::disconnected() {
    qDebug() << "Соединение разорвано";
    connectStatus = 0;
}
