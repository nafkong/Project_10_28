#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0);
	double scale = 0.5;

	double i_minH = 0;
	double i_maxH = 20;

	double i_minS = 43;
	double i_maxS = 255;

	double i_minV = 55;
	double i_maxV = 255;

	while (1)
	{
		Mat frame;
		Mat hsvMat;
		Mat detectMat;
		Mat faceMat, dstMat;

		cap >> frame;

		cvtColor(frame, hsvMat, COLOR_BGR2HSV);
		frame.copyTo(detectMat);
		cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);

		imshow("frame", frame);
		frame.copyTo(faceMat, detectMat);

		medianBlur(faceMat, dstMat, 3);
//		blur(faceMat, dstMat, Size(3, 3));
//		GaussianBlur(faceMat, dstMat, Size(3, 3), 3, 3);
		imshow("dstMat", dstMat);


		waitKey(30);

	}
}