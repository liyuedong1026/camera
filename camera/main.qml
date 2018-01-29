import QtQuick 2.2
import QtQuick.Controls 1.1
import MainScreen 1.0

ApplicationWindow {
    id:camera
    visible: true
    width: 640
    height: 480
    title: qsTr("Test")
    color: "red"

    menuBar: MenuBar {
        Menu {
            id: file
            objectName: "File"
            title: qsTr("File")

            MenuItem {
                id: exit
                objectName: "Exit"
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    MainScreen {
        anchors.fill: parent
        id: mainscreen1
        objectName: "mainscreen"
    }

    Button {
         id: opencamera
         objectName: "open"
         text: qsTr("open")
         x: 100
         y: 0
     }

     Button {
         id: capture
         objectName: "capture"
         text: qsTr("capture")
         x: 200
         y: 0
     }

     Button {
         id: save
         objectName: "save"
         text: qsTr("save")
         x: 300
         y: 0
     }

     Label {
         id: showcamera
         objectName: "showcamera"
         text: qsTr("showcamera")
         x: 200
         y: 200
         width: 200
         height: 200
         color: "blue"
     }
}
