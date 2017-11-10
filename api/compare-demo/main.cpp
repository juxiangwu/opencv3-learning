#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

void compute_staturation_single(cv::Mat & src,cv::Mat & dst){
    cv::MatIterator_< uchar > src_it = src.begin< uchar >();
    cv::MatIterator_< uchar > dst_it = dst.begin< uchar >();
    while(src_it != src.end< cv::Vec3b >()){
        (*dst_it) = cv::saturate_cast<uchar>(((*src_it) - 128)*2 +128);
        //(*dst_it)[1] = cv::saturate_cast<uchar>(((*src_it)[1] - 128)*2 +128);
        //(*dst_it)[2] = cv::saturate_cast<uchar>(((*src_it)[2] - 128)*2 +128);
        src_it++;
        dst_it++;
    }
}

int main()
{
    cv::Mat src = cv::imread("E:/Develop/projects/opencv3-learning/datas/f1.png",0);
    cv::Mat dst;

    //compute_staturation_single(src,dst);
    cv::Mat cmp_dst;

    cv::compare(src,50,cmp_dst,cv::CMP_EQ);

    cv::imshow("SRC",src);
    //cv::imshow("DST",dst);
    cv::imshow("CMP",cmp_dst);

    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}
