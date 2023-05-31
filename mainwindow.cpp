#include "mainwindow.h"
#include "ui_mainwindow.h"

#define PATH1 "/home/akari/workspace/soft3/Qt/soft3_vol2/test1.png"
#define PATH2 "/home/akari/workspace/soft3/Qt/soft3_vol2/test2.png"

QString g_img_path1, g_img_path2; //ファイル画像のパスを入れるためのグローバル変数
//cv::Mat g_img1, g_img2;
int g_count = 0; //カメラ入力のカウントを行うための変数。

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*** 背景色を薄い黄色にしている ***/
    centralWidget()->setStyleSheet("background:lemonchiffon;");

    /*** スタートボタンの調整 ***/
    ui->startButton->setFlat(true);
    ui->startButton->setStyleSheet("background-color:lemonchiffon;");

    /*** 各ボタンに対して背景の色が透けないようにしている ***/
    ui->quitButton->setStyleSheet("background-color:gainsboro;");
    ui->fileSelectButton->setStyleSheet("background-color:gainsboro;");
    ui->cameraButton_1->setStyleSheet("background-color:gainsboro;");
    ui->returnButton_1->setStyleSheet("background-color:gainsboro;");
    ui->fileOpenButton_1->setStyleSheet("background-color:gainsboro;");
    ui->fileOpenButton_2->setStyleSheet("background-color:gainsboro;");
    ui->returnButton_2->setStyleSheet("background-color:gainsboro;");
    ui->cameraTakeButton_1->setStyleSheet("background-color:gainsboro;");
}

MainWindow::~MainWindow()
{
    getUsbCamT->Stop = true; //USBカメラ
    delete ui;
}

/** USBカメラ **/
void MainWindow::onValueChangedCam()
{
    cv::Mat dst;
    getUsbCamT->getImage(&dst);
    qtImage = QImage((const unsigned char*)(dst.data), dst.cols, dst.rows, QImage::Format_RGB888);
    ui->cameraLabel_1->setPixmap(QPixmap::fromImage(qtImage));
}


void MainWindow::on_quitButton_released()
{
    exit(0);
}
void MainWindow::on_startButton_released()
{
    auto current_page = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(++current_page);
}


void MainWindow::on_fileSelectButton_released()
{
    auto current_page = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(current_page+2);
    ui->debuglabel_2->setText("1枚目の画像を選択してください。");
}

void MainWindow::on_returnButton_1_released()
{
    auto current_page = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(--current_page);
}

void MainWindow::on_fileOpenButton_1_released()
{
    QString selFilter;
    g_img_path1 = QFileDialog::getOpenFileName(this, tr("1枚目の画像選択"), "", tr("Image(*.png *.jpg *.jpeg)"), &selFilter, QFileDialog::DontUseCustomDirectoryIcons); //opencvに渡すには共通の変数にするべきだね
    if(g_img_path1.isEmpty()){
        ui->debuglabel_2->setText("1枚目の画像の取得に失敗しました。もう一度選択してください。");
    }else{
        ui->debuglabel_2->setText("2枚目の画像を選択してください。");
    }
}

void MainWindow::on_returnButton_2_released()
{
    auto current_page = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(current_page-2);
}

void MainWindow::on_cameraButton_1_released()
{
    auto current_page = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(++current_page);
    ui->debuglabel_3->setText("1枚目の画像を撮影してください。");
    /**USBカメラ**/
    getUsbCamT = new getUsbCamera(this);
    if(getUsbCamT->initCam()){
        connect(getUsbCamT, SIGNAL(valueChangedCam(void)), this, SLOT(onValueChangedCam(void)));
        getUsbCamT->start();
    }else{
        QMessageBox msgBox(this);
        msgBox.setText(tr("カメラがオープンできませんでした。"));
        msgBox.setWindowTitle(tr("エラー"));
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.setDefaultButton(QMessageBox::Yes);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        ui->debuglabel_1->setText("カメラ画像の取得に失敗しました。もう一度選択してください。");
        auto current_page = ui->stackedWidget->currentIndex();
        ui->stackedWidget->setCurrentIndex(--current_page);
    }
}

void MainWindow::on_cameraTakeButton_1_released()
{
    cv::Mat img;
    getUsbCamT->getImage(&img);
//    qtImage = QImage((const unsigned char*)(img.data), img.cols, img.rows, QImage::Format_RGB888);
    g_count++;
    if(g_count == 1){
        cv::imwrite(PATH1, img);
        g_img_path1 = tr(PATH1);
        ui->debuglabel_3->setText("2枚目の画像を撮影してください。");
    }else{
        cv::imwrite(PATH2, img);
        g_img_path1 = tr(PATH2);
        g_count = 0;
        ui->debuglabel_3->setText("");
        getUsbCamT->Stop = true;
        auto current_page = ui->stackedWidget->currentIndex();
        ui->stackedWidget->setCurrentIndex(current_page+2);
    }
}

void MainWindow::on_fileOpenButton_2_released()
{
    if(g_img_path1.isEmpty()){
        ui->debuglabel_2->setText("1枚目の画像を先に選択してください。");
    }else{
        QString selFilter;
        g_img_path2 = QFileDialog::getOpenFileName(this, tr("2枚目の画像選択"), "", tr("Image(*.png *.jpg *.jpeg)"), &selFilter, QFileDialog::DontUseCustomDirectoryIcons); //opencvに渡すには共通の変数にするべきだね
        if(g_img_path2.isEmpty()){
            ui->debuglabel_2->setText("2枚目の画像の取得に失敗しました。もう一度選択してください。");
        }else{
            ui->debuglabel_2->setText("");
            auto current_page = ui->stackedWidget->currentIndex();
            ui->stackedWidget->setCurrentIndex(++current_page);
        }
    }

}

