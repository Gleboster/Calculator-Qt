import QtQuick 2.6
import QtQuick.Window 2.2

import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Rectangle {
    id: calculationLine
    
    x: 39
    y: 68
    
    width: 281
    height: 30
    
    color: "#04BFAD"
    
    property alias text: calculationLineText.text
    
    Body_2 {
        id: calculationLineText
    }
}
