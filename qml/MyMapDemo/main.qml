import QtQuick 1.1

Image  {
    id: myApp
    width: 360
    height: 640
    source: "images/background.png"

    function updateMap()
    {
        // Map updated
        myMapView.myMapImage.source = "-1"
        myMapView.myMapImage.source =  "images/myMap.png"
    }

    // Title Bar
    Image {
        id: titleBar
        source: "images/title.png"
    }

    // Switching between screens
    SimpleViewManager
    {
        id: myViewManager
        width: parent.width
        height: parent.height - titleBar.height
        anchors.top: titleBar.bottom

        // Home Screen
        HomeScreen{
            id: homeScreenView
        }

        // MyMap Screen
        MyMap{
            id: myMapView
        }
    }

    // Options dialog
    Options
    {
        id: optionsDialog
        anchors.top: parent.top
    }
    About{
        id: aboutDialog
        anchors.top: parent.top
    }
}
