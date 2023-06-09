#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include <model.h>
#include <QObject>

class ViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int clickedNum READ clickedNum NOTIFY clickedNumChanged)

public:
    ViewModel();
    ~ViewModel();

    int clickedNum() const;

    Q_INVOKABLE void addNum();
    Q_INVOKABLE void subNum();

signals:
    void clickedNumChanged();

private:
    Model m_model;
};


#endif // VIEWMODEL_H
