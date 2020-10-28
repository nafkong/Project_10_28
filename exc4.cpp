#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

VideoCapture cap(0);

int main()
{
	while (1)
	{
		Mat frame, dstMat, image;
		cap >> frame;
//		cvtColor(frame, image, COLOR_BGR2GRAY);
		Sobel(frame, dstMat, CV_16SC1, 1, 0, 3);
//		Sobel(image, dstMat, CV_16SC1, 0, 1, 3);
		imshow("dstMat", dstMat);
		waitKey(30);
	}
}