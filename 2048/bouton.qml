import QtQuick 2.0

Item {
    property alias valeurText: texteBouton.text
    property alias action: mouseArea
    property alias couleur: rectangle.color
    //property alias action: mouseArea.onClicked
    width: 110
    height: 50

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: vueGame.templateQML[3]
        radius: 3
        border.width: 0

        Text {
            id: texteBouton
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family:vueGame.templateQML[6]
            wrapMode: Text.Wrap
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
        }
    }
}
