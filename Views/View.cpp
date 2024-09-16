#include "View.h"

View::View(QObject *parent) : QObject(parent) {}

View::~View(){
}

void View::ShowResult(const QString &resultContent) {
    emit resultUpdated(resultContent);
}

void View::UpdateCalculationLine(const QString &calculationLineContent) {
    emit calculationLineUpdated(calculationLineContent);
}

void View::OpenSecretWindow()
{
    emit secretWindowOpened();
}
