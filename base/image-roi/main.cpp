#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    cv::Mat pic = cv::imread("E:/Develop/projects/opencv3-learning/datas/f1.png");
    cv::Mat image = cv::Mat::zeros(128, 128, CV_8UC3);
    image.setTo(cv::Scalar(100, 0, 0));

    cv::Rect roi_rect = cv::Rect(0,0,image.cols,image.rows);

    image.copyTo(pic(roi_rect));

    cv::imshow("PIC",pic);
    cv::waitKey();
    return 0;
}
