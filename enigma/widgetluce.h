#ifndef WIDGETLUCE_H
#define WIDGETLUCE_H

#include <QWidget>
#include <QLabel>

class WidgetLuce : public QLabel
{
    Q_OBJECT
public:
    explicit WidgetLuce(QWidget *parent = nullptr);

    void ini();

    char lettera;

signals:

public slots:
};

#endif // WIDGETLUCE_H
