import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import trafficlight.controller.backend 1.0
import broadcast.receiver.backend 1.0

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Traffic Lights Controler")
    property int lightWidth: 150
    property int lightHeight: 150
    property bool redLightIsOn: controller.redSwitch
    property bool greenLightIsOn: controller.greenSwitch
    property bool yellowLightIsOn: controller.yellowSwitch
    TrafficLightsController{
        id: controller
    }

    BroadcastReceiver{
        id:receiver
    }

    Rectangle{
        id:lightBg
        anchors { horizontalCenter: parent.horizontalCenter; top: parent.top;}
        color:"black"
        height:200
        width:600
        Rectangle {
             id:redLight
             anchors {left: parent.left; leftMargin: 50; verticalCenter: parent.verticalCenter}
             width:lightWidth
             height: lightHeight
             color: redLightIsOn?"red":"black"
             border.color: "Red"
             border.width: 1
             radius: width*0.5
        }
        Rectangle {
             id:yellowLight
             anchors {horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter}
             width:lightWidth
             height: lightHeight
             color: yellowLightIsOn?"Yellow":"black"
             border.color: "Yellow"
             border.width: 1
             radius: width*0.5
        }
        Rectangle {
             id:blueLight
             anchors {right: parent.right; rightMargin: 50; verticalCenter: parent.verticalCenter}
             width:lightWidth
             height: lightHeight
             color: greenLightIsOn?"Green":"black"
             border.color: "Green"
             border.width: 1
             radius: width*0.5
        }
    }
    RowLayout{
        id:btnLayout
        anchors{bottom: parent.bottom; bottomMargin: 100; horizontalCenter: parent.horizontalCenter}
//        Button {
//            text: "Start"
//            onClicked:controller.lightControler(true);
//        }
//        Button {
//            text: "Stop"
//            onClicked:controller.lightControler(false);
//        }
        Button {
            text: "Connect"
            onClicked: receiver.processPendingDatagrams();
        }
        Button {
            text: "Quit"
            onClicked: mainWindow.close();
        }
    }
    Text {
        id: datagram
        anchors{bottom:parent.bottom}
        text: qsTr("Received Msg: "+receiver.datagram)
    }
}
