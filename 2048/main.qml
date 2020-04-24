import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    
    Rectangle {
        id: rectangle2
        x: 100
        y: 66
        width: 225
        height: 225
        color: "#dddddd"

        Case {
            id: element11
            x: 5
            y: 5
        }

        Case {
            id: element12
            x: 5
            y: 60
        }

        Case {
            id: element13
            x: 5
            y: 115
        }

        Case {
            id: element14
            x: 5
            y: 170
        }

        Case {
            id: element21
            x: 60
            y: 5
        }

        Case {
            id: element22
            x: 60
            y: 60
        }

        Case {
            id: element23
            x: 60
            y: 115
        }

        Case {
            id: element24
            x: 60
            y: 170
        }

        Case {
            id: element31
            x: 115
            y: 5
        }

        Case {
            id: element32
            x: 115
            y: 60
        }

        Case {
            id: element33
            x: 115
            y: 115
        }

        Case {
            id: element34
            x: 115
            y: 170
        }

        Case {
            id: element41
            x: 170
            y: 5
        }

        Case {
            id: element42
            x: 170
            y: 60
        }

        Case {
            id: element43
            x: 170
            y: 115
        }

        Case {
            id: element44
            x: 170
            y: 170
        }
        
    }
}
