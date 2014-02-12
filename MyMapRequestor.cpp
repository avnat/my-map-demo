#include "MyMapRequestor.h"

// define constants
QString MAP_WIDTH="360"; // Map width
QString MAP_HEIGHT="430";
int MAP_ZOOM= 14;
int CACHE_MAP_LIMIT = 5;
QString MAP_PATH = "qml/MyMapDemo/images/myMap.png";

MyMapRequestor::MyMapRequestor(QObject *parent) :
    QObject(parent)
{
    //  Lock app orientation to potrait
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationLockPortrait);

    // Exposing  MyMapRequestor class to QML
    ctxt = viewer.rootContext();
    ctxt->setContextProperty("MyMapRequestor", this);

    // Setting QML source file
    viewer.setMainQmlFile(QLatin1String("qml/MyMapDemo/main.qml"));

    rootObject = dynamic_cast<QObject*>(viewer.rootObject());

    // Map receieved signal connected to the slot
    connect(this, SIGNAL(MapResponseReceived()), rootObject, SLOT(updateMap()));

    QNetworkProxyFactory::setUseSystemConfiguration(true);
    nam = new QNetworkAccessManager(this);

    // Connecting Network access manager to the slot
    connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));

    // Conecting signal from Qt to QML
    viewer.showExpanded();

    // Initialize GPS Requestor
    iGPSRequestor = new GPSRequestor();

    // Connecting the GPSRequestor to the slot
    connect(iGPSRequestor, SIGNAL(updateLatLong(QString,QString)), this, SLOT(updateLatLong(QString,QString)));
}

void MyMapRequestor::finished(QNetworkReply *reply)
{
    // Map received
    if (reply->error() == QNetworkReply::NoError)
    {
        // read data from QNetworkReply here
        // Creating QImage from the reply
        QImageReader imageReader(reply);
        mapImage = imageReader.read();

        mapImage.save(MAP_PATH);

        // Emit Map received signal
        MapResponseReceived();
        // Add map to cache
        addToCacheMap(mapImage);        
    }

}


// This function is used to hit the map URL with the parameters
void MyMapRequestor::getMap(int type)
{
    iType=type;

    // If the map with the same attributes already exits in the Cache the function returns from here.
    if (checkCache())
    {
        return;
    }

    // Creating the URL for requesting the map
    QString url = "http://m.nokia.me/?c="
            +iLat+","
            +iLng+",&h="
            + MAP_HEIGHT + ",&w="
            + MAP_WIDTH + "&z="
            + QString::number(MAP_ZOOM) + "&nord";

    url.append("&t="+ QString::number(type));
    qDebug()<<url;


    // Using the http get method to send map request
    nam->get(QNetworkRequest(QUrl(url)));
}


// zoom in function
void MyMapRequestor::zoomIn()
{
    if(MAP_ZOOM!=16)
    {
        MAP_ZOOM++;
        getMap(iType);
    }
}

// zoom out function
void MyMapRequestor::zoomOut()
{
    if(MAP_ZOOM!=8)
    {
        MAP_ZOOM--;
        getMap(iType);
    }

}

// Updating the lat and lng as received from GPSRequestor
void MyMapRequestor::updateLatLong(QString lat,QString lng)
{
    iLat = lat;
    iLng = lng;
}

// Adding map to Cache
void MyMapRequestor::addToCacheMap(QImage image)
{
    mapCache.append(new MapSnaps(image, iLat, iLng,iType, MAP_ZOOM ));
    if (mapCache.length() >5)
    {
        mapCache.takeFirst();
    }
}

// Checking if the requested map alreading exits in Cache
bool MyMapRequestor::checkCache()
{
    for (int i = 0; i < mapCache.length(); i++) {

        if (mapCache.at(i)->lat == iLat &&
                mapCache.at(i)->lng == iLng &&
                mapCache.at(i)->type == iType &&
                mapCache.at(i)->zoomLevel == MAP_ZOOM)
        {
            mapCache.at(i)->map.save(MAP_PATH);
            MapResponseReceived();
            return true;
        }
    }
    return false;
}
