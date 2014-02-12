import QtQuick 1.1

// Options Dialog
Image{
    width: myApp.width
    height: myApp.height
    source: "images/transparent.png"
    opacity: 0


    Rectangle{
        id: listContainer
        width: parent.width-100
        height: 270
        radius: 5
        color: "white"
        anchors.centerIn: parent
        Text{
            id: optionsText
            text: "Choose Map mode"
            font.pixelSize: 20
            font.bold: true
            color: "black"
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // List of Map Modes
        ListModel {
            id: optionsModel
            ListElement {
                title: "Normal map"
            }
            ListElement {
                title: "Satellite map"
            }
            ListElement {
                title: "Terrain map"
            }
            ListElement {
                title: "Hybrid map"
            }
            ListElement {
                title: "Back"
            }
        }

        ListView{
            id: optionsList
            width: parent.width
            height: parent.height
            anchors.top: optionsText.bottom
            anchors.topMargin: 5
            model: optionsModel
            clip: true
            delegate: Rectangle{
                width: parent.width
                height: 45
                color: green

                Text{
                    text: title
                    font.pixelSize: 20
                    color: "black"
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.top: parent.top
                    anchors.topMargin: 10

                }

                Rectangle{
                    width: parent.width
                    height: 1
                    color: "black"
                    anchors.bottom: parent.bottom
                }

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        // Requesting map with selected mode
                        if (index!=4){
                            MyMapRequestor.getMap(index);
                        }
                        optionsDialog.opacity = 0
                    }
                }
            }
        }

    }

}
