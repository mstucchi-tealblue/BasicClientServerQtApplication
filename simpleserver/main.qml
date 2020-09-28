import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Window {
    width: 200
    height: 150
    visible: true
    title: qsTr("Hello World")

    ColumnLayout {
        RowLayout{
            Button {
                Layout.fillWidth : true
                Layout.fillHeight: true
                id: sendHello
                text: "send hello to client";
                onClicked: server.sendHello()
                }
        }

        RowLayout{
            Text {
                Layout.fillWidth : true
                Layout.fillHeight: true
                text: server.windowHeight
            }
        }
    }



}
