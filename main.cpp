#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include <QtDebug>
#include <QQmlContext>
#include <QFontDatabase>

#include "imageprovider.h"
#include "liveimage.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qDebug() << "register:" << qmlRegisterType<LiveImage>("MyApp.Images", 1, 0, "LiveImage");
    ImageProvider *provider = new(ImageProvider);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("LiveImageProvider", provider);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    QImage img = QImage();
    qDebug() << img.load(":/images/idlecirc.png");
    provider->setImage(img);

    Imageprocessor(provider);

    return app.exec();
}
