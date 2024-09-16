import QtQuick 2.6
import QtQuick.Window 2.2

import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Window{
    id: secretMenu
    visible: false
    width: 300
    height: 200
    title: "Secret Menu"
    color: "lightgrey"

    Text {
        id: secretMenuText
        text: "Секретное меню"
        anchors.centerIn: parent
        font.pointSize: 20
    }

    Button {
        text: "Назад"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        onClicked: {
            secretMenu.visible = false; // Закрытие меню
        }
    }

    Connections {
            target: view
            onSecretWindowOpened: {
                 secretMenu.visible = true;
            }
        }
}
