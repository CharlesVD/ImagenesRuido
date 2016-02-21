#ifndef DIALOGEXAMINARIMAGEN_H
#define DIALOGEXAMINARIMAGEN_H

#include <QDialog>

namespace Ui {
class DialogExaminarImagen;
}

class DialogExaminarImagen : public QDialog
{
    Q_OBJECT

public:
    explicit DialogExaminarImagen(QWidget *parent = 0);
    ~DialogExaminarImagen();

private:
    Ui::DialogExaminarImagen *ui;
};

#endif // DIALOGEXAMINARIMAGEN_H
