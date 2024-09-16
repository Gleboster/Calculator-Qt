import QtQuick 2.6
import QtQuick.Window 2.2

import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

CircleButton {
    property alias text: textButton.text
    property string colorTextDefault
    property string colorTextPressed: colorTextDefault

    onPressed: {
        buttonsController.handleSimpleButton(text);
    }

    Text {
        id: textButton
        anchors.centerIn: parent

        color: parent.containsPress ? colorTextPressed : colorTextDefault

        font.family: "Open Sans"
        font.weight: Font.DemiBold
        font.pixelSize: 24
        font.letterSpacing: 1
        
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    
    
}
