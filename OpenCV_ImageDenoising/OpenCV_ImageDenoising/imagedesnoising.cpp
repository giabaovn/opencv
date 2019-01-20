#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	// load image
	Mat noisedImg = imread("img1.jpg");

	// denoising
	Mat denoisedImg;
	cv::fastNlMeansDenoisingColored(noisedImg, denoisedImg, 10, 10, 7, 21);

	// write the result
	imwrite("img2.jpg", denoisedImg);

	// create windows
	namedWindow("noisedImg", WINDOW_AUTOSIZE);
	namedWindow("denoisedImg", WINDOW_AUTOSIZE);

	// show images
	imshow("noisedImg", noisedImg);
	imshow("denoisedImg", denoisedImg);

	waitKey(0);
	return 0;
}