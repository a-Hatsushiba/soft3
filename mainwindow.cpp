#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openImageFile()
{
    QString selFilter;
    auto img_path1 = QFileDialog::getOpenFileName(this, tr("ファイルを開く"), "", tr("Image(*.png *.jpg *.jpeg)"), &selFilter, QFileDialog::DontUseCustomDirectoryIcons); //opencvに渡すには共通の変数にするべきだね
    ui->debuglabel->setText(img_path1);
}

void MainWindow::on_nextPageButton_released()
{
    auto current_page = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(++current_page);
}

void MainWindow::on_returnButton_released()
{
    auto current_page = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(--current_page);
}

void MainWindow::on_finishButton_released()
{
    exit(0);
}

void MainWindow::on_pushButton_released()
{
    exit(0);
}

void MainWindow::on_fileButton_released()
{

}
