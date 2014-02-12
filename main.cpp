#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "MyMapRequestor.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyMapRequestor myMap;

    return app.exec();
}
