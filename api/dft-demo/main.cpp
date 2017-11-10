#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat src = imread("E:/Develop/projects/opencv3-learning/datas/f1.png");
    Mat gray;
    cvtColor(src,gray,COLOR_RGB2GRAY);

    //这里获取符合快速傅里叶变换（FFT）的大小，m和n都可以分解为2、3、5相乘的组合，参见 注1
    int M = getOptimalDFTSize( src.rows );
    int N = getOptimalDFTSize( src.cols );

    Mat padded;
    //将原图像的大小变为m*n的大小，补充的位置填0，
    copyMakeBorder(gray, padded, 0, M - gray.rows, 0, N - gray.cols, BORDER_CONSTANT, Scalar::all(0));
    //这里是获取了两个mat，一个用于存放dft变换的实部，一个用于存放虚部，初始的时候，实部就是图像本身，虚部全为0
    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};

    Mat complexImg;
    //将几个单通道的mat融合成一个多通道的mat，这里融合的complexImg即有实部，又有虚部
    merge(planes, 2, complexImg);
    //dft变换，因为complexImg本身就是两个通道的mat，所以dft变换的结果也可以保存在其中
    dft(complexImg, complexImg);
    //将complexImg重新拆分成两个mat，一个是实部，一个是虚部
    split(complexImg, planes);

    // compute log(1 + sqrt(Re(DFT(img))**2 + Im(DFT(img))**2))
    //这一部分是为了计算dft变换后的幅值，以便于显示幅值的计算公式如上
    magnitude(planes[0], planes[1], planes[0]);//将两个mat对应位置相乘
    Mat magI = planes[0];
    magI += Scalar::all(1);
    log(magI, magI);

    // crop the spectrum, if it has an odd number of rows or columns
    //修剪频谱，如果图像的行或者列是奇数的话，那其频谱是不对称的，因此要修剪
    //这里为什么要用  &-2这个操作，我会在代码后面的 注2 说明
    magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));
    Mat _magI = magI.clone();
    normalize(_magI, _magI, 0, 1, CV_MINMAX);
    imshow("before rearrange ",_magI);

    int cx = magI.cols/2;
    int cy = magI.rows/2;
    // rearrange the quadrants of Fourier image
    // so that the origin is at the image center
    Mat tmp;
    Mat q0(magI, Rect(0, 0, cx, cy));
    Mat q1(magI, Rect(cx, 0, cx, cy));
    Mat q2(magI, Rect(0, cy, cx, cy));
    Mat q3(magI, Rect(cx, cy, cx, cy));

    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

    normalize(magI, magI, 0, 1, CV_MINMAX);

    imshow("spectrum magnitude", magI);

    imshow("SRC",src);


    waitKey();
    destroyAllWindows();

    return 0;
}
