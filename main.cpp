#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Controllers/ButtonsController.h"
#include "Views/View.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    View view;
    engine.rootContext()->setContextProperty("view", &view);

    Model model(&view);

    ButtonsController buttonsController(&model);
    ActionEnumDeclarer::declareQML();
    engine.rootContext()->setContextProperty("buttonsController", &buttonsController);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    engine.load(QUrl(QStringLiteral("qrc:/SecretWindow.qml")));
    return app.exec();
}
