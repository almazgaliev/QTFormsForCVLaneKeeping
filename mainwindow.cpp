#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include "algorithm.cpp"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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
    filepath = fileName.toStdString();
    QPixmap pix(fileName);
    DisplayImage(pix);
}


void MainWindow::FindLanesOnImage()
{
    filepath = Algo(filepath);
    QPixmap pix(filepath.c_str());
    DisplayImage(pix);
}

void MainWindow::DisplayImage(QPixmap img)
{
    ui->label->setPixmap(img);
    ui->label->adjustSize();
    ui->label->show();
}
