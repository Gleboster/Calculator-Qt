import QtQuick 2.6
import QtQuick.Window 2.2

import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1





Window {
    visible: true
    width: 360
    height: 640
    title: "Calculator"

    //TODO красивше
    flags: Qt.Window | Qt.WindowTitleHint | Qt.WindowSystemMenuHint | Qt.WindowMinMaxButtonsHint | Qt.WindowCloseButtonHint

    minimumHeight: height
    maximumHeight: height
    minimumWidth: width
    maximumWidth: width

    BackCalculator {
        id: backCalculator
    }

    BackCalculation {
        id: backCalculation
    }

    TopToolBar {
        id: toolBar
    }

    CalculationLine {
        id: calculationLine
        text: ""
    }

    Result {
        id: result
        text: "0"
    }


    Connections {
            target: view
            onResultUpdated: {
                result.text = resultContent;
            }
            onCalculationLineUpdated: {
                calculationLine.text = calculationLineContent;
            }
        }


    ButtonsActions {
        id: buttonsActions
    }

    ButtonsSimple {
        id: buttonsSimple
    }

    CancelButton {
        id: cancel
    }
}
