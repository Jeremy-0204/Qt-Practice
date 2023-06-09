#include "QtWidgetsApplication1.h"

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
}

void QtWidgetsApplication1::ButtonClicked()
{
    QMessageBox::information(this, "Title", "Hello");
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{}
