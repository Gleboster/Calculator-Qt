import QtQuick 2.6
import QtQuick.Window 2.2

import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Rectangle {
    id: buttonsSimple
    width: 228
    height: 312
    y: 288
    x: 24
    
    color: "#024873"
    
    ListModel {
        id: buttonsActionPlaces
        ListElement { relativeY: 1; relativeX: 1; text: "7"}
        ListElement { relativeY: 1; relativeX: 2; text: "8"}
        ListElement { relativeY: 1; relativeX: 3; text: "9"}
        ListElement { relativeY: 2; relativeX: 1; text: "4"}
        ListElement { relativeY: 2; relativeX: 2; text: "5"}
        ListElement { relativeY: 2; relativeX: 3; text: "6"}
        ListElement { relativeY: 3; relativeX: 1; text: "1"}
        ListElement { relativeY: 3; relativeX: 2; text: "2"}
        ListElement { relativeY: 3; relativeX: 3; text: "3"}
        ListElement { relativeY: 4; relativeX: 2; text: "0"}
        ListElement { relativeY: 4; relativeX: 3; text: "."}
    }
    
    ButtonsReplacer {
        id: buttonsSimpleReplacer
        model: buttonsActionPlaces
        delegate:
            SimpleButton{
            x: (model.relativeX - 1) * buttonsSimpleReplacer.stepXbyPx
            y: (model.relativeY - 1) * buttonsSimpleReplacer.stepYbyPx
            
            text: model.text
            
            colorBackgroundDefault: "#B0D1D8"
            colorBackgroundPressed: "#04BFAD"
            
            colorTextDefault: "#024873"
            colorTextPressed: "#FFFFFF"
        }
    }
}
