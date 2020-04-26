import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 645
    height: 480
    title: qsTr("2048")
    color: vueGame.templateQML[0]
    
    Rectangle {
        id: rectangle
        x: 210
        y: 66
        width: 225
        height: 225
        color: "#bbada0"
        focus: true
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

        Case {
            id: element11
            x: 5
            y: 5
            numero: 0
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]

        }

        Case {
            id: element12
            x: 60
            y: 5
            numero: 1
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }

        Case {
            id: element13
            x: 115
            y: 5
            numero: 2
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }

        Case {
            id: element14
            x: 170
            y: 5
            numero: 3
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }

        Case {
            id: element21
            x: 5
            y: 60
            numero: 4
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }

        Case {
            id: element22
            x: 60
            y: 60
            numero: 5
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }

        Case {
            id: element23
            x: 115
            y: 60
            numero: 6
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }

        Case {
            id: element24
            x: 170
            y: 60
            numero: 7
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }

        Case {
            id: element31
            x: 5
            y: 115
            numero: 8
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }

        Case {
            id: element32
            x: 60
            y: 115
            numero: 9
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }

        Case {
            id: element33
            x: 115
            y: 115
            numero: 10
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }

        Case {
            id: element34
            x: 170
            y: 115
            numero: 11
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }

        Case {
            id: element41
            x: 5
            y: 170
            numero: 12
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }

        Case {
            id: element42
            x: 60
            y: 170
            numero: 13
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }

        Case {
            id: element43
            x: 115
            y: 170
            numero: 14
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }

        Case {
            id: element44
            x: 170
            y: 170
            numero: 15
            valeurText: vueGame.valQML[numero]
            couleur: vueGame.colQML[numero]
        }
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

    Enregistrer {
        id: enregistrer
        anchors.fill: parent
        visible: false
    }

    Charger {
        id: charger
        anchors.fill: parent
        visible: false
    }
}
