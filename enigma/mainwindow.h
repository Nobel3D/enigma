#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "enigma.h"
#include "widgettasto.h"
#include "widgetluce.h"
#include "widgetrotore.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void premuto(const WidgetTasto* b);
    void rilascio();
private:
    Ui::MainWindow *ui;

    QList<WidgetTasto*>* tastiera;
    QList<WidgetLuce*>* luci;
    Enigma* e;
    char cifrata;

    WidgetTasto* c2b(char c);
    QLabel* c2l(char l);
};


#endif // MAINWINDOW_H
