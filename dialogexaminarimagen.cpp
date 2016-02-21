#include "dialogexaminarimagen.h"
#include "ui_dialogexaminarimagen.h"

DialogExaminarImagen::DialogExaminarImagen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogExaminarImagen)
{
    ui->setupUi(this);
}

DialogExaminarImagen::~DialogExaminarImagen()
{
    delete ui;
}
