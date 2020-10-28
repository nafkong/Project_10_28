#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() 
{
	VideoCapture cap(0);
	while (1)
	{
		Mat frame,dstMat;
		cap >> frame;
		medianBlur(frame, dstMat, 15);
		imshow("dstMat", dstMat);
		waitKey(30);

	}
}