import QtQuick 2.6
import QtQuick.Window 2.2

import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Rectangle
{
    property string colorBackgroundDefault
    property string colorBackgroundPressed: colorBackgroundDefault

    property alias containsPress: mouseArea.containsPress

    width: 60
    height: 60
    radius: width / 2

    color: colorBackgroundDefault
    
    signal clicked()
    signal pressed()

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true

        onEntered: {
            parent.color = Qt.darker(parent.colorBackgroundDefault, 1.2);
        }
        onExited: {
            parent.color = parent.colorBackgroundDefault;
            if (pressed)
                parent.clicked()
        }

        onPressed: {
            parent.color = parent.colorBackgroundPressed;
            parent.pressed();
        }

        onReleased: {
            parent.color = containsMouse ? Qt.darker(parent.colorBackgroundDefault, 1.2) : parent.colorBackgroundDefault;
        }

        onClicked: {
            parent.clicked();
        }
    }
}
