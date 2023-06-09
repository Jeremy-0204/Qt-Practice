#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int mClickedNum READ getmClickedNum WRITE setmClickedNum NOTIFY numChanged)

public:
    explicit Model(QObject* parent = nullptr);
    ~Model();

    int getmClickedNum() const;
    void setmClickedNum(const int &);

private:
    int mClickedNum;

signals:
    void numChanged();
};

#endif // MODEL_H
