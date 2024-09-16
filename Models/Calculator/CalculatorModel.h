#ifndef CALCULATOR_MODEL_H
#define CALCULATOR_MODEL_H

#include "Declarers/ActionEnumDeclarer.h"

#include "CalculationLineBuilder.h"

class CalculatorModel{
private:
    CalculationLineBuilder calculationLineBuilder;

public:
    void Input(QString &input); //TODO TRYINPUT;
    void InputAction(ActionEnumDeclarer::Action &action);

    double getResult() const;
    QString getCalculationLine() const;

};

#endif

