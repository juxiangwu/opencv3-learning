#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/cvui.h>

using namespace std;
const std::string WINDOW_NAME = "SRC";
int main()
{
    cv::Mat frame = cv::Mat(640, 480, CV_8UC3);
    bool checked = false;
    int count = 0;

    cv::namedWindow(WINDOW_NAME);
    cvui::init(WINDOW_NAME);

    while (true) {
        frame = cv::Scalar(49, 52, 49);

        cvui::text(frame, 50, 30, "Hey there!");
        cvui::text(frame, 200, 30, "Use hex 0xRRGGBB colors easily", 0.4, 0xff0000);

        if (cvui::button(frame, 50, 50, "Button")) {
            std::cout << "Button clicked!" << std::endl;
        }

        cvui::window(frame, 50, 100, 120, 100, "Window");
        cvui::counter(frame, 200, 100, &count);
        cvui::checkbox(frame, 200, 150, "Checkbox", &checked);

        cvui::update();

        cv::imshow(WINDOW_NAME, frame);
        char key = cv::waitKey(10);
        if(key == 27){
            break;
        }
    }

    return 0;
}
