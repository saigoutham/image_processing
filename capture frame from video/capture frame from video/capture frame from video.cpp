// capture frame from video.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;


int main()
{
	VideoCapture src("pv.mp4");
	if (!src.isOpened())
	{
		cout << "error :Video not loaded";
		system("pause");
		return -1;
	}
	src.set(CV_CAP_PROP_POS_MSEC, 50000);
	double height = src.get(CV_CAP_PROP_FRAME_HEIGHT);
	double width = src.get(CV_CAP_PROP_FRAME_WIDTH);
	double fps = src.get(CV_CAP_PROP_FPS);
	cout << "Height , Width and fps of video :" << height << width << fps;
	namedWindow("frames", 1);
	while (1)
	{
		Mat frame;
		bool check = src.read(frame);
		if (!check)
			break;
		imshow("frames", frame);
		if (waitKey(100) == 27)
			break;
	}
    return 0;
}

