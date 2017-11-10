#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat   T;
    Mat   A=Mat::eye(1,3,CV_32FC1);
    Mat   C=Mat::eye(3,3,CV_32FC1);
    std::cout<<"A="<<A<<std::endl<<"C="<<C<<std::endl;
    gemm(A,C,1,10,0,T,0);//the src3 can't be 0,so if you

    std::cout<<"T="<<T;

    return 0;
}
