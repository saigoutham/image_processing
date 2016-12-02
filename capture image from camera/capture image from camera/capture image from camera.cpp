// capture image from camera.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\highgui\highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		cout << "Error : ";
		system("pause");
		return -1;
	}
	double width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	cout << "Frame height :" << height << endl;
	cout << "Frame width : " << width << endl;
	namedWindow("Display",WINDOW_NORMAL);
	while (1)
	{
		Mat frame;
		bool check = cap.read(frame);
		if (!check)
		{
			break;
		}
		imshow("Display", frame);
		if (waitKey(30) == 27)
			break;
	}
    return 0;
}

