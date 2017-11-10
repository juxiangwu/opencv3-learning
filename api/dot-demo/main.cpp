#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main()
{
    Mat A=Mat::ones(2,3,CV_8UC1);
    Mat B=Mat::ones(2,3,CV_8UC1);

    A.at<uchar>(0,0)=1;
    A.at<uchar>(0,1)=2;
    A.at<uchar>(0,2)=3;
    A.at<uchar>(1,0)=4;
    A.at<uchar>(1,1)=5;
    A.at<uchar>(1,2)=6;

    B.at<uchar>(0,0)=1;
    B.at<uchar>(0,1)=2;
    B.at<uchar>(0,2)=3;
    B.at<uchar>(1,0)=4;
    B.at<uchar>(1,1)=5;
    B.at<uchar>(1,2)=6;

    double AB=A.dot(B);
    std::cout << "A.dot(B) = " << AB << std::endl;
    return 0;
}
