#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main()
{
    vector<Point2f> sides;//建立容器存坐标
     sides.push_back(Point2f(3, 4));
     sides.push_back(Point2f(6, 8));
     sides.push_back(Point2f(1, 1));
     Mat xpts(sides.size(), 1, CV_32F, &sides[0].x, 2 * sizeof(float));
     Mat ypts(sides.size(), 1, CV_32F, &sides[0].y, 2 * sizeof(float));
     cout << "x: " << xpts.t() << endl;
     cout << "y: " << ypts.t() << endl;
     Mat magnitude, angle;
     cartToPolar(xpts, ypts, magnitude, angle);//调用库函数
     cout << "\nmagnitude: " << magnitude.t();
     cout << "\nangle: " << angle.t() *180. / CV_PI <<endl;
    return 0;
}
