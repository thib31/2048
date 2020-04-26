import QtQuick 2.0

Item {
    property alias valeurText: texteBouton.text
    property alias action: mouseArea
    //property alias action: mouseArea.onClicked
    width: 110
    height: 50

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: vueGame.templateQML[0]

        Text {
            id: texteBouton
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
        }
    }
}
