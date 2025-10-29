#include <opencv2/opencv.hpp>
#include <iostream>
#include"function.h"

#ifdef _DEBUG
#pragma comment(lib, "opencv_world4120d.lib")
#else
#pragma comment(lib, "opencv_world4120.lib")
#endif

int main() {
	cv::Mat screen = captureScreenMat();
	cv::imwrite("screenshot.jpg", screen);
	//cv::imshow("スクリーンショット", screen);
	match();
	cv::waitKey(0);
	cursorMove();
	return 0;
}