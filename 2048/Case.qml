import QtQuick 2.0

Item {
    property alias valeurText: valeur.text
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 50
        height: 50
        color: "#ffffff"
    }

    Text {
        id: valeur
        x: 0
        y: 0
        width: 50
        height: 50
        font.family: "Tahoma"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 24
        focus: true
    }

}
