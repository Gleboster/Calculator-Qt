import QtQuick 2.6
import QtQuick.Window 2.2

import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

import ActionQMLEnums 1.1

Rectangle {
    id: buttonsActions
    width: 312
    height: 396
    y: 204
    x: 24
    
    color: "#024873"
    
    ListModel {
        id: buttonsActionPlaces
        ListElement { relativeY: 1; relativeX: 1; actionType: Action.Brackets ; sourceImage: "Assets/Brackets.png" }
        ListElement { relativeY: 1; relativeX: 2; actionType: Action.ChangeSign; sourceImage: "Assets/ChangeSign.png" }
        ListElement { relativeY: 1; relativeX: 3; actionType: Action.Proccent; sourceImage: "Assets/Proccent.png" }
        ListElement { relativeY: 1; relativeX: 4; actionType: Action.Division;  sourceImage: "Assets/Division.png" }
        ListElement { relativeY: 2; relativeX: 4; actionType: Action.Multiple; sourceImage: "Assets/Multiple.png" }
        ListElement { relativeY: 3; relativeX: 4; actionType: Action.Minus; sourceImage: "Assets/Minus.png" }
        ListElement { relativeY: 4; relativeX: 4; actionType: Action.Plus; sourceImage: "Assets/Plus.png" }
        ListElement { relativeY: 5; relativeX: 4; actionType: Action.Equal; sourceImage: "Assets/Equal.png" }
    }
    
    ButtonsReplacer{
        id: buttonsActionReplacer

        model: buttonsActionPlaces
        delegate:
            ButtonAction {
            actionType: model.actionType

            x: (model.relativeX - 1) * buttonsActionReplacer.stepXbyPx
            y: (model.relativeY - 1) * buttonsActionReplacer.stepYbyPx
            sourceActionImage: model.sourceImage

            colorBackgroundDefault: "#0889A6"
            colorBackgroundPressed: "#F7E425"
        }
    }
}
