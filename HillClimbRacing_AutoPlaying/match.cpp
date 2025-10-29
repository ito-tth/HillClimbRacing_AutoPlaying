#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include"function.h"

/*
#ifdef _DEBUG
#pragma comment(lib, "opencv_world4120d.lib")
#else
#pragma comment(lib, "opencv_world4120.lib")
#endif
*/

int match() {
    // 画像とテンプレート画像の読み込み
    cv::Mat image = cv::imread("screenshot.jpg", cv::IMREAD_COLOR);
    cv::Mat templ = cv::imread("sample.jpg", cv::IMREAD_COLOR);
    if (image.empty() || templ.empty()) {
        std::cerr << "画像の読み込みに失敗しました" << std::endl;
        return -1;
    }
    // 結果を格納する行列の用意
    cv::Mat result;
    // テンプレートマッチングの実施。相関係数正規化法を利用
    cv::matchTemplate(image, templ, result, cv::TM_CCOEFF_NORMED);
    // 類似度マップから最大値の位置を取得
    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
    // 検出した位置に矩形を描画。矩形は赤い色で表現
    cv::rectangle(image, maxLoc, cv::Point(maxLoc.x + templ.cols, maxLoc.y + templ.rows), cv::Scalar(0, 0, 255), 2);
    // 結果を表示
    cv::imshow("Detected", image);
    cv::waitKey(0);
    return 0;
}