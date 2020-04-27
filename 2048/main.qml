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
}
