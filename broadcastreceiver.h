#ifndef BROADCASTRECEIVER_H
#define BROADCASTRECEIVER_H

#include <QObject>
#include <qqml.h>
QT_BEGIN_NAMESPACE
class QUdpSocket;
QT_END_NAMESPACE

class BroadcastReceiver : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString datagram READ datagram WRITE setDatagram NOTIFY datagramIsChanged)
    QML_ELEMENT
public:
    explicit BroadcastReceiver(QObject *parent = nullptr);

signals:
    void datagramIsChanged();
public:
    Q_INVOKABLE void processPendingDatagrams();
    QString datagram(){return mDatagram;};
    void setDatagram(QString &datagram);
private:
    QUdpSocket *udpSocket = nullptr;
    QString mDatagram;

};

#endif // BROADCASTRECEIVER_H
