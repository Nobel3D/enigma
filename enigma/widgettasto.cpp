#include "widgettasto.h"

WidgetTasto::WidgetTasto(QWidget *parent) : QPushButton(parent)
{
    connect(this, SIGNAL(pressed()), this, SLOT(slot()));
}

void WidgetTasto::ini()
{
    char t = objectName().at(2).toLatin1();
    lettera = t == '_' ? ' ' : t;
}

void WidgetTasto::slot()
{
    emit premuto(this);
}
