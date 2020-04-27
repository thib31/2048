import QtQuick 2.10
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Item {
    property var police: ["Tahoma","Times New Roman","Courier"]
    property var choixPolice: 0
    property var taillePolice: 12
    id:fenetre
    visible: false

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
                text: qsTr("Choix de la police")
                font.family:vueGame.templateQML[6]
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
            }

            Bouton {
                id: boutonValid
                x: parent.width/4-width/2
                y: 192
                valeurText: qsTr("Valider")
                couleur: vueGame.templateQML[4]
                action.onClicked: {
                    vueGame.changePolice(police[choixPolice]);
                    console.log(vueGame.templateQML[6])
                    fenetre.visible=false
                }
            }

            Bouton {
                id: boutonAnnulEnr
                x: parent.width*3/4-width/2
                y: boutonValid.y
                valeurText: qsTr("Annuler")
                action.onClicked: fenetre.visible=false
            }

            GridLayout {
                id: grid
                y: 48
                width: 300
                height: 20
                rows: 2
                columns: 3
                Layout.preferredWidth: 100
                anchors.horizontalCenter: parent.horizontalCenter
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

                Rectangle{
                    id:zoneTahoma
                    width: 100
                    height: 20
                    color: "#00000000"
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

                    CheckBox {
                        id: checkBox0
                        onCheckedChanged: {
                            if (checked){
                                checkBox1.checkedState=Qt.Unchecked
                                checkBox2.checkedState=Qt.Unchecked
                                choixPolice=0
                            }
                        }
                    }

                    Text {
                        id: element
                        x: checkBox0.width
                        verticalAlignment: Text.AlignVCenter
                        text: qsTr("Tahoma")
                        font.family: "Tahoma"
                        font.pixelSize: 12
                    }



                }

                Rectangle{
                    id:zoneTimes
                    width: 100
                    height: 20
                    color: "#00000000"

                    CheckBox {
                        id: checkBox1
                        onCheckedChanged: {
                            if (checked){
                                checkBox0.checkedState=Qt.Unchecked
                                checkBox2.checkedState=Qt.Unchecked
                                choixPolice=1
                            }
                        }
                    }

                    Text {
                        id: element1
                        x: checkBox1.width
                        text: qsTr("Times")
                        font.family: "Times New Roman"
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 12
                    }
                }

                Rectangle{
                    id:zoneCourrier
                    width: 100
                    height: 20
                    color: "#00000000"

                    CheckBox {
                        id: checkBox2
                        onCheckedChanged: {
                            if (checked){
                                checkBox0.checkedState=Qt.Unchecked
                                checkBox1.checkedState=Qt.Unchecked
                                choixPolice=2
                            }
                        }
                    }

                    Text {
                        id: element2
                        x: checkBox2.width
                        text: qsTr("Courier")
                        font.family: "Courier"
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 12
                    }
                }

            }

        }
    }
}
