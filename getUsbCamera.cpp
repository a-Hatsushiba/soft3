#include "getUsbCamera.h"

/** USBカメラ **/
getUsbCamera::getUsbCamera(QObject *parent, bool b) : QThread(parent), Stop(b)
{

}

getUsbCamera::~getUsbCamera()
{
    Stop = true;
}

bool getUsbCamera::initCam(void) //カメラ読み込みできるか
{
    bool ret = true;

    cap.open(0);
    if(cap.isOpened()){
        cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
        cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    }else{
        ret = false;
    }
    return ret;
}

void getUsbCamera::run(void) //実行
{
    QMutex mutex;

    while(1){
        mutex.lock();
        if(this->Stop) break;
        mutex.unlock();

        cap >>frame; //カメラからフレームを取得
        cv::cvtColor(frame, dst, cv::COLOR_BGR2RGB);

        emit valueChangedCam();

        this->msleep(20);
    }
}

void getUsbCamera::getImage(cv::Mat *image)
{
    *image = dst.clone(); //getUsbCameraクラスだからdst使える。
}
