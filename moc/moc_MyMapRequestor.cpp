/****************************************************************************
** Meta object code from reading C++ file 'MyMapRequestor.h'
**
** Created: Wed Dec 28 11:14:33 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MyMapRequestor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyMapRequestor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyMapRequestor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   38,   15,   15, 0x08,
      77,   69,   15,   15, 0x08,

 // methods: signature, parameters, type, tag, flags
     108,   15,   15,   15, 0x02,
     117,   15,   15,   15, 0x02,
     132,  127,   15,   15, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_MyMapRequestor[] = {
    "MyMapRequestor\0\0MapResponseReceived()\0"
    "reply\0finished(QNetworkReply*)\0lat,lng\0"
    "updateLatLong(QString,QString)\0zoomIn()\0"
    "zoomOut()\0type\0getMap(int)\0"
};

const QMetaObject MyMapRequestor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyMapRequestor,
      qt_meta_data_MyMapRequestor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyMapRequestor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyMapRequestor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyMapRequestor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyMapRequestor))
        return static_cast<void*>(const_cast< MyMapRequestor*>(this));
    return QObject::qt_metacast(_clname);
}

int MyMapRequestor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: MapResponseReceived(); break;
        case 1: finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: updateLatLong((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: zoomIn(); break;
        case 4: zoomOut(); break;
        case 5: getMap((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MyMapRequestor::MapResponseReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
