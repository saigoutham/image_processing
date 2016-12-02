// capture image from video.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\highgui\highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap("pv.mp4");
	if (!cap.isOpened())
	{
		cout << "Error : ";
		system("pause");
		return -1;
	}
	cap.set(CV_CAP_PROP_POS_MSEC, 1000);
	double fps = cap.get(CV_CAP_PROP_FPS);
	cout << "Frames per second : " << fps << endl;
	namedWindow("display", WINDOW_AUTOSIZE);

	while (1)
	{
		Mat frame;
		bool check = cap.read(frame);
		if (!check)
		{
			cout << "Error : ";
			break;
			
		}
		imshow("display", frame);
		if (waitKey(30) == 27)
		{
			break;
		}
	}
    return 0;
}

