import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

Window {
    width: 200
    height: 150
    visible: true
    title: qsTr("Hello World")

    Button {
        id: sendHello
        text: "send hello to client";
        onClicked: server.sendHello()

    }
}
