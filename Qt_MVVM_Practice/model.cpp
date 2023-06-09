#include "model.h"

Model:: Model(QObject* parent) : QObject(parent), mClickedNum(0)
{}

Model :: ~Model()
{}

int Model :: getmClickedNum() const
{
    return mClickedNum;
}

void Model :: setmClickedNum(const int &newNum)
{
    if(mClickedNum != newNum)
    {
        mClickedNum = newNum;
    }

    emit numChanged();
}
