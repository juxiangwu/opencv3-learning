#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    int sz[3] = { 4, 4, 4 };
    cv::Mat m( 3, sz, CV_32FC3 );
    cv::randu( m, -1.0f, 1.0f );
    float max = 0.0f;
    cv::MatConstIterator_< cv::Vec3f > it = m.begin< cv::Vec3f >();
    while( it != m.end< cv::Vec3f >() ) {
     float len2 = (*it)[0]*(*it)[0]+(*it)[1]*(*it)[1]+(*it)[2]*(*it)[2];
     if( len2 > max ) max = len2;
     it++;
    }
    std::cout << "max = " << max << std::endl;
    return 0;
}
