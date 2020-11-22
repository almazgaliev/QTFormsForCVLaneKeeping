#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void DisplayImage(QPixmap img);
    ~MainWindow();

public slots:
    void LoadImage();
    void FindLanesOnImage();
private:
    bool imageLoaded;
    std::string filepath;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
