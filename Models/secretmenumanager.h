#ifndef SECRETMENUMANAGER_H
#define SECRETMENUMANAGER_H

#include "Views/View.h"
#include "../Declarers/ActionEnumDeclarer.h"

class SecretMenuManager{
    const QString PASSWORD = "123";

    QString inputedPassword;
    bool passwordIsInputed;

    View* view;
public:
    SecretMenuManager(View* _veiw) : view(_veiw){}

    void handleActionWithDuration(ActionEnumDeclarer::Action& action, qint64 durationInMs);
    void handleNumInput(QString &NumText);
};

#endif // SECRETMENUMANAGER_H
