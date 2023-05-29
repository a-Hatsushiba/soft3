#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    ui->fileOpenButton_1->setStyleSheet("background-color:gainsboro;");
    ui->cameraButton_1->setStyleSheet("background-color:gainsboro;");
    ui->returnButton_1->setStyleSheet("background-color:gainsboro;");
    ui->fileOpenButton_2->setStyleSheet("background-color:gainsboro;");
    ui->cameraButton_2->setStyleSheet("background-color:gainsboro;");
    ui->returnButton_2->setStyleSheet("background-color:gainsboro;");
}

MainWindow::~MainWindow()
{
    delete ui;
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


void MainWindow::on_fileOpenButton_1_released()
{
    QString selFilter;
    QString img_path1 = QString::null;
    img_path1 = QFileDialog::getOpenFileName(this, tr("ファイルを開く1"), "", tr("Image(*.png *.jpg *.jpeg)"), &selFilter, QFileDialog::DontUseCustomDirectoryIcons); //opencvに渡すには共通の変数にするべきだね
    if(img_path1.isNull()){
        ui->debuglabel_1->setText("画像の取得に失敗しました。もう一度選択してください。");
    }else{
        ui->debuglabel_1->setText("");
        auto current_page = ui->stackedWidget->currentIndex();
        ui->stackedWidget->setCurrentIndex(++current_page);
    }
}

void MainWindow::on_returnButton_1_released()
{
    auto current_page = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(--current_page);
}

void MainWindow::on_fileOpenButton_2_released()
{
    QString selFilter;
    QString img_path2 = QString::null;
    img_path2 = QFileDialog::getOpenFileName(this, tr("ファイルを開く1"), "", tr("Image(*.png *.jpg *.jpeg)"), &selFilter, QFileDialog::DontUseCustomDirectoryIcons); //opencvに渡すには共通の変数にするべきだね
    if(img_path2.isNull()){
        ui->debuglabel_2->setText("画像の取得に失敗しました。もう一度選択してください。");
    }else{
        ui->debuglabel_2->setText("");
        auto current_page = ui->stackedWidget->currentIndex();
        ui->stackedWidget->setCurrentIndex(++current_page);
    }
}

void MainWindow::on_returnButton_2_released()
{
    auto current_page = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(--current_page);
}
