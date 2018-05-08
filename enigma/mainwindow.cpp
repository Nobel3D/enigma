#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Rotore rot1("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    Rotore rot2("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    Rotore rot3("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    e = new Enigma(rot1, rot2, rot3);

    ui->rotore1->ini(e->rotore(0), ui->lR1);
    ui->rotore2->ini(e->rotore(1), ui->lR2);
    ui->rotore3->ini(e->rotore(2), ui->lR3);

    tastiera = new QList<WidgetTasto*>;

    tastiera->append(ui->btA);
    tastiera->append(ui->btB);
    tastiera->append(ui->btC);
    tastiera->append(ui->btD);
    tastiera->append(ui->btE);
    tastiera->append(ui->btF);
    tastiera->append(ui->btG);
    tastiera->append(ui->btH);
    tastiera->append(ui->btI);
    tastiera->append(ui->btL);
    tastiera->append(ui->btM);
    tastiera->append(ui->btN);
    tastiera->append(ui->btO);
    tastiera->append(ui->btP);
    tastiera->append(ui->btQ);
    tastiera->append(ui->btR);
    tastiera->append(ui->btS);
    tastiera->append(ui->btT);
    tastiera->append(ui->btU);
    tastiera->append(ui->btV);
    tastiera->append(ui->btZ);
    tastiera->append(ui->btX);
    tastiera->append(ui->btY);
    tastiera->append(ui->btK);
    tastiera->append(ui->btW);
    tastiera->append(ui->btJ);
    tastiera->append(ui->bt_);

    luci = new QList<WidgetLuce*>;

    luci->append(ui->lA);
    luci->append(ui->lB);
    luci->append(ui->lC);
    luci->append(ui->lD);
    luci->append(ui->lE);
    luci->append(ui->lF);
    luci->append(ui->lG);
    luci->append(ui->lH);
    luci->append(ui->lI);
    luci->append(ui->lL);
    luci->append(ui->lM);
    luci->append(ui->lN);
    luci->append(ui->lO);
    luci->append(ui->lP);
    luci->append(ui->lQ);
    luci->append(ui->lR);
    luci->append(ui->lS);
    luci->append(ui->lT);
    luci->append(ui->lU);
    luci->append(ui->lV);
    luci->append(ui->lZ);
    luci->append(ui->lX);
    luci->append(ui->lY);
    luci->append(ui->lK);
    luci->append(ui->lW);
    luci->append(ui->lJ);
    luci->append(ui->l_);

    for(int i = 0; i < tastiera->length(); i++)
    {
        tastiera->at(i)->ini();
        luci->at(i)->ini();

        connect(tastiera->at(i), SIGNAL(premuto(const WidgetTasto*)), this, SLOT(premuto(const WidgetTasto*)));
        connect(tastiera->at(i), SIGNAL(released()), this, SLOT(rilascio()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::premuto(const WidgetTasto *b)
{
    cifrata = e->cifra(b->lettera);
    c2l(cifrata)->setStyleSheet("QLabel { background-color: yellow; color: black; }");
    ui->rotore1->aggiorna();
    ui->rotore2->aggiorna();
    ui->rotore3->aggiorna();
}

void MainWindow::rilascio()
{
    c2l(cifrata)->setStyleSheet("");
}

WidgetTasto *MainWindow::c2b(char c)
{
    c = toupper(c);
    for(int i = 0; i < tastiera->length(); i++)
        if(tastiera->at(i)->lettera == c)
            return tastiera->at(i);
}

QLabel* MainWindow::c2l(char c)
{
    c = toupper(c);
    for(int i = 0; i < luci->length(); i++)
        if(luci->at(i)->lettera == c)
            return luci->at(i);
}
