#include "SecretMenuManager.h"

void SecretMenuManager::handleActionWithDuration(ActionEnumDeclarer::Action &action, qint64 durationInMs)
{
    if (action == ActionEnumDeclarer::Action::Equal && durationInMs >= 4000){
        passwordIsInputed = true;
        inputedPassword = "";
    }
}

void SecretMenuManager::handleNumInput(QString &NumText)
{
    if(!passwordIsInputed)
        return;

    inputedPassword += NumText;
    if (inputedPassword == PASSWORD)
        view->OpenSecretWindow();

    if (inputedPassword.length() == PASSWORD.length()){
        passwordIsInputed = false;
        inputedPassword = "";
    }
}
