#ifndef WIDGETTASTO_H
#define WIDGETTASTO_H

#include <QPushButton>

class WidgetTasto : public QPushButton
{
    Q_OBJECT
public:
    WidgetTasto(QWidget *parent = nullptr);

    void ini();

    char lettera;
private slots:
    void slot();
signals:
    void premuto(const WidgetTasto* b);
private:
};

#endif // WIDGETTASTO_H
