#ifndef MODEL_H
#define MODEL_H

#include "Declarers/ActionEnumDeclarer.h"
#include "Calculator/CalculatorModel.h"

#include <QDebug>
#include "Views/View.h"
#include "SecretMenuManager.h"

class Model {
    CalculatorModel _calculatorModel;

    SecretMenuManager* secretMenuManager;
    View* view;
public:
    Model(View* _view);

    ~Model();

    void handleActionWithDuration(ActionEnumDeclarer::Action& action, qint64 durationInMs);

    void handleNumInput(QString &NumText);

private:
    void OutputResult();
    void OutputCalculationLine();
};

#endif
