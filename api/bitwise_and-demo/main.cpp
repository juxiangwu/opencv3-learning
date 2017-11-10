#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    cv::Mat src1 = cv::imread("E:/Develop/projects/opencv3-learning/datas/c1.jpg");
    cv::Mat src2 = cv::imread("E:/Develop/projects/opencv3-learning/datas/sk1.jpg");
    cv::Mat dst;

    cv::bitwise_and(src1,src2,dst);

    cv::imshow("SRC1",src1);
    cv::imshow("SRC2",src2);
    cv::imshow("DST",dst);
    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}
