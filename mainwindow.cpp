#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include "algorithm.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    imageLoaded = false;
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::LoadImage);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::FindLanesOnImage);
    ui->label->setScaledContents(true);
    ui->label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadImage()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));
    if(fileName.size()!=0)
    {
        filepath = fileName.toStdString();
        QPixmap pix(fileName);
        DisplayImage(pix);
    }
}


void MainWindow::FindLanesOnImage()
{
    if(filepath.size()!=0)
    {
        filepath = Algo(filepath);
        QPixmap pix(filepath.c_str());
        DisplayImage(pix);
    }
}

void MainWindow::DisplayImage(QPixmap img)
{
    ui->label->setPixmap(img);
    ui->label->adjustSize();
    ui->label->show();
}
