import QtQuick 2.0

Item {
    property alias valeurText: valeur.text
    property alias couleur: rectangle.color
    property int numero
    width: 50
    height: 50

    Rectangle {
        id: rectangle
        anchors.fill: parent
    }

    Text {
        id: valeur
        anchors.fill: parent
        font.family:vueGame.templateQML[6]
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 24
        focus: true
    }
}
