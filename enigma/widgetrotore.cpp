#include "widgetrotore.h"

WidgetRotore::WidgetRotore(QWidget *parent) : QScrollBar(parent)
{
}

void WidgetRotore::ini(Rotore *_r, QLabel *_e)
{
    v = 0;
    r = _r;
    e = _e;
    e->setText(QChar(r->posizione()));
    connect(this, SIGNAL(valueChanged(int)), this, SLOT(slot(int)));
}

char WidgetRotore::letteraAttuale() const
{
    return r->posizione();
}

void WidgetRotore::aggiorna()
{
    setValue(0);
    e->setText(QChar(r->posizione()));
    return;
}

void WidgetRotore::slot(int val)
{
    r->avanza(val - v);
    e->setText(QChar(r->posizione()));
    v = val;
}
