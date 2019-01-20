#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main() {

	// create vector for images
	vector<Mat> buffer(5);

	// load images
	// create 5 Mat object for showing
	Mat img1 = imread("im1.jpg", IMREAD_COLOR);
	buffer[0] = img1;

	Mat img2 = imread("im2.jpg", IMREAD_COLOR);
	buffer[1] = img2;

	Mat img3 = imread("im3.jpg", IMREAD_COLOR);
	buffer[2] = img3;

	Mat img4 = imread("im4.jpg", IMREAD_COLOR);
	buffer[3] = img4;

	Mat img5 = imread("im5.jpg", IMREAD_COLOR);
	buffer[4] = img5;

	// denoising color multi
	Mat desnoisedImg;
	int imgs_count = buffer.size();
	cv::fastNlMeansDenoisingColoredMulti(buffer, desnoisedImg, imgs_count / 2, imgs_count, 10, 10, 7, 21);

	// show all images
	imshow("noisedImg1", img1);
	imshow("noisedImg2", img2);
	imshow("noisedImg3", img3);
	imshow("noisedImg4", img4);
	imshow("noisedImg5", img5);
	imshow("desnoisedImg", desnoisedImg);

	waitKey(0);
	return 0;
}