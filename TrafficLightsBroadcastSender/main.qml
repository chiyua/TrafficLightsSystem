import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import sender.backend 1.0

Window {
    id:mainWindow
    width: Screen.width
    height: Screen.height
    visible: true
    title: qsTr("Traffic Lights Broadcast Sender")
    Sender{
        id:sender
    }
    Text {
        id: statusLabel
        anchors{verticalCenter: parent.verticalCenter;horizontalCenter: parent.horizontalCenter;}
        text: qsTr("Ready to broadcast datagrams on port 45454")
    }
    Button{
        anchors{bottom: parent.bottom; bottomMargin: parent.height*0.2; left: parent.left; leftMargin: parent.width*0.4;}
        id:startBtn
        text: "Start"
        onClicked: {sender.broadcastDatagram();}
    }
    Button{
        anchors{bottom: parent.bottom; bottomMargin: parent.height*0.2; left: parent.left; leftMargin: parent.width*0.6;}
        id:quitBtn
        text: "Quit"
        onClicked: {mainWindow.close()}
    }
}
