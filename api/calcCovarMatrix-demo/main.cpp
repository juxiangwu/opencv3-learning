#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat_<double> temp1(10, 3);
    Mat_<double> mean1, cov1;
    temp1(0, 0) = 49;
    temp1(0, 1) = 7;
    temp1(0, 2) = 29;

    temp1(1, 0) = 8;
    temp1(1, 1) = 19;
    temp1(1, 2) = 16;


    temp1(2, 0) = 12;
    temp1(2, 1) = 8;
    temp1(2, 2) = 14;

    temp1(3, 0) = 19;
    temp1(3, 1) = 37;
    temp1(3, 2) = 22;

    temp1(4, 0) = 3;
    temp1(4, 1) = 43;
    temp1(4, 2) = 21;


    temp1(5, 0) = 34;
    temp1(5, 1) = 17;
    temp1(5, 2) = 17;

    temp1(6, 0) = 20;
    temp1(6, 1) = 34;
    temp1(6, 2) = 27;

    temp1(7, 0) = 49;
    temp1(7, 1) = 14;
    temp1(7, 2) = 37;


    temp1(8, 0) = 20;
    temp1(8, 1) = 26;
    temp1(8, 2) = 21;

    temp1(9, 0) = 31;
    temp1(9, 1) = 41;
    temp1(9, 2) = 21;

    calcCovarMatrix(temp1, cov1, mean1, CV_COVAR_NORMAL | CV_COVAR_ROWS);
    cout << mean1 << endl;
    cout << cov1/9 << endl;
    return 0;
}
