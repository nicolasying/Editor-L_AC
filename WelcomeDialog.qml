import QtQuick 2.5
import QtQuick.Controls 1.4

Item {
    width: 800
    height: 600
    Image {
        id: image1
        x: 68
        y: 0
        width: 724
        height: 586
        fillMode: Image.PreserveAspectFit
        source: "welcomePic.png"
    }
    Button {
        x: 700
        y: 564
        text: "I know"
        isDefault: true
        checkable: true
        onClicked: welcomeDialog.close()
    }

    Text {
        id: text1
        x: 28
        y: 104
        text: qsTr("Welcome")
        font.family: customizedFont.name
        font.pixelSize: 16
    }

    Text {
        id: text2
        x: 28
        y: 164
        text: qsTr("Open File")
        font.family: customizedFont.name
        font.pixelSize: 16
    }

    Text {
        id: text3
        x: 36
        y: 223
        text: qsTr("Setting")
        font.family: customizedFont.name
        font.pixelSize: 16
    }

    Text {
        id: text4
        x: 45
        y: 284
        text: qsTr("Help")
        font.family: customizedFont.name
        font.pixelSize: 16
    }

    Text {
        id: text5
        x: 398
        y: 544
        text: qsTr("Highlight Scheme")
        font.family: customizedFont.name
        font.pixelSize: 16
    }

    Text {
        id: text6
        x: 573
        y: 544
        text: qsTr("Font Size Selection")
        font.family: customizedFont.name
        font.pixelSize: 16
    }

}
