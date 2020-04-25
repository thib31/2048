import QtQuick 2.0

Item {
    width: 110
    height: 50
    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: "#dddddd"

        Text {
            id: texteBouton
            anchors.fill: parent
            text: qsTr("text")
        }


        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: vueGame.deplacement(1,0)
        }
    }
}
