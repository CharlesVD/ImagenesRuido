#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <CL/cl.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vsalpimienta = new SalPimienta(parentWidget());
    vgamma = new Gamma(parentWidget());

    cl_platform_id platform;
    clGetPlatformIDs(1, &platform, NULL);

    cl_device_id device;
    clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);

    cl_context context;
    context = clCreateContext(NULL, 1, &device, NULL, NULL, NULL);
}

MainWindow::~MainWindow()
{
    delete ui;
}

float MainWindow::aleatorio(float min, float max)
{
    int minI = min*100000;
    int maxI = max*100000;

    float num = qrand()%( maxI-minI )+minI;
    num = num*0.00001;

    return num;
}

void MainWindow::on_actionAbrir_Im_gen_triggered()
{
    QFileDialog ventanaArchivo;

    ruta= ventanaArchivo.getOpenFileName(this, tr("Seleccionar Imágen"),QDir::homePath(),tr("Imágenes (*.jpeg *.png)"));
    ventanaArchivo.close();
    imagenCV = cv::imread(ruta.toStdString());
    cv::cvtColor(imagenCV,imagenCV,CV_BGR2RGB);

    QImage imagenMuestra =  QImage((const unsigned char*)(imagenCV.data),
               imagenCV.cols,imagenCV.rows,QImage::Format_RGB888);

    ui->labelImagen->setMinimumWidth(imagenCV.cols);
    ui->labelImagen->setMinimumHeight(imagenCV.rows);
    ui->labelImagen->setPixmap(QPixmap::fromImage(imagenMuestra));
}

void MainWindow::on_actionRestablecer_triggered()
{
//    imagenCV = cv::imread(ruta.toStdString());
//    cv::cvtColor(imagenCV,imagenCV,CV_BGR2RGB);

    QImage imagenMuestra =  QImage((const unsigned char*)(imagenCV.data),
               imagenCV.cols,imagenCV.rows,QImage::Format_RGB888);

//    ui->labelImagen->setMinimumWidth(imagenCV.cols);
//    ui->labelImagen->setMinimumHeight(imagenCV.rows);
    ui->labelImagen->setPixmap(QPixmap::fromImage(imagenMuestra));
}

void MainWindow::on_actionSal_pimienta_triggered()
{
    vsalpimienta->exec();
    cv::Mat ImgProc = imagenCV;
    int prob;
    for(int i=0;i<imagenCV.cols;i++)
    {
        for(int j=0;j<imagenCV.rows;j++)
        {
            prob = aleatorio(1,100);
            if(prob<=20)
            {
                ImgProc.at <cv::Vec3b>(j,i)[0]=0;
                ImgProc.at <cv::Vec3b>(j,i)[1]=0;
                ImgProc.at <cv::Vec3b>(j,i)[2]=0;
            }
            prob = aleatorio(1,100);
            if(prob<=20)
            {
                ImgProc.at <cv::Vec3b>(j,i)[0]=255;
                ImgProc.at <cv::Vec3b>(j,i)[1]=255;
                ImgProc.at <cv::Vec3b>(j,i)[2]=255;
            }
        }
    }
    QImage imagenMuestra =  QImage((const unsigned char*)(ImgProc.data),
               ImgProc.cols,ImgProc.rows,QImage::Format_RGB888);

    ui->labelImagen->setPixmap(QPixmap::fromImage(imagenMuestra));
}

void MainWindow::on_actionGamma_triggered()
{
    vgamma->exec();
//        cv::gpu::GpuMat ImgProc;
//        ImgProc.upload(imagenCV);
        cv::Mat ImgProc;
        imagenCV.copyTo(ImgProc);
        int ruidoF;
    //    float ruido,rx,ry,A,theta,img;
        float img,A,ruido;
        A=sqrt((double)500/(double)2)/2;

        for(int i=0;i<imagenCV.cols;i++)
        {
            for(int j=0;j<imagenCV.rows;j++)
            {
                img=0.0;
                for(int x=0;x<=2;x++)
                {
                    ruido=-2*A*log(aleatorio(0,1));
                    //theta=(float)qrand()*1.9175345E-4 - M_PI;
                    //rx = ruido * cos(theta);
                    //ry = ruido * sin(theta);
                    //ruido = pow(rx,2) + pow(ry,2);
                    img+=ruido;
                }
                ruidoF = (int)(img+0.5);
                if(ruidoF>255)
                {
                    ruidoF=255;
                }
                ImgProc.at <cv::Vec3b>(j,i)[0]=(ImgProc.at <cv::Vec3b>(j,i)[0]+ruidoF)/2;
                ImgProc.at <cv::Vec3b>(j,i)[1]=(ImgProc.at <cv::Vec3b>(j,i)[1]+ruidoF)/2;
                ImgProc.at <cv::Vec3b>(j,i)[2]=(ImgProc.at <cv::Vec3b>(j,i)[2]+ruidoF)/2;
            }
        }
        QImage imagenMuestra =  QImage((const unsigned char*)(ImgProc.data),
                   ImgProc.cols,ImgProc.rows,QImage::Format_RGB888);

        ui->labelImagen->setPixmap(QPixmap::fromImage(imagenMuestra));
}
