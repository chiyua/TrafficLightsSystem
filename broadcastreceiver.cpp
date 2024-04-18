#include <QUdpSocket>
#include "broadcastreceiver.h"

BroadcastReceiver::BroadcastReceiver(QObject *parent)
    : QObject{parent}
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(45454,QUdpSocket::ShareAddress);
}

void BroadcastReceiver::processPendingDatagrams()
{
    QByteArray msg;
    while (udpSocket->hasPendingDatagrams()){
        msg.resize(int (udpSocket->pendingDatagramSize()));
        udpSocket->readDatagram(msg.data(),msg.size());
        mDatagram=msg;
        qDebug()<<"Received data: "<<mDatagram;
        emit datagramIsChanged();
    }
//    qDebug()<<"Received data: "<<mDatagram;
}

void BroadcastReceiver::setDatagram(QString &datagram)
{
    if (datagram==mDatagram)
    {
        return;
    }
    datagram=mDatagram;
    emit datagramIsChanged();
}
