#include "gamma.h"
#include "ui_gamma.h"

Gamma::Gamma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gamma)
{
    ui->setupUi(this);
}

Gamma::~Gamma()
{
    delete ui;
}
