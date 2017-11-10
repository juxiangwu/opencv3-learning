#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/cvui.h>

#define WINDOW_NAME "Skin Beauty"

/**
 * 基向双边滤波，磨皮算法实现
 */
using namespace std;
int dx = 1,fc = 3,p = 50;
cv::Mat skin_beauty(cv::Mat & src){
    //Dest =(Src * (100 - Opacity) + (Src + 2 * GuassBlur(EPFFilter(Src) - Src + 128) - 256) * Opacity) /100 ;
    cv::Mat temp1,temp2,temp3,temp4;
    cv::bilateralFilter(src,temp1,dx,fc,fc);
    temp2 = (temp1-src+128);
    cv::GaussianBlur(temp2,temp3,cv::Size((2*dx-1),(2*dx-1)),0,0);
    temp4 = src+2*temp3-255;
    cv::Mat dst = (src*(100-p) + temp4*p)/100;
    return dst;
}


int main()
{

    cv::Mat pic = cv::imread("E:/Develop/projects/opencv3-learning/datas/s1.png");
    int width = pic.cols, height = pic.rows;
    std::cout << pic.size() << std::endl;
    cv::Mat frame = cv::Mat(cv::Size(width*2+250, height+80), pic.type());

    cv::namedWindow(WINDOW_NAME);
    cvui::init(WINDOW_NAME);
    cv::Mat temp1,temp2,temp3,temp4,dst;
    while (cv::waitKey(10) != 27) {

        cv::bilateralFilter(pic,temp1,dx,fc,fc);
        temp2 = (temp1-pic+128);
        cv::GaussianBlur(temp2,temp3,cv::Size((2*dx-1),(2*dx-1)),0,0);
        temp4 = pic+2*temp3-255;
        dst = (pic*(100-p) + temp4*p)/100;
        //cv::imshow("DST",dst);
       // std::cout << "res.size()" << res.size() << std::endl;
        cvui::window(frame,0,0,dst.cols,dst.rows+50,"SRC");
        pic.copyTo(frame(cv::Rect(0,20,dst.cols,dst.rows)));

        cvui::window(frame,dst.cols+10,0,dst.cols,dst.rows+50,"DST");
        dst.copyTo(frame(cv::Rect(dst.cols+10,20,dst.cols,dst.rows)));

        cvui::window(frame, width * 2 + 30, 50, 190, 250, "Setting");
        //cvui::checkbox(frame, 375, 80, "Use Canny Edge", &use_canny);
        cvui::trackbar(frame, width * 2 + 35, 110, 165, &fc, 1, 255);
        cvui::trackbar(frame, width * 2 + 35, 180, 165, &dx, 1, 255);
        cvui::trackbar(frame, width * 2 + 35, 250, 165, &p, 1, 255);

        cvui::update();
        cv::imshow(WINDOW_NAME, frame);
    }
    return 0;
}
