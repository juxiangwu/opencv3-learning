#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    cv::Mat src = cv::imread("E:/Develop/projects/opencv3-learning/datas/f1.png");

    cv::Mat dst(src.size(),src.type());

    cv::MatIterator_< cv::Vec3b > src_it = src.begin< cv::Vec3b >();
    cv::MatIterator_< cv::Vec3b > dst_it = dst.begin< cv::Vec3b >();
    while(src_it != src.end< cv::Vec3b >()){
        (*dst_it)[0] = cv::saturate_cast<uchar>(((*src_it)[0] - 128)*2 +128);
        (*dst_it)[1] = cv::saturate_cast<uchar>(((*src_it)[1] - 128)*2 +128);
        (*dst_it)[2] = cv::saturate_cast<uchar>(((*src_it)[2] - 128)*2 +128);
        src_it++;
        dst_it++;
    }
    cv::imshow("SRC",src);
    cv::imshow("DST",dst);
    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}
