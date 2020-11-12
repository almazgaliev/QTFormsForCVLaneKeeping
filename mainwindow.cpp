#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::LoadImage);

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
    QPixmap pix(fileName);
    ui->label->adjustSize();
    ui->label->setPixmap(pix);
    ui->label->show();
}

