import QtQuick 2.7
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
    title: qsTr("Editor for Language AC")

    DocumentHandler {
        id: tabDocument
        Component.onCompleted: tabDocument.fileUrl = "qrc:/factorielle.lac"
    }

    Action {
        id: newTabAction
        shortcut: "ctrl+T"
        onTriggered: {
            fileTabs.addTab("New File", Qt.createComponent("/CodeTab.qml"));
            fileTabs.getTab(fileTabs.count - 1).active = true;
            //_Highlighters.newTabCreated("codeText")
        }
    }

    Action {
        id: closeTabAction
        shortcut: "ctrl+W"
        onTriggered: fileTabs.removeTab(fileTabs.currentIndex)
    }

    Action {
        id: noAction
        onTriggered: errorDialog.open()
    }

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem {
                text: "Open..."
                shortcut: "Ctrl+O"
                onTriggered: {
                    fileDialog.selectExisting = true
                    fileDialog.open()
                }
            }
            MenuItem {
                text: "Save"
                shortcut: "Ctrl+S"
            }
            MenuItem {
                text: "Save as..."
                shortcut: "Ctrl+Shift+S"
                onTriggered: {
                    fileDialog.selectExisting = false
                    fileDialog.open()
                }
            }
            MenuSeparator {
            }
            MenuItem {
                text: "Close Current Tab"
                action: closeTabAction
            }
            MenuItem {
                text: "Close All Tabs"
                shortcut: "Ctrl+Alt+W"
            }
        }

        Menu {
            title: "Edit"
            MenuItem {
                text: "Cut"
                shortcut: "Ctrl+X"
            }
            MenuItem {
                text: "Copy"
                shortcut: "Ctrl+C"
            }

            MenuItem {
                text: "Paste"
                shortcut: "Ctrl+V"
            }
        }
    }

    FileDialog {
        id: fileDialog
        nameFilters: ["LAC files (*.lac)", "Text files (*.txt)", "All files (*)"]
        //        onAccepted: {
        //            if (fileDialog.selectExisting)
        //                document.fileUrl = fileUrl
        //            else
        //                document.saveAs(fileUrl, selectedNameFilter)
        //        }
    }

    MessageDialog {
        id: errorDialog
        title: "Under construction"
        text: "Wait for the next build."
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
                buttonAction: noAction
            }
            FunctionalityButton {
                id: editButton
                y: 90
                anchors.leftMargin: 0
                iconSVG: "icons/edit.svg"
                anchorstop: welcomeButton.bottom
                buttonAction: newTabAction
            }
            FunctionalityButton {
                id: helpButton
                y: 210
                anchors.leftMargin: 0
                anchorstop: editButton.bottom
                iconSVG: "icons/help.svg"
                buttonAction: noAction
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

        TabView {
            id: fileTabs
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.left: functionalityBar.right
            anchors.leftMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            style: TabViewStyle {
                frameOverlap: 1
                tab: Rectangle {
                    color: styleData.selected ? "#263238" : "#455A64"
                    implicitWidth: Math.max(text.width + 4, 80)
                    implicitHeight: 30
                    Text {
                        id: text
                        anchors.centerIn: parent
                        text: styleData.title
                        color: styleData.selected ? "#ECEFF1" : "#CFD8DC"
                    }
                    Rectangle {
                        visible: styleData.selected ? true : false
                        color: "#B0BEC5"
                        width: parent.width
                        height: 2
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 0
                    }
                }
                frame: Rectangle {
                    color: "#263238"
                }
            }

            TextEdit {
                id: codeText
                text: tabDocument.text
                objectName: "activeCodeText"
                width: 500
                height: 500
                //width: flick.width
                //height: flick.height
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.left: parent.left

                //anchors.left: textEnum.right
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
                //onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)
                Component.onCompleted: forceActiveFocus()
            }

            Component {
                id: tempComp
                CodeTab {

                }
            }
//            TextEdit {
//                objectName: "activeCodeText"
//                visible: true
//                anchors.left: parent.left
//                anchors.leftMargin: 0
//                anchors.top: parent.top
//                anchors.topMargin: 0
//                width: 500
//                height: 500
//            }

            Tab {
                title: "Any tab"
            }
        }
    }

    StatusBar {
        id: statusBar
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        height: 20
        RowLayout {
            anchors.fill: parent

            //            Label {
            //                id: positionCounter
            //                text: "#Line: "+ codeArea.lineCount + " Ln: " + codeArea.cursorPosition
            //                font.pointSize: 12
            //                //checkable: false
            //                //flat: true
            //                height: 20
            //            }
            Label {
                id: languageIndicator
                text: "Language AC"
                font.pointSize: 12
                //checkable: false
                //flat: true
                height: 20
            }

            Label {
                id: fontSizer
                text: "SIZE VARIABLE"
                font.pointSize: 12
                //checkable: false
                //flat: true
                height: 20
            }
        }
    }
}
