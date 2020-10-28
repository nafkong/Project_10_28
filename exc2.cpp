#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

VideoCapture cap(0);

int main()
{
//	Mat kernel = (Mat_<float>(2, 2) << 1, 1, 1, 1);
	while (1)
	{
		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		Mat frame, dstMat;
		cap >> frame;
		blur(frame, dstMat, Size(3, 3));
		imshow("dstMat", dstMat);
		waitKey(30);
	}	
}