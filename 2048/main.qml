import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 645
    height: 360
    title: qsTr("2048")
    color: vueGame.templateQML[0]
    
    FocusScope {
        id: focusScope
        x: 0
        y: 0
        width: 100
        height: 100
        focus: vueGame.templateQML[5]
        Keys.onPressed: {
         switch (event.key) {
            case Qt.Key_Up:
                vueGame.deplacement(1,0);
                break;
            case Qt.Key_Down:
                vueGame.deplacement(-1,0);
                break;
            case Qt.Key_Left:
                vueGame.deplacement(0,1);
                break;
            case Qt.Key_Right:
                vueGame.deplacement(0,-1);
                break;
         }
        }
    }

    Damier {
        id:rectangle
        x: 210
        y: 40
    }

    Bouton {
        id: boutonPrecedent
        x: rectangle.x
        y: rectangle.y + rectangle.height+5
        action.onClicked: vueGame.precedent()
        valeurText: qsTr("Précédent")
    }

    Bouton {
        id: boutonSuivant
        x: rectangle.x + 115
        y: rectangle.y + rectangle.height+5
        action.onClicked: vueGame.suivant()
        valeurText: qsTr("Suivant")
    }

    Bouton {
        id: boutonNouvPartie
        x: rectangle.x + rectangle.width + 50
        y: rectangle.y +5
        action.onClicked: vueGame.nouvPartie()
        valeurText: qsTr("Nouvelle Partie")
    }

    Bouton {
        id: boutonEnregPartie
        x: rectangle.x + rectangle.width + 50
        y: rectangle.y +60
        action.onClicked: enregistrer.visible=true
        valeurText: qsTr("Enregistrer Partie")
    }

    Bouton {
        id: boutonChargerPartie
        x: rectangle.x + rectangle.width + 50
        y: rectangle.y +115
        action.onClicked: charger.visible=true
        valeurText: qsTr("Charger Partie")
    }

    Bouton {
        id: boutonSupprPartie
        x: rectangle.x + rectangle.width + 50
        y: rectangle.y +170
        action.onClicked: supprimer.visible=true
        valeurText: qsTr("Supprimer Partie")
    }

    Bouton {
        id: boutonPolice
        x: rectangle.x -50-110
        y: rectangle.y
        action.onClicked: police.visible=true
        valeurText: qsTr("Changer Police")
    }

    Enregistrer {
        id: enregistrer
        anchors.fill: parent
        visible: false
    }

    AfficheListe {
        id: charger
        anchors.fill: parent
        visible: false
        titre: "Charger une partie enregistrée"
        textebouton: "Charger"
        bouton.onClicked: {
            vueGame.chargePartie(vueGame.partiesQML[ligne])
            affiche=false
        }
    }

    AfficheListe {
        id: supprimer
        anchors.fill: parent
        visible: false
        titre: "Supprimer une partie enregistrée"
        textebouton: "Supprimer"
        bouton.onClicked: {
            vueGame.deletePartie(vueGame.partiesQML[ligne])
            affiche=false
        }
    }

    Police {
        id: police
        anchors.fill: parent
    }

    Rectangle{
        id:rectanglePerdu
        visible: vueGame.valFin[0]
        anchors.fill: parent
        color: vueGame.templateQML[0]

        Image {
            id: image
            height: 240
            y:15
            fillMode: Image.PreserveAspectFit
            source: vueGame.templateQML[7]
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: textPerdu
            y:260
            width: parent.width
            horizontalAlignment: Text.AlignHCenter
            text: qsTr("Oh non ! Vous avez perdu...\n Vous pouvez revenir en arrière, ou commencer une nouvelle partie ;)")
            font.pointSize: 10
            font.family: vueGame.templateQML[6]
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Bouton{
            id:boutonPerdu
            y:300
            valeurText: "Retour"
            action.onClicked: vueGame.closeFin(0)
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    Rectangle{
        id:rectangleGagne
        visible: vueGame.valFin[1]
        anchors.fill: parent
        color: vueGame.templateQML[0]
        focus: true

        Image {
            id: image2
            height: 240
            y:15
            fillMode: Image.PreserveAspectFit
            source: vueGame.templateQML[8]
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: textGagne
            y:260
            width: parent.width
            horizontalAlignment: Text.AlignHCenter
            text: qsTr("Bravo, vous avez gagné !!\n Vous pouvez continuer votre partie, ou en commencer une nouvelle ;)")
            font.pointSize: 10
            font.family: vueGame.templateQML[6]
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Bouton{
            id:boutonGagne
            y:300
            valeurText: "Continuer"
            action.onClicked: {
                vueGame.closeFin(1);
            }
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
