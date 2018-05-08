#ifndef WIDGETROTORE_H
#define WIDGETROTORE_H

#include <QWidget>
#include <QScrollBar>
#include <QLabel>

#include "rotore.h"

class WidgetRotore : public QScrollBar
{
    Q_OBJECT
public:
    explicit WidgetRotore(QWidget *parent = nullptr);
    void ini(Rotore *_r, QLabel* _e);
    char letteraAttuale() const;
    void aggiorna();

    int v;
    Rotore* r;
public slots:
    void slot(int val);
private:
    QLabel* e;
};

#endif // WIDGETROTORE_H
