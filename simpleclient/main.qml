import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

Window {
    width: client.windowWidth
    height: client.windowHeight
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        anchors.fill: parent
        TextArea {
            text: client.receivedFromSever
        }
    }
}
