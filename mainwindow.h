#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>

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
    void on_quitButton_released();

    void on_startButton_released();

    void on_fileOpenButton_1_released();

    void on_returnButton_1_released();

    void on_fileOpenButton_2_released();

    void on_returnButton_2_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
