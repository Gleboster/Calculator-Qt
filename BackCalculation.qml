import QtQuick 2.6
import QtQuick.Window 2.2

import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Rectangle {
    id: backCalculation
    
    anchors.top : toolBar.bottom
    
    width: parent.width
    height: 156
    
    color: "#04BFAD"
    
    radius: 25
    
    //Прямоугольник перекрывающий верхние скругление и стык
    Rectangle{
        width: parent.width
        height: parent.radius
        color: parent.color
        anchors.top: parent.top
    }
}
