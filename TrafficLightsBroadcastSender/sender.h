#ifndef SENDER_H
#define SENDER_H

#include <QObject>
//#include <QTimer>

QT_BEGIN_NAMESPACE
class QUdpSocket;
QT_END_NAMESPACE

class Sender: public QObject
{
    Q_OBJECT
public:
    explicit Sender(QObject *parent = nullptr);
    Q_INVOKABLE void startBroadcasting();
    Q_INVOKABLE void broadcastDatagram();
    QUdpSocket *udpSocket = nullptr;
//    QTimer timer;
//    int messageNo = 1;
};

#endif // SENDER_H
