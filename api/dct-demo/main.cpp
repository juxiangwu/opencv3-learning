#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat srcImage = imread("E:/Develop/projects/opencv3-learning/datas/f1.png");

    int height = srcImage.rows;
    int width = srcImage.cols;

    //从BGR空间转换到YUV颜色空间
    Mat yuvImage(srcImage.size(), CV_8UC3);
    cvtColor(srcImage, yuvImage, CV_BGR2YUV);
    //定义输出图像
    Mat dstImage(srcImage.size(), CV_64FC3);

    //分割YUV三个通道
    vector<Mat> channels;
    split(yuvImage, channels);

    //提取YUV颜色各个通道的值
    Mat y = channels.at(0); imshow("Y", y);
    Mat u = channels.at(1); imshow("U", u);
    Mat v = channels.at(2); imshow("V", v);

    //定义DCT系数的三个通道
    Mat DCTY(srcImage.size(), CV_64FC1);
    Mat DCTU(srcImage.size(), CV_64FC1);
    Mat DCTV(srcImage.size(), CV_64FC1);

    //进行DCT变换
    dct(Mat_<double>(y), DCTY);
    dct(Mat_<double>(u), DCTU);
    dct(Mat_<double>(v), DCTV);

    channels.at(0) = Mat_<uchar>(DCTY);
    channels.at(1) = Mat_<uchar>(DCTU);
    channels.at(2) = Mat_<uchar>(DCTV);

    merge(channels,dstImage);

    imshow("SRC",srcImage);
    imshow("DST-DCT",dstImage);

    waitKey();
    destroyAllWindows();

    return 0;
}
