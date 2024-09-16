#ifndef VIEW_H
#define VIEW_H

#include <QString>
#include <QObject>

class View : public QObject {
    Q_OBJECT

public:
    View(QObject *parent = nullptr);

    virtual ~View();

    Q_INVOKABLE void ShowResult(const QString &resultContent);

    Q_INVOKABLE void UpdateCalculationLine(const QString &calculationLineContent);
    Q_INVOKABLE void OpenSecretWindow();

signals:
    void resultUpdated(const QString &resultContent);
    void calculationLineUpdated(const QString &calculationLineContent);
    void secretWindowOpened();
};

#endif
