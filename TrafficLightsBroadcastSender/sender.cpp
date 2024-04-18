#include <QtNetwork>
#include "sender.h"

Sender::Sender(QObject *parent)
    : QObject{parent}
{
    udpSocket = new QUdpSocket(this);
}

void Sender::startBroadcasting()
{
//    timer.start(1000);
}

void Sender::broadcastDatagram()
{
//    QByteArray datagram = "Broadcast message " + QByteArray::number(messageNo);
    QByteArray datagram = "Broadcast msg: Red is on";
    udpSocket->writeDatagram(datagram, QHostAddress::Broadcast, 45454);
    qDebug()<<"Is broadcasting msg:"<<datagram;
//! [1]
//    ++messageNo;
}
