#include "viewmodel.h"

ViewModel :: ViewModel()
{}

ViewModel :: ~ViewModel()
{}

int ViewModel::clickedNum() const {
    return m_model.getmClickedNum();
}

void ViewModel::addNum() {
    int currentNum = m_model.getmClickedNum();
    m_model.setmClickedNum(currentNum + 1);
    emit clickedNumChanged();
}

void ViewModel::subNum() {
    int currentNum = m_model.getmClickedNum();
    m_model.setmClickedNum(currentNum - 1);
    emit clickedNumChanged();
}