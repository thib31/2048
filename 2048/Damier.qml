import QtQuick 2.0

Item {
    width: 225
    height: 225

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: vueGame.templateQML[2]

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
}
