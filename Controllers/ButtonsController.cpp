#include "ButtonsController.h"

void ButtonsController::handleActionButtonDown(ActionEnumDeclarer::Action action)
{
    timerLastAction.start();
}

void ButtonsController::handleActionButtonUp(ActionEnumDeclarer::Action action)
{
    qint64 elapsed = timerLastAction.elapsed();

    model->handleActionWithDuration(action, elapsed);
}

void ButtonsController::handleSimpleButton(QString textButton)
{
    model->handleNumInput(textButton);
}
