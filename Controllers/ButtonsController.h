#include <QObject>
#include <QString>

#include <QElapsedTimer>

#include "Declarers/ActionEnumDeclarer.h"
#include "../Models/Model.h"

class ButtonsController : public QObject{
    Q_OBJECT
private:
    QElapsedTimer timerLastAction;
    Model* model;
public:
    ButtonsController(Model* _model, QObject *parent = nullptr): model(_model),  QObject(parent){}

    Q_INVOKABLE void handleActionButtonDown(ActionEnumDeclarer::Action action);
    Q_INVOKABLE void handleActionButtonUp(ActionEnumDeclarer::Action action);

    Q_INVOKABLE void handleSimpleButton(QString textButton);
};
