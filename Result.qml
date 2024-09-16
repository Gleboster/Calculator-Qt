import QtQuick 2.6
import QtQuick.Window 2.2

import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Rectangle {
    id: result
    
    x: 39
    y: 106

    width: 281
    height: 60
    
    color: "#04BFAD"
    
    property alias text: textResult.text

    Body_1 {
        id: textResult
        text: "123456789"
    }
}
