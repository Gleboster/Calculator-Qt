#include "CalculatorModel.h"

#include "CalculationParser.h"

#include <QDebug>

void CalculatorModel::Input(QString &input)
{
    calculationLineBuilder.Input(input);
}

void CalculatorModel::InputAction(ActionEnumDeclarer::Action &action)
{
    calculationLineBuilder.InputAction(action);
}

double CalculatorModel::getResult() const
{
    CalculationParser parser;
    return parser.Calculate(calculationLineBuilder.getCalculationLine());
}

QString CalculatorModel::getCalculationLine() const
{
    return calculationLineBuilder.getCalculationLine();
}
