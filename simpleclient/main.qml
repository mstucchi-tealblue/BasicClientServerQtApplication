import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        anchors.fill: parent
        TextArea {
            //placeholderText: "Nothing yet"
            text: client.statusLabel
        }
    }
}
