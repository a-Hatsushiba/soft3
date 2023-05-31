#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
/** USBカメラ用 **/
#include <QMessageBox>
#include <QThread>
#include "getUsbCamera.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    getUsbCamera *getUsbCamT; //usbカメラ追加

private slots:
    void on_quitButton_released();

    void on_startButton_released();

    void on_fileSelectButton_released();

    void on_returnButton_1_released();

    void on_fileOpenButton_1_released();

    void on_returnButton_2_released();

    void onValueChangedCam(void); //USBカメラ

    void on_cameraButton_1_released();

    void on_cameraTakeButton_1_released();

    void on_fileOpenButton_2_released();

    void on_cameraTakeButton_2_released();

private:
    Ui::MainWindow *ui;

    QImage qtImage; //USBカメラつ
};
#endif // MAINWINDOW_H
