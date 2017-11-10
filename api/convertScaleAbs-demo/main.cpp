#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/cvui.h>

using namespace std;

int main()
{
    cv::Mat src1 = cv::imread("E:/Develop/projects/opencv3-learning/datas/c1.jpg");
    cv::Mat dst;

    cv::namedWindow("CTRL");
    cvui::init("CTRL");
    cv::Mat control_frame = cv::Mat(200, 250, CV_8UC3);
    int alpha_trace = 5;
    double alpha = alpha_trace / 10.0;
    double beta = 1.0 - alpha;
    char key = -1;
    while(true){
        alpha = alpha_trace / 10.0;
        beta = 1.0 - alpha;
        cv::convertScaleAbs(src1,dst,alpha,beta);

        cvui::text(control_frame,10,10,"Alpha",0.4,0xff0000);
        cvui::trackbar(control_frame, 10, 30, 165, &alpha_trace, 0, 10);
        //cvui::text(control_frame,10,100,"Gamma",0.4,0xff0000);
        //cvui::trackbar(control_frame, 10, 120, 165, &beta_trace, 0, 10);

        cv::imshow("CTRL",control_frame);
        cv::imshow("SRC",src1);
        cv::imshow("DST",dst);

        cvui::update();


        key == cv::waitKey(10);
        if(key == 27){
            break;
        }

    }
    cv::destroyAllWindows();
    return 0;
}
