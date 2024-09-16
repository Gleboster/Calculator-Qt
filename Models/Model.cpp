#include "Model.h"

Model::Model(View *_view) : view(_view){
    secretMenuManager = new SecretMenuManager(_view);
}

Model::~Model(){
    delete secretMenuManager;
}

void Model::handleActionWithDuration(ActionEnumDeclarer::Action &action, qint64 durationInMs)
{
    secretMenuManager->handleActionWithDuration(action, durationInMs);

    if (action == ActionEnumDeclarer::Action::Equal)
        OutputResult();
    else{
        _calculatorModel.InputAction(action);
        OutputCalculationLine();
    }
}

void Model::handleNumInput(QString &NumText)
{
    secretMenuManager->handleNumInput(NumText);

    _calculatorModel.Input(NumText);
    OutputCalculationLine();
}

void Model::OutputResult()
{
    view->ShowResult(QString::number(_calculatorModel.getResult()));
}

void Model::OutputCalculationLine(){
    view->UpdateCalculationLine(_calculatorModel.getCalculationLine());
}
