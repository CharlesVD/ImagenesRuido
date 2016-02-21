#ifndef GAMMA_H
#define GAMMA_H

#include <QDialog>

namespace Ui {
class Gamma;
}

class Gamma : public QDialog
{
    Q_OBJECT

public:
    explicit Gamma(QWidget *parent = 0);
    ~Gamma();

private:
    Ui::Gamma *ui;
};

#endif // GAMMA_H
