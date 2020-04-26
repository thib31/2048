import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
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
                id: element
                x: 0
                y:20
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                text: qsTr("Text")
                font.pixelSize: 12
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
                }
            }

            Bouton {
                id: boutonCharg
                x: parent.width/4-width/2
                y: 192
                valeurText: qsTr("Charger")
                couleur: vueGame.templateQML[4]
                action.onClicked: {
                    vueGame.chargePartie(vueGame.partiesQML[table.currentRow])
                    fenetreChargement.visible=false
                }
            }

            Bouton {
                id: boutonAnnulCha
                x: parent.width*3/4-width/2
                y: boutonCharg.y
                valeurText: qsTr("Annuler")
                action.onClicked: fenetreChargement.visible=false
            }
        }
    }
}
