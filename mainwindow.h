#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "salpimienta.h"
#include "gamma.h"

#include <QMainWindow>
#include <QFileDialog>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/gpu/gpu.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbrir_Im_gen_triggered();

    void on_actionRestablecer_triggered();

    void on_actionSal_pimienta_triggered();

    void on_actionGamma_triggered();

private:
    Ui::MainWindow *ui;

    SalPimienta *vsalpimienta;
    Gamma *vgamma;

    float aleatorio(float min, float max);
    QString ruta;
    cv::Mat imagenCV;
};

#endif // MAINWINDOW_H
