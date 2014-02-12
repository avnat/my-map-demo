#ifndef MyMapRequestor_H
#define MyMapRequestor_H

#include <QObject>

#include <QNetworkProxyFactory>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QImageReader>
#include <QtGui>
#include <QDeclarativeContext>
#include "qmlapplicationviewer.h"
#include "GPSRequestor.h"

/* MapSnaps class for caching */
class MapSnaps{
public:
    MapSnaps(QImage a_map, QString a_lat, QString a_lng,
             int a_type, int a_zoomLevel)
    {
        map = a_map;
        lat= a_lat;
        lng = a_lng;
        type = a_type ;
        zoomLevel = a_zoomLevel;
    }

    QImage map;
    QString lat, lng;
    int type, zoomLevel;
};

class MyMapRequestor : public QObject
{
    Q_OBJECT
public:
    MyMapRequestor(QObject *parent = 0);

    Q_INVOKABLE void zoomIn();
    Q_INVOKABLE void zoomOut();
    Q_INVOKABLE  void getMap(int type);

    void addToCacheMap(QImage);
    bool checkCache();
signals:
    void MapResponseReceived();

private slots:
    void finished(QNetworkReply *reply);
    void updateLatLong(QString lat,QString lng);

private:
    QmlApplicationViewer viewer;
    QDeclarativeContext *ctxt;
    QObject *rootObject;
    QImage mapImage;                /* Used to store the map Image */
    int index_cache;
    QNetworkAccessManager *nam;
    GPSRequestor* iGPSRequestor;
    QString iLat, iLng;             /* Stores the latitude and longitude of a position */
    int iType;                      /* Stores the index of map mode -- Normal mode(0), Sattelite mode(1), Terrain mode(2) and Hybrid mode(3) */
    QList<MapSnaps*> mapCache;      /* list of the chached maps */
};

#endif // MyMapRequestor_H
