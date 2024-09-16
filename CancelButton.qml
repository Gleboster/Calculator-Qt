import QtQuick 2.6
import QtQuick.Window 2.2

import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

import ActionQMLEnums 1.1

ButtonAction {
    id: cancel
    actionType: Action.Cancel
    sourceActionImage: "qrc:/Assets/Cancel.png"

    x: 24
    y: 540
    
    colorBackgroundDefault: "#F8AEAE"
    colorBackgroundPressed: "#F25E5E"


}
