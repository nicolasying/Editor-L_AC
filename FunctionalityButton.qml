import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtGraphicalEffects 1.0

Item {
    height: 48
    width:  parent.width


    property string baseColor: "#FFFFFF"
    property var id: functionalityBarButtons
    property string iconSVG: "icons/settings.svg"
    property var anchorstop: parent.top
    property var buttonAction

    ToolButton {
        anchors.fill:parent
        checkable: true
        exclusiveGroup: functionalityBarButtons
        transformOrigin: Item.TopLeft
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.topMargin: 0
        isDefault: false
        action: buttonAction
        style: ButtonStyle {
            background: Rectangle {
                id: background
                anchors.fill: parent

                Rectangle {
                    id: innerBackground
                    anchors.fill: parent
                    height: 60
                    width: 60
                    anchors.centerIn: parent
                    color : control.pressed ? "#546E7A" : "#37474F"
                }

                Rectangle {
                    id: iconFill
                    visible: false
                    anchors.centerIn: parent
                    height: 40
                    width: 40
                    color: control.pressed ? "#ECEFF1" : "#78909C"
                }

                Image {
                    id: icon
                    visible: false
                    anchors.fill: iconFill
                    source: iconSVG
                }

                OpacityMask {
                    anchors.fill: iconFill
                    source: iconFill
                    maskSource: icon
                }

                Canvas {
                    id: highlight
                    anchors.fill: innerBackground

                    contextType: "2d"

                    opacity: control.pressed ? 0.1 : 0.2
                }

            }
        }
    }
}
