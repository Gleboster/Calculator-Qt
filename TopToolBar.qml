import QtQuick 2.6
import QtQuick.Window 2.2

import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Rectangle {
    id: toolBar
    anchors.top: parent.top
    anchors.horizontalCenter: parent.horizontalCenter
    width: parent.width
    height: toolbarImage.paintedHeight * (parent.width / toolbarImage.paintedWidth)
    
    Image {
        id: toolbarImage
        source: "Assets/ToolBar.png"
        width: parent.width
        fillMode: Image.PreserveAspectFit
        asynchronous: true
    }
}
