#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/cvui.h>

using namespace std;

#define WINDOW_NAME "CVUI Canny Edge"

int main(void)
{
    cv::Mat pic = cv::imread("E:/Develop/projects/opencv3-learning/datas/f1.png");
    int width = pic.rows, height = pic.cols;
    cv::Mat frame = cv::Mat(cv::Size(width + 30, height), 0);
    int low_threshold = 50, high_threshold = 150;
    bool use_canny = false;

    cv::namedWindow(WINDOW_NAME);
    cvui::init(WINDOW_NAME);

    while (cv::waitKey(30) != 27) {
        if (use_canny) {
            cv::cvtColor(pic, frame, CV_BGR2GRAY);
            cv::Canny(frame, frame, low_threshold, high_threshold, 3);
        }
        else {
            pic.copyTo(frame);
        }

        cvui::window(frame, 360, 50, 180, 180, "Setting");
        cvui::checkbox(frame, 375, 80, "Use Canny Edge", &use_canny);
        cvui::trackbar(frame, 375, 110, 165, &low_threshold, 5, 150);
        cvui::trackbar(frame, 375, 180, 165, &high_threshold, 80, 300);

        cvui::update();
        cv::imshow(WINDOW_NAME, frame);


    }
    return 0;
}
