#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openImageFile();

    void on_nextPageButton_released();

    void on_returnButton_released();

    void on_finishButton_released();

    void on_pushButton_released();

    void on_fileButton_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
