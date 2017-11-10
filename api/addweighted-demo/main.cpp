#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/cvui.h>

using namespace std;

int main()
{
    cv::Mat src1 = cv::imread("E:/Develop/projects/opencv3-learning/datas/c1.jpg");
    cv::Mat src2 = cv::imread("E:/Develop/projects/opencv3-learning/datas/sk1.jpg");
    cv::Mat dst;
    int alpha_trace = 5;
    int gamma_trace = 2;

    double alpha = alpha_trace / 10.0;
    double gamma = gamma_trace / 10.0;

    cv::namedWindow("CTRL");
    cvui::init("CTRL");
    cv::Mat control_frame = cv::Mat(200, 250, CV_8UC3);
    char key = -1;
    while(true){
        control_frame = cv::Scalar(49, 52, 49);
        alpha = alpha_trace / 10.0;
        gamma = gamma_trace / 10.0;
        cv::addWeighted(src1,alpha,src2,1.0-alpha,gamma,dst);
        cvui::text(control_frame,10,0,"Alpha",0.4,0xff0000);
        cvui::trackbar(control_frame, 10, 20, 165, &alpha_trace, 0, 10);
        cvui::text(control_frame,10,100,"Gamma",0.4,0xff0000);
        cvui::trackbar(control_frame, 10, 120, 165, &gamma_trace, 0, 25);
        cv::imshow("CTRL",control_frame);
        cv::imshow("DST",dst);
        cvui::update();
        key = cv::waitKey(10);
        if(key == 27){
            break;
        }
    }
    cv::destroyAllWindows();
    return 0;
}
