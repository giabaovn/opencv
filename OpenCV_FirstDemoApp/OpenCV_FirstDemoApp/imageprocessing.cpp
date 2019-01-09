#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	// Load image
	Mat colorImg = imread("colorImg.jpg");

	// Convert to gray image
	Mat grayImg;
	cvtColor(colorImg, grayImg, COLOR_RGB2GRAY);
	imwrite("grayImg.jpg", grayImg);

	// Create windows
	namedWindow("colorImg", WINDOW_AUTOSIZE);
	namedWindow("grayImg", WINDOW_AUTOSIZE);

	// Show images
	imshow("colorImg", colorImg);
	imshow("grayImg", grayImg);

	waitKey(0);
	return 0;
}