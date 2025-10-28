#include <opencv2/opencv.hpp>
#include <iostream>

#ifdef _DEBUG
#pragma comment(lib, "opencv_world4120d.lib")
#else
#pragma comment(lib, "opencv_world4120.lib")
#endif


int main() {
    // �摜��ǂݍ��ށi�����t�H���_�� test.jpg ��u���Ă��������j
    cv::Mat img = cv::imread("test.jpg");

    if (img.empty()) {
        std::cout << "�摜���ǂݍ��߂܂���ł����B" << std::endl;
        return -1;
    }

    // �E�B���h�E�ɉ摜��\��
    cv::imshow("�\���e�X�g", img);
    cv::waitKey(0); // �L�[���͑҂�
    return 0;
}