import QtQuick 2.6
import QtQuick.Window 2.2

import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

CircleButton{
    property string sourceActionImage
    property int actionType

    onClicked: {
        buttonsController.handleActionButtonUp(actionType)
    }

    onPressed: {
        buttonsController.handleActionButtonDown(actionType)
    }

    Image
    {
        source: parent.sourceActionImage
        anchors.fill: parent
        anchors.margins: 12
    }
}
