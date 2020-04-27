import QtQuick 2.0
// Petite différence par rapport à AfficheListe, la fenêtre de confirmation, lorsque le nom de partie est déjà utilisé.
// C'est elle qui fait appel au mode "écrasementé de la fonction enregistrePartie.

Item {
    property var taillePolice: 12

    id:fenetre
    //height: 300
    //width: 645

    Rectangle {
        id: rectangle1
        color: vueGame.templateQML[1]

        anchors.fill: parent

        Rectangle {
            id: rectangle
            width: 350
            height: 250
            x: (parent.width-width)/2
            y: (parent.height-height)/2
            color: vueGame.templateQML[0]

            Text {
                id: nomFenetre
                x: 0
                y: 27
                width: parent.width
                text: qsTr("Enregistrer la partie")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                font.family:vueGame.templateQML[6]
            }

            Text {
                id: element
                x: 39
                y: 84
                height: 25
                verticalAlignment: Text.AlignVCenter
                text: qsTr("Nom :")
                font.pixelSize: 12
                font.family:vueGame.templateQML[6]
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
                    font.pixelSize: 12
                    verticalAlignment: Text.AlignVCenter
                    font.family:vueGame.templateQML[6]
                }
            }

            Bouton {
                id: boutonEnreg
                x: parent.width/4-width/2
                y: 192
                valeurText: qsTr("Enregistrer")
                couleur: vueGame.templateQML[4]
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
                x: parent.width*3/4-width/2
                y: boutonEnreg.y
                valeurText: qsTr("Annuler")
                action.onClicked: fenetre.visible=false
            }

        }

        Rectangle {
            id: enregForce
            color: vueGame.templateQML[1]
            anchors.fill: parent
            visible: false

            Rectangle {
                id: rectangle4
                width: 300
                height: 120
                x: (parent.width-width)/2
                y: (parent.height-height)/2
                color: vueGame.templateQML[0]

                Text {
                    id: nomFenetre2
                    x: 0
                    y: 15
                    width: parent.width
                    text: qsTr("Un fichier portant ce nom existe déjà.\n Voulez-vous continuer ?")
                    font.bold: true
                    font.pixelSize: 14
                    font.family:vueGame.templateQML[6]
                    horizontalAlignment: Text.AlignHCenter
                }
                Bouton {
                    id: boutonEnreg2
                    x: parent.width/4-width/2
                    y: 62
                    valeurText: qsTr("Oui")
                    couleur: vueGame.templateQML[4]
                    action.onClicked: {
                        vueGame.enregistrePartie(textInput.text,true)
                        fenetre.visible=false
                        enregForce.visible=false
                    }
                }

                Bouton {
                    id: boutonAnnulEnr2
                    x: parent.width*3/4-width/2
                    y: boutonEnreg2.y
                    valeurText: qsTr("Non")
                    action.onClicked: enregForce.visible=false
                }
            }
        }
    }
}
