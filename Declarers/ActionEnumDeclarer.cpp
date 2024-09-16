#include "ActionEnumDeclarer.h"

void ActionEnumDeclarer::declareQML() {
    qRegisterMetaType<ActionEnumDeclarer::Action>("ActionEnumDeclarer::Action");
    qmlRegisterType<ActionEnumDeclarer>("ActionQMLEnums", 1, 1, "Action");
}

