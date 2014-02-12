/****************************************************************************
** Meta object code from reading C++ file 'GPSRequestor.h'
**
** Created: Wed Dec 28 11:14:31 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GPSRequestor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GPSRequestor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GPSRequestor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   53,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GPSRequestor[] = {
    "GPSRequestor\0\0lat,lng\0"
    "updateLatLong(QString,QString)\0"
    "geoPositionInfo\0positionUpdated(QGeoPositionInfo)\0"
};

const QMetaObject GPSRequestor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GPSRequestor,
      qt_meta_data_GPSRequestor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GPSRequestor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GPSRequestor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GPSRequestor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GPSRequestor))
        return static_cast<void*>(const_cast< GPSRequestor*>(this));
    return QObject::qt_metacast(_clname);
}

int GPSRequestor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateLatLong((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: positionUpdated((*reinterpret_cast< QGeoPositionInfo(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GPSRequestor::updateLatLong(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
