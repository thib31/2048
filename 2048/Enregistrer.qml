import QtQuick 2.0

Item {
    id:fenetre
    //height: 300
    //width: 645

    Rectangle {
        id: rectangle1

        color: "#94999999"
        anchors.fill: parent

        Rectangle {
            id: rectangle
            width: 350
            height: 250
            x: (parent.width-rectangle.width)/2
            y: (parent.height-rectangle.height)/2
            color: "#dddddd"

            Text {
                id: nomFenetre
                x: 0
                y: 27
                width: parent.width
                text: qsTr("Enregistrer la partie")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
            }

            Text {
                id: element
                x: 39
                y: 84
                height: 25
                verticalAlignment: Text.AlignVCenter
                text: qsTr("Nom :")
                font.pixelSize: 12
            }

            Rectangle {
                id: rectangle2
                x: 102
                y: element.y
                width: 205
                height: 25
                color: "#ffffff"
                border.color: "gray"
                border.width: 1

                TextInput {
                    id: textInput
                    anchors.fill: parent
                    anchors.margins: 4
                    text: "Nom"
                    font.pixelSize: 12
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Bouton {
                id: boutonEnreg
                x: 49
                y: 192
                valeurText: qsTr("Enregistrer")
                action.onClicked: {
                    if (vueGame.enregistrePartie(textInput.text,false)===0){
                        fenetre.visible=false
                    }
                    else{
                        enregForce.visible=true
                    }
                }
            }

            Bouton {
                id: boutonAnnulEnr
                x: 197
                y: boutonEnreg.y
                valeurText: qsTr("Annuler")
                action.onClicked: fenetre.visible=false
            }

        }

        Rectangle {
            id: enregForce
            color: "#94999999"
            anchors.fill: parent
            visible: false

            Rectangle {
                id: rectangle4
                width: 300
                height: 120
                x: (parent.width-width)/2
                y: (parent.height-height)/2
                color: "#dddddd"

                Text {
                    id: nomFenetre2
                    x: 0
                    y: 27
                    width: parent.width
                    text: qsTr("Un fichier portant ce nom existe déjà, voulez-vous continuer ?")
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignHCenter
                }
                Bouton {
                    id: boutonEnreg2
                    x: 49
                    y: 192
                    valeurText: qsTr("Oui")
                    action.onClicked: {
                        vueGame.enregistrePartie(textInput.text,true)
                        fenetre.visible=false
                        enregForce.visible=false
                    }
                }

                Bouton {
                    id: boutonAnnulEnr2
                    x: 197
                    y: boutonEnreg2.y
                    valeurText: qsTr("Non")
                    action.onClicked: enregForce.visible=false
                }
            }
        }
    }

}
