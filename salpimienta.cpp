#include "salpimienta.h"
#include "ui_salpimienta.h"

SalPimienta::SalPimienta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SalPimienta)
{
    ui->setupUi(this);
}

SalPimienta::~SalPimienta()
{
    delete ui;
}
