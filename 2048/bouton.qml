import QtQuick 2.0
// Pour plus de légèreté  dans le code, j'ai utilisé un seul type de bouton dans mon interface QML.
// Il est donc disponible, avec les alias nécessaires.
//      - valeurText pour la zone de texte présente dans le bouton
//      - mouseArea pour la commande
//      - couleur : définie par défaut, on peut cependant la changer (nuance rouge pour les boutons importants oar exemple)


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
            wrapMode: Text.Wrap                 // Renvoi à la ligne automatique. Utile avec la police Courier
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
        }
    }
}
