import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQuick.LocalStorage 2.0
import Qt.labs.folderlistmodel 2.1
import QtQuick.Dialogs 1.2
import local.nicolasien.editorlac 1.0

ApplicationWindow {
    id: applicationWindow
    visible: true
    minimumWidth: 640
    minimumHeight: 480
    width: 1024
    height: 768
    title: tabDocument.documentTitle + qsTr(" - Editor for Language AC")

    DocumentHandler {
        id: tabDocument
        target: codeText
        Component.onCompleted: {

            tabDocument.fileUrl = "qrc:/factorielle.lac"
            //synHandler.targetLang = languageIndicator.currentText
        }
    }

    Action {
        id: noAction
        onTriggered: errorDialog.open()
    }

    Action {
        id: welcomeAction
        onTriggered: welcomeDialog.open()
    }

    Action {
        id: openHelpPage
        shortcut: StandardKey.HelpContents
        onTriggered: Qt.openUrlExternally("https://github.com/nicolasying/Editor-L_AC")
    }

    Action {
        id: copyAction
        text: "&Copy"
        shortcut: StandardKey.Copy
        iconName: "edit-copy"
        enabled: (!!activeFocusItem && !!activeFocusItem["copy"])
        onTriggered: activeFocusItem.copy()
    }

    Action {
        id: cutAction
        text: "Cu&t"
        shortcut: StandardKey.Cut
        iconName: "edit-cut"
        enabled: (!!activeFocusItem && !!activeFocusItem["cut"])
        onTriggered: activeFocusItem.cut()
    }

    Action {
        id: pasteAction
        text: "&Paste"
        shortcut: StandardKey.Paste
        iconName: "edit-paste"
        enabled: (!!activeFocusItem && !!activeFocusItem["paste"])
        onTriggered: activeFocusItem.paste()
    }

    Action {
        id: enlargeCode
        shortcut: "Ctrl+="
        onTriggered: fontSizer.value = fontSizer.value + 1
    }


    Action {
        id: ensmallCode
        shortcut: "Ctrl+-"
        onTriggered: fontSizer.value = fontSizer.value - 1
    }

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem {
                text: "Open..."
                shortcut: StandardKey.Open
                onTriggered: {
                    fileDialog.selectExisting = true
                    fileDialog.open()
                }
            }
            MenuItem {
                text: "New..."
                shortcut: "Ctrl+N"
                onTriggered: {
                    tabDocument.fileUrl = "";
                }
            }
            MenuSeparator {
            }
            MenuItem {
                text: "Save"
                shortcut: StandardKey.Save
            }
            MenuItem {
                text: "Save as..."
                shortcut: StandardKey.SaveAs
                onTriggered: {
                    fileDialog.selectExisting = false
                    fileDialog.open()
                }
            }
            MenuSeparator {
            }
//            MenuItem {
//                text: "Close Current Tab"
//                action: closeTabAction
//            }
            MenuItem {
                text: "Close All Tabs"
                shortcut: StandardKey.Close
            }
        }

        Menu {
            title: "Edit"
            MenuItem {
                text: "Cut"
                action: cutAction
            }
            MenuItem {
                text: "Copy"
                action: copyAction
            }

            MenuItem {
                text: "Paste"
                action: pasteAction
            }
        }
        Menu {
            title: "Help"
            MenuItem {
                text: "Go to source page"
                action: openHelpPage
            }
        }
    }


    FileDialog {
        id: fileDialog
        nameFilters: ["LAC files (*.lac)", "Text files (*.txt)", "All files (*)"]
        onAccepted: {
            if (fileDialog.selectExisting)
                tabDocument.fileUrl = fileUrl
            else
                tabDocument.saveAs(fileUrl, selectedNameFilter)
        }
    }

    MessageDialog {
        id: errorDialog
        title: "Under construction"
        icon: StandardIcon.Information
        text: "Under construction"
        informativeText: "Wait for the next build.\nOr Purchase a beta membership.\nContact ban.elliott@gmail.com"
        standardButtons: StandardButton.Help | StandardButton.Ok
        onHelp: Qt.openUrlExternally("https://github.com/nicolasying/Editor-L_AC")
    }

    Dialog {
        id: welcomeDialog
        title: "A few essentials"
        width: 800
        height: 600
        contentItem: WelcomeDialog {

        }

    }

    ExclusiveGroup {
        id: functionalityBarButtons
    }

    Item {
        id: mainWindow
        anchors.bottom: statusBar.top
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottomMargin: 0
        anchors.topMargin: 0
        anchors.leftMargin: 0
        anchors.rightMargin: 0

        Rectangle{
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.topMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.rightMargin: 0

            color: "#263238"

        }

        ToolBar {
            id: functionalityBar
            width: 60
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            visible: true
            transformOrigin: Item.TopLeft
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0

            style: ToolBarStyle {
                background: Rectangle {
                    color: "#37474F"
                }
            }

            FunctionalityButton {
                id: welcomeButton
                y: 30
                anchors.leftMargin: 0
                iconSVG: "icons/welcome.svg"
                buttonAction: welcomeAction
            }
            FunctionalityButton {
                id: editButton
                y: 90
                anchors.leftMargin: 0
                iconSVG: "icons/edit.svg"
                anchorstop: welcomeButton.bottom
                buttonAction: Action {
                    onTriggered: {
                        fileDialog.selectExisting = true
                        fileDialog.open()
                    }
                }
            }
            FunctionalityButton {
                id: helpButton
                y: 210
                anchors.leftMargin: 0
                anchorstop: editButton.bottom
                iconSVG: "icons/help.svg"
                buttonAction: openHelpPage
            }
            FunctionalityButton {
                id: settingsButton
                y: 150
                anchors.leftMargin: 0
                anchorstop: helpButton.bottom
                iconSVG: "icons/settings.svg"
                buttonAction: noAction
            }
        }
        Rectangle {
                  id: scrollbar
                  anchors.right: flick.right
                  y: flick.visibleArea.yPosition * flick.height
                  width: 10
                  height: flick.visibleArea.heightRatio * flick.height
                  color: "#546E7A"
              }
        Flickable {
            id: flick

            width: parent.width
            height: parent.height
            contentWidth: codeText.paintedWidth
            contentHeight: codeText.paintedHeight
            clip: true
            //flickableDirection: Flickable.VerticalFlick

            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.left: functionalityBar.right
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0

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
            Label {
                id: textEnum
                visible: true
                width: 40
                text: popup()
                horizontalAlignment: Text.AlignRight
                font.pointSize: fontSizer.value
                font.family: "Menlo"
                font.weight: Font.Thin
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.top: parent.top
                anchors.topMargin: 0
                color: "#90A4AE"

                function popup (){
                    var text = ""
                    for (var i = 1; i <= codeText.lineCount; i++) text += (i + "\n")
                    return text
                }
            }

            TextEdit {
                id: codeText
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.left: textEnum.right
                anchors.leftMargin: 10
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0

                text: tabDocument.text
                objectName: "activeCodeText"

                textMargin: 0
                wrapMode: TextEdit.NoWrap

                selectionColor: "#78909C"
                color: "#FFFFFF"
                selectedTextColor: "#CFD8DC"


                font.pointSize: fontSizer.value
                font.family: "Menlo"
                selectByKeyboard: true
                selectByMouse: true

                activeFocusOnPress: true
                activeFocusOnTab: true
                onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)
                Component.onCompleted: {
                    forceActiveFocus()

                }

            }//textEdit
        }//flicker

    }
    StatusBar {
        id: statusBar
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        height: 30
        RowLayout {
            anchors.fill: parent

            Label {
                id: positionCounter
                text: "#Line: "+ codeText.lineCount + ", Current Pos: " +codeText.cursorPosition
                font.pointSize: 12
                //checkable: false
                //flat: true
                height: 20
            }
            ComboBox {
                id: languageIndicator

                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                anchors.right: fontSizeLable.left
                anchors.rightMargin: 70
                model: ["Language AC", "C"]

                height: 20
                implicitWidth: 100
                onCurrentIndexChanged: synHandler.targetLang = languageIndicator.currentText

            }



            Label {
                id: fontSizeLable
                text: "Font Size: "
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                anchors.right: fontSizer.left
                anchors.rightMargin: 10

                font.pointSize: 12
                height: 20
            }

            SpinBox {
                id: fontSizer
                anchors.right: parent.right
                anchors.rightMargin: 10

                Layout.fillHeight: true
                transformOrigin: Item.Center
                Layout.maximumWidth: 100
                Layout.minimumWidth: 30
                Layout.alignment: Qt.AlignVCenter
                implicitWidth: 100
                implicitHeight: 10
                value: 14
                stepSize: 1
                maximumValue: 30
                minimumValue: 6
                style:  SpinBoxStyle {
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 10
                        border.color: "gray"
                        radius: 2
                    }
                }
            }
        }
    }
    HighliterHandler {
        id: synHandler
    }
}

