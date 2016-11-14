import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQuick.LocalStorage 2.0
import Qt.labs.folderlistmodel 2.1
import QtQuick.Dialogs 1.2
//import local.nicolasien.editorlac 1.0

//Tab {
//    id: tab1
//    width: 150

//    title: tabDocument.documentTitle
//    anchors.left: parent.left
//    anchors.leftMargin: 0
//    anchors.fill: parent
//    onFocusChanged: {
//        activeCodeText = codeText
//    }



Item {
    id: firstTab
    anchors.right: parent.right
    anchors.rightMargin: 0
    anchors.left: parent.left
    anchors.leftMargin: 0
    anchors.bottom: parent.bottom
    anchors.bottomMargin: 0
    anchors.top: parent.top
    anchors.topMargin: 0
    Flickable {
        id: flick

        width: parent.width
        height: parent.height
        contentWidth: codeText.paintedWidth
        contentHeight: codeText.paintedHeight
        clip: true

        function ensureVisible(r)
        {
            if (contentX >= r.x)
                contentX = r.x;
            else if (contentX+width <= r.x+r.width)
                contentX = r.x+r.width-width;
            if (contentY >= r.y)
                contentY = r.y;
            else if (contentY+height <= r.y+r.height)
                contentY = r.y+r.height-height;
        }

        TextField {
            id: textEnum
            visible: false
            width: 30

            font.pointSize: 14
            font.family: "Menlo"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
        }
        TextEdit {
            id: codeText

            objectName: "activeCodeText"

            width: flick.width
            height: flick.height
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: textEnum.right
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            textMargin: 0
            wrapMode: TextEdit.NoWrap

            selectionColor: "#78909C"
            color: "#FFFFFF"
            selectedTextColor: "#CFD8DC"


            font.pointSize: 14
            font.family: "Menlo"
            selectByKeyboard: true
            selectByMouse: true

            activeFocusOnPress: true
            activeFocusOnTab: true
            onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)
            Component.onCompleted: forceActiveFocus()
        }

    }
}
//}

