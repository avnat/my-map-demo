import QtQuick 1.1

// MyMap View
Rectangle{
    width: parent.width
    height: parent.height
    color: "transparent"

    property alias myMapImage: mapImage

    Rectangle{
        id: infoText
        width: parent.width
        height: 30
        anchors.top: titleBar.bottom
        color: "lightsteelblue"
        Text {
            text: "You are here!"
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 20
            font.bold: true
        }
    }

    // Map Image
    Image{
        id: mapImage
        width: parent.width
        height:parent.height - refreshButton.height - backButton.height - infoText.height
        anchors.top: infoText.bottom
        cache: false
        source: "images/myMap.png"
    }

    // Options Dialog
    ImageButton
    {
        id: optionsButton
        width: parent.width/2
        height: 60
        normalImage: "images/options.png"
        pressedImage: normalImage
        anchors.bottom: parent.bottom
        anchors.left: parent.left

        MouseArea{
            anchors.fill: parent
            onClicked: optionsDialog.opacity = 1;
        }
    }

    // Back button
    ImageButton
    {
        id: backButton
        width: parent.width/2
        height: 60
        normalImage: "images/back.png"
        pressedImage: normalImage
        anchors.bottom: parent.bottom
        anchors.right: parent.right

        MouseArea{
            anchors.fill: parent
            // Switching to home screen
            onClicked: homeScreenView.visible = "true"
        }
    }

    // Zoom in button
    ImageButton{
        id: zoomInButton
        normalImage: "images/zoomin.png"
        pressedImage: normalImage
        width: parent.width/3
        height: 60
        anchors.top:mapImage.bottom
        anchors.left: parent.left

        MouseArea{
            anchors.fill: parent
            // Accessing the zoomIn() from MyMapRequestor.cpp
            onClicked:MyMapRequestor.zoomIn();
        }
    }

    // Zoom out button
    ImageButton{
        id: zoomOutButton
        normalImage: "images/zoomout.png"
        pressedImage: normalImage
        width: parent.width/3
        height: 60
        anchors.top:  mapImage.bottom
        anchors.left: zoomInButton.right

        MouseArea{
            anchors.fill: parent
            // Accessing the zoomOut() from MyMapRequestor.cpp
            onClicked:MyMapRequestor.zoomOut();
        }
    }

    // Refresh button
    ImageButton{
        id: refreshButton
        normalImage: "images/refresh.png"
        pressedImage: normalImage
        width: parent.width/3
        height: 60
        anchors.top:  mapImage.bottom
        anchors.left: zoomOutButton.right

        MouseArea{
            anchors.fill: parent
            // Requesting map
            onClicked:MyMapRequestor.getMap(0);
        }
    }

}
