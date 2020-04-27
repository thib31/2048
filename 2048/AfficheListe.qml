import QtQuick 2.0
import QtQuick.Controls 1.4

// Cette fenetre affiche une liste de parties enregistrées. Elle permet d'en charger ou supprimer une.
// Pour plus de simplicité, j'ai fait une même fenêtre, avec des alias pour les fonctions et certaines zones de texte.
// Pour afficher la liste, j'ai utilisé TableViex, qui récupère les données dans une QStringList fournie par le C++
// Lors du clic sur le bouton (action définie dans main.qml), on exécute la fonction, et le nom de la partie
// est récupéré à l'aide de l'index de la ligne selectionnée.

// petit détail : j'ai trouvé comment changer la police des items de la liste, mais pas celle du nom de la colonne.

Item {
    property alias titre: titre.text
    property alias textebouton: boutonValid.valeurText
    property alias bouton: boutonValid.action
    property alias ligne: table.currentRow
    property alias affiche: fenetreChargement.visible
    id:fenetreChargement
    width: 645
    height: 480

    Rectangle {
        id:rectangle
        anchors.fill: parent
        color: vueGame.templateQML[1]

        Rectangle {
            id: rectangle1
            width: 350
            height: 250
            x: (parent.width-width)/2
            y: (parent.height-height)/2
            color: vueGame.templateQML[0]

            Text {
                id: titre
                x: 0
                y:20
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
                font.family:vueGame.templateQML[6]
            }


            Rectangle {
                id:rectangleTable
                width:200
                height: 140
                x:(parent.width-width)/2
                y:45


                TableView {
                    id: table
                    anchors.fill: parent
                    TableViewColumn {
                        title: "Nom de la partie"
                    }
                    model: vueGame.partiesQML
                    sortIndicatorOrder: Qt.AscendingOrder

                    itemDelegate: Item{
                        Text {
                            font.family:vueGame.templateQML[6]
                            elide: styleData.elideMode
                            text: styleData.value
                        }
                    }
                }
            }

            Bouton {
                id: boutonValid
                x: parent.width/4-width/2
                y: 192
                couleur: vueGame.templateQML[4]
            }

            Bouton {
                id: boutonAnnulCha
                x: parent.width*3/4-width/2
                y: boutonValid.y
                valeurText: qsTr("Annuler")
                action.onClicked: fenetreChargement.visible=false
            }
        }
    }
}
