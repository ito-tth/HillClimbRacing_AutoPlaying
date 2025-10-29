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
    // �摜�ƃe���v���[�g�摜�̓ǂݍ���
    cv::Mat image = cv::imread("screenshot.jpg", cv::IMREAD_COLOR);
    cv::Mat templ = cv::imread("sample.jpg", cv::IMREAD_COLOR);
    if (image.empty() || templ.empty()) {
        std::cerr << "�摜�̓ǂݍ��݂Ɏ��s���܂���" << std::endl;
        return -1;
    }
    // ���ʂ��i�[����s��̗p��
    cv::Mat result;
    // �e���v���[�g�}�b�`���O�̎��{�B���֌W�����K���@�𗘗p
    cv::matchTemplate(image, templ, result, cv::TM_CCOEFF_NORMED);
    // �ގ��x�}�b�v����ő�l�̈ʒu���擾
    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
    // ���o�����ʒu�ɋ�`��`��B��`�͐Ԃ��F�ŕ\��
    cv::rectangle(image, maxLoc, cv::Point(maxLoc.x + templ.cols, maxLoc.y + templ.rows), cv::Scalar(0, 0, 255), 2);
    // ���ʂ�\��
    cv::imshow("Detected", image);
    cv::waitKey(0);
    return 0;
}