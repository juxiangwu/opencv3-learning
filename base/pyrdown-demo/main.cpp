#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/cvui.h>

using namespace std;
const std::string WINDOW_NAME = "CV3-pyrDown";

int main()
{
    cv::Mat pic = cv::imread("E:/Develop/projects/opencv3-learning/datas/f1.png");
    cv::namedWindow(WINDOW_NAME);
    cvui::init(WINDOW_NAME);
    char key = -1;
    cv::Mat frame = cv::Mat(cv::Size(pic.cols*2+20,pic.rows+30),pic.type());
    std::cout << pic.size() << frame.size() << std::endl;
    cv::Mat dst;
    while (true) {

        cvui::window(frame,0,0,pic.cols,pic.rows+30,"SRC");
        pic.copyTo(frame(cv::Rect(0,20,pic.cols,pic.rows)));
        cv::pyrDown(pic,dst);

        cvui::window(frame,pic.cols+10,0,pic.cols,pic.rows+30,"DST");

        dst.copyTo(frame(cv::Rect(pic.cols+10,20,dst.cols,dst.rows)));

        key = cv::waitKey(10);
        if(key == 27){
            break;
        }
        cvui::update();
        cv::imshow(WINDOW_NAME,frame);
    }
    return 0;
}
