#include "CalculationLineBuilder.h"

void CalculationLineBuilder::Input(QString &input)
{
    stateMachineInput.Input(input);
}

void CalculationLineBuilder::InputAction(ActionEnumDeclarer::Action action)
{
    stateMachineInput.InputAction(action);
}

QString CalculationLineBuilder::getCalculationLine() const{
    return stateMachineInput.getInputed();
}

QString CalculationLineBuilder::StateMachineInput::getInputed() const
{
    return resultInput + currentState->getInputed();
}

void CalculationLineBuilder::StateMachineInput::Input(QString &input)
{
    currentState->Input(input, *this);
}

void CalculationLineBuilder::StateMachineInput::InputAction(ActionEnumDeclarer::Action action)
{   
    if(action == ActionEnumDeclarer::Action::Cancel){
        if (currentState != &stateInputEmpty){
            resultInput += currentState->getInputed();
            currentState = &stateInputEmpty;
        }
        resultInput.chop(1);
        return;
    }

    currentState->InputAction(action, *this);
}

void CalculationLineBuilder::StateMachineInput::switchState(CalculationLineBuilder::StateInputBase &nextState, QString &input)
{
    resultInput += currentState->getInputed();
    currentState = &nextState;
    currentState->Enter();
    currentState->Input(input, *this);
}

void CalculationLineBuilder::StateMachineInput::switchState(CalculationLineBuilder::StateInputBase &nextState, ActionEnumDeclarer::Action action)
{
    resultInput += currentState->getInputed();
    currentState = &nextState;
    if (action != ActionEnumDeclarer::Action::Brackets){
        currentState->Enter();
        currentState->InputAction(action, *this);
    }
}

void CalculationLineBuilder::StateInputNum::Input(QString &input, CalculationLineBuilder::StateMachineInput &stateMachine)
{
    strNum += input;
}

void CalculationLineBuilder::StateInputNum::InputAction(ActionEnumDeclarer::Action action, CalculationLineBuilder::StateMachineInput &stateMachine)
{
    switch (action) {
    case ActionEnumDeclarer::Action::Proccent:
    case ActionEnumDeclarer::Action::Division:
    case ActionEnumDeclarer::Action::Multiple:
    case ActionEnumDeclarer::Action::Minus:
    case ActionEnumDeclarer::Action::Plus:
        stateMachine.switchState(stateMachine.stateInputAction, action);
        break;
    case ActionEnumDeclarer::Action::Brackets:
        stateMachine.switchState(stateMachine.stateInputEndExpression, action);
        break;
    case ActionEnumDeclarer::Action::ChangeSign:
        changeSign();
    break;
    default:
        break;
    }
}

QString CalculationLineBuilder::StateInputNum::getInputed()
{
    return prefixNum + strNum + postfixNum;
}

void CalculationLineBuilder::StateInputNum::clear()
{
    prefixNum = "";
    postfixNum = "";
    strNum = "";
    numIsPositive = true;
}

void CalculationLineBuilder::StateInputNum::changeSign()
{
    if(numIsPositive){
        prefixNum = "(-";
        postfixNum = ")";
    }
    else{
        prefixNum = "";
        postfixNum = "";
    }
}

void CalculationLineBuilder::StateInputAction::Input(QString &input, CalculationLineBuilder::StateMachineInput &stateMachine)
{
    if(input[0].isDigit())
        stateMachine.switchState(stateMachine.stateInputNum, input);
}

void CalculationLineBuilder::StateInputAction::InputAction(ActionEnumDeclarer::Action action, CalculationLineBuilder::StateMachineInput &stateMachine)
{
    switch (action)
    {
    case ActionEnumDeclarer::Action::Proccent:
    case ActionEnumDeclarer::Action::Division:
    case ActionEnumDeclarer::Action::Multiple:
    case ActionEnumDeclarer::Action::Minus:
    case ActionEnumDeclarer::Action::Plus:
        inputed = getActionSign(action);
        break;
    case ActionEnumDeclarer::Action::Brackets:
        stateMachine.switchState(stateMachine.stateStartExpression, action);
        break;
    }
}

QString CalculationLineBuilder::StateInputAction::getInputed()
{
    return inputed;
}

void CalculationLineBuilder::StateInputAction::clear()
{
    inputed = "";
}

QString CalculationLineBuilder::StateInputAction::getActionSign(ActionEnumDeclarer::Action action) const
{
    switch (action) {
    case ActionEnumDeclarer::Action::Proccent:
        return "%";
    case ActionEnumDeclarer::Action::Division:
        return "/";
    case ActionEnumDeclarer::Action::Multiple:
        return "*";
    case ActionEnumDeclarer::Action::Minus:
        return "-";
    case ActionEnumDeclarer::Action::Plus:
        return "+";
    default:
        break;
    }
    return "";
}

void CalculationLineBuilder::StateInputStartExpression::Input(QString &input, CalculationLineBuilder::StateMachineInput &stateMachine)
{
    if(input[0].isDigit())
        stateMachine.switchState(stateMachine.stateInputNum, input);
}

void CalculationLineBuilder::StateInputStartExpression::InputAction(ActionEnumDeclarer::Action action, CalculationLineBuilder::StateMachineInput &stateMachine)
{
    switch (action) {
    case ActionEnumDeclarer::Action::Minus:
    case ActionEnumDeclarer::Action::ChangeSign:
        stateMachine.switchState(stateMachine.stateInputAction, ActionEnumDeclarer::Action::Minus);
        break;
    case ActionEnumDeclarer::Action::Brackets:
        stateMachine.switchState(stateMachine.stateStartExpression, action);
        break;
    }
}

QString CalculationLineBuilder::StateInputStartExpression::getInputed()
{
    return "(";
}

void CalculationLineBuilder::StateInputStartExpression::clear()
{
}

void CalculationLineBuilder::StateInputEndExpression::Input(QString &input, CalculationLineBuilder::StateMachineInput &stateMachine)
{
}

void CalculationLineBuilder::StateInputEndExpression::InputAction(ActionEnumDeclarer::Action action, CalculationLineBuilder::StateMachineInput &stateMachine)
{
    switch (action)
    {
    case ActionEnumDeclarer::Action::Proccent:
    case ActionEnumDeclarer::Action::Division:
    case ActionEnumDeclarer::Action::Multiple:
    case ActionEnumDeclarer::Action::Minus:
    case ActionEnumDeclarer::Action::Plus:
        stateMachine.switchState(stateMachine.stateInputAction, action);
        break;
    case ActionEnumDeclarer::Action::Brackets:
        stateMachine.switchState(stateMachine.stateInputEndExpression, action);
        break;
    }
}

QString CalculationLineBuilder::StateInputEndExpression::getInputed()
{
    return ")";
}

void CalculationLineBuilder::StateInputEndExpression::clear()
{
}

void CalculationLineBuilder::StateInputEmpty::Input(QString &input, CalculationLineBuilder::StateMachineInput &stateMachine)
{
    if(input[0].isDigit())
        stateMachine.switchState(stateMachine.stateInputNum, input);
}

void CalculationLineBuilder::StateInputEmpty::InputAction(ActionEnumDeclarer::Action action, CalculationLineBuilder::StateMachineInput &stateMachine)
{
    switch (action)
    {
    case ActionEnumDeclarer::Action::Proccent:
    case ActionEnumDeclarer::Action::Division:
    case ActionEnumDeclarer::Action::Multiple:
    case ActionEnumDeclarer::Action::Minus:
    case ActionEnumDeclarer::Action::Plus:
        stateMachine.switchState(stateMachine.stateInputAction, action);
        break;
    case ActionEnumDeclarer::Action::Brackets:
        stateMachine.switchState(stateMachine.stateStartExpression, action);
        break;
    }
}

QString CalculationLineBuilder::StateInputEmpty::getInputed()
{
    return "";
}

void CalculationLineBuilder::StateInputEmpty::clear()
{
}
