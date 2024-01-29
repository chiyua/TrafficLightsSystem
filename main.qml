import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Traffic Lights Controler")
    property int lightWidth: 150
    property int lightHeight: 150
    property bool redLightIsOn: false
    property bool greenLightIsOn: false
    property bool yellowLightIsOn: false
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
        Button {
            text: "Connect"
            onClicked: model.submit()
        }
        Button {
            text: "Disconnect"
            onClicked: model.revert()
        }
        Button {
            text: "Send"
            onClicked: model.submit()
        }
    }

}
