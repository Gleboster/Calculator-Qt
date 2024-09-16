#ifndef CALCULATIONLINEBUILDER_H
#define CALCULATIONLINEBUILDER_H

#include "Declarers/ActionEnumDeclarer.h"

#include <QString>

#include "stack";

class CalculationLineBuilder{
private:
    class StateMachineInput;

    class StateInputBase{
    public:
        void Enter(){
            clear();
        }
        virtual void Input(QString &input, StateMachineInput& stateMachine) = 0;
        virtual void InputAction(ActionEnumDeclarer::Action action, StateMachineInput& stateMachine) = 0;
        virtual QString getInputed() = 0;

    protected:
        virtual void clear() = 0;
    };

    class StateInputNum : public StateInputBase{
        QString prefixNum;
        QString strNum;
        QString postfixNum;

        bool numIsPositive = true;
        bool lastActionIsChangeSign = false;
    public:
        void Input(QString &input, StateMachineInput& stateMachine) override;
        void InputAction(ActionEnumDeclarer::Action action, StateMachineInput& stateMachine) override;
        QString getInputed() override;
    protected:
        void clear();
    private:
        void changeSign();
        bool tryCancelInput();
    };

    class StateInputAction : public StateInputBase{
        QString inputed;
    public:
        void Input(QString &input, StateMachineInput& stateMachine) override;
        void InputAction(ActionEnumDeclarer::Action action, StateMachineInput& stateMachine) override;
        QString getInputed() override;
    protected:
        void clear() override;
    private:
        QString getActionSign(ActionEnumDeclarer::Action action) const;
    };

    class StateInputStartExpression : public StateInputBase{
    public:
        void Input(QString &input, StateMachineInput& stateMachine) override;
        void InputAction(ActionEnumDeclarer::Action action, StateMachineInput& stateMachine) override;
        QString getInputed() override;
    protected:
        void clear() override;
    };

    class StateInputEndExpression : public StateInputBase{
        void Input(QString &input, StateMachineInput& stateMachine) override;
        void InputAction(ActionEnumDeclarer::Action action, StateMachineInput& stateMachine) override;
        QString getInputed() override;
    protected:
        void clear() override;
    };

    class StateInputEmpty : public StateInputBase{
    public:
        void Input(QString &input, StateMachineInput& stateMachine) override;
        void InputAction(ActionEnumDeclarer::Action action, StateMachineInput& stateMachine) override;
        QString getInputed() override;
    protected:
        void clear() override;
    };

    class StateMachineInput {
        StateInputBase* currentState;

        QString resultInput;
        StateInputEmpty stateInputEmpty;
    public:
        StateMachineInput(){
            currentState = &stateInputEmpty;
            currentState->Enter();
        }

        QString getInputed() const;

        void Input(QString &input);
        void InputAction(ActionEnumDeclarer::Action action);

        void switchState(StateInputBase& nextState, QString &input);
        void switchState(StateInputBase& nextState, ActionEnumDeclarer::Action action);

        StateInputNum stateInputNum;
        StateInputAction stateInputAction;
        StateInputStartExpression stateStartExpression;
        StateInputEndExpression stateInputEndExpression;
    };


    StateMachineInput stateMachineInput;
public:
    CalculationLineBuilder() = default;

    void Input(QString &input);
    void InputAction(ActionEnumDeclarer::Action action);

    QString getCalculationLine() const;
};

#endif // CALCULATIONLINEBUILDER_H
