#ifndef ACTION_ENUM_DECLARER_H
#define ACTION_ENUM_DECLARER_H

#include <QObject>

#include <QtGlobal>
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
    // Qt 4
    #include <QDeclarativeEngine>
#else
    // Qt 5
    #include <QQmlEngine>
#endif

class ActionEnumDeclarer : public QObject {
    Q_OBJECT
public:
    enum Action {
        Brackets,
        ChangeSign,
        Proccent,
        Division,
        Multiple,
        Minus,
        Plus,
        Equal,
        Cancel
    };
    Q_ENUM(Action)

    static void declareQML();
};

#endif
