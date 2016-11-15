import QtQuick 2.7
import QtQuick.Controls 1.4

Item {
    width: 800
    height: 600
    Image {
        id: image1
        x: 38
        y: -12
        width: 724
        height: 586
        fillMode: Image.PreserveAspectFit
        source: "welcomePic.png"
    }
    Button {
        x: 688
        y: 548
        text: "I know"
        isDefault: true
        checkable: true
        onClicked: welcomeDialog.close()
    }

    Text {
        id: text1
        x: 8
        y: 92
        text: qsTr("Welcome")
        font.pixelSize: 16
    }

    Text {
        id: text2
        x: 8
        y: 152
        text: qsTr("Open File")
        font.pixelSize: 16
    }

    Text {
        id: text3
        x: 16
        y: 211
        text: qsTr("Setting")
        font.pixelSize: 16
    }

    Text {
        id: text4
        x: 25
        y: 272
        text: qsTr("Help")
        font.pixelSize: 16
    }

    Text {
        id: text5
        x: 358
        y: 538
        text: qsTr("Highlight Scheme")
        font.pixelSize: 16
    }

    Text {
        id: text6
        x: 533
        y: 538
        text: qsTr("Font Size Selection")
        font.pixelSize: 16
    }

}
