import QtQuick 1.0

// Home Screen View
Rectangle{
    width: parent.width
    height: parent.height
    color: "transparent"

    // My Postion button
    ImageButton{
        id: myPositionButton
        width: 250
        height: 60
        normalImage: "images/MyPosition.png"
        pressedImage: normalImage
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 100


        MouseArea {
            anchors.fill: parent
            onClicked: {
                //Switching to MyMap View
                myMapView.visible = true
                //Getting Map
                MyMapRequestor.getMap(0);
            }
        }
    }

    // About button
    ImageButton{
        id: aboutButton
        width: 250
        height: 60
        normalImage: "images/about.png"
        pressedImage: normalImage
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: myPositionButton.bottom
        anchors.topMargin: 40
        MouseArea{
            anchors.fill: parent
            onClicked: aboutDialog.opacity = 1;
        }
    }

    // Exit button
    ImageButton{
        id: exitButton
        width: 250
        height: 60
        normalImage: "images/exit.png"
        pressedImage: normalImage
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: aboutButton.bottom
        anchors.topMargin: 40

        MouseArea{
            anchors.fill:parent
            onClicked: Qt.quit();
        }
    }

}
