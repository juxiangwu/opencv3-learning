#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    char m1_data[3] = {1,2,3};
    char m2_data[3] = {1,1,1};
    cv::Mat m1(cv::Size(3,1),CV_8UC1,m1_data);
    cv::Mat m2(cv::Size(3,1),CV_8UC1,m2_data);

    std::cout << "m1:" << m1 << std::endl;
    std::cout << "m2:" << m2 << std::endl;

    cv::Mat dst = m1.cross(m2);
    std::cout << "m1.cross(m2):" << dst << std::endl;
    return 0;
}
