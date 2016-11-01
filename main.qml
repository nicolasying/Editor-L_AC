import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.0
import QtQuick.LocalStorage 2.0
import Qt.labs.folderlistmodel 2.1

ApplicationWindow {
    id: applicationWindow
    visible: true
    minimumWidth: 640
    minimumHeight: 480
    width: 1024
    height: 768

    Material.theme: Material.Dark
    Material.accent: Material.Teal
    Material.primary: Material.BlueGrey

    title: qsTr("Editor for Language AC")

    ButtonGroup { buttons: functionalityBar.children }

    ToolBar {
        id: functionalityBar
        width: 60
        height: parent.height
        visible: true
        transformOrigin: Item.TopLeft
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        hoverEnabled: false

        ToolButton {
            id: welcomeButton
            width: parent.width
            x: 40
            text: qsTr("Welcome")
            transformOrigin: Item.TopLeft
            highlighted: false
            anchors.top: parent.top
            anchors.topMargin: 20
            autoExclusive: true
            checkable: true
            anchors.left: parent.left
            anchors.leftMargin: 0
            height: 30
        }

        ToolButton {
            id: editorButton
            width: parent.width
            text: qsTr("Edit")
            checkable: true
            autoExclusive: true
            transformOrigin: Item.TopLeft
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: welcomeButton.bottom
            anchors.topMargin: 0
            height: 30
        }

        ToolButton {
            id: helpButton
            width: parent.width
            text: qsTr("Help")
            autoExclusive: true
            checkable: true
            transformOrigin: Item.TopLeft
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: editorButton.bottom
            anchors.topMargin: 0
            height: 30
        }


        ToolButton {
            id: settingsButton
            width: parent.width
            text: qsTr("Settings")
            checkable: true
            autoExclusive: true
            transformOrigin: Item.TopLeft
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: helpButton.bottom
            anchors.topMargin: 30
            height: 30
        }
    }
    TabBar {
        id: fileTabs
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: functionalityBar.right
        anchors.leftMargin: 0
        height: 40

        TabButton {
            id: tab1Button
            width: 100
            text: qsTr("File Var")
            anchors.left: parent.left
            anchors.leftMargin: 0
        }
        TabButton {
            id: tab2Button
            width: 40
            text: qsTr("+")
            anchors.left: tab1Button.right
            anchors.leftMargin: 0
        }
    }

    StackView {
        id: fileViews
        anchors.left: functionalityBar.right
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: fileTabs.bottom
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        Item {
            id: initialTab
            anchors.fill: parent


        }

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
                id: codeContainer
                contentWidth: parent.width
                anchors.fill: parent
                ScrollBar.vertical: ScrollBar {
                    active: true
                }
                ScrollBar.horizontal: ScrollBar {
                    active: false
                }

                TextArea.flickable: TextArea {
                    wrapMode: TextArea.Wrap
                    id: codeArea
                    text: qsTr("Begin coding.")
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 0
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.top: parent.top
                    anchors.topMargin: 0
                    leftPadding: 30
                    topPadding: 30
                    font.pointSize: 12
                    font.family: "Menlo"
                    selectByKeyboard: true
                    selectByMouse: true
                    selectionColor: Material.primary
                    textFormat: "RichText"
                    activeFocusOnPress: true
                    activeFocusOnTab: true
                    //textDocument.objectName:

                }
            }

        }
    }

    footer : Row {
        topPadding: 5
        spacing: 5


        Button {
            id: positionCounter
            text: "#Line: "+ codeArea.lineCount + " Ln: " + codeArea.cursorPosition
            font.pointSize: 12
            checkable: false
            flat: true
            height: 20
        }

        Button {
            id: languageIndicator
            text: "Language AC"
            font.pointSize: 12
            checkable: false
            flat: true
            height: 20
        }

        Button {
            id: fontSizer
            text: "SIZE VARIABLE"
            font.pointSize: 12
            checkable: false
            flat: true
            height: 20
        }
        Rectangle {
            color: "#526463"
            width: parent.width
            height: 20
        }
    }
}
