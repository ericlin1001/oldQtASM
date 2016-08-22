#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
//
#include <iostream>
using namespace std;

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    cout<<"adfadfasdfa"<<endl;
    char buffer[100];
    cin>>buffer;
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QScopedPointer<QmlApplicationViewer> viewer(QmlApplicationViewer::create());

    viewer->setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer->setMainQmlFile(QLatin1String("qml/test2/main.qml"));
    viewer->showExpanded();

    return app->exec();
}
