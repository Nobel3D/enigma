#include "widgetluce.h"
#include <QDebug>

WidgetLuce::WidgetLuce(QWidget *parent) : QLabel(parent)
{


}

void WidgetLuce::ini()
{
    char t = objectName().at(1).toLatin1();
    lettera = t == '_' ? ' ' : t;
}
