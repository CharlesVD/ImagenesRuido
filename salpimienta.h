#ifndef SALPIMIENTA_H
#define SALPIMIENTA_H

#include <QDialog>

namespace Ui {
class SalPimienta;
}

class SalPimienta : public QDialog
{
    Q_OBJECT

public:
    explicit SalPimienta(QWidget *parent = 0);
    ~SalPimienta();

private:
    Ui::SalPimienta *ui;
};

#endif // SALPIMIENTA_H
