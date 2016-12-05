// Detect mouse click and other events.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
void mouseEvents(int event, int x, int y, int flag, void *userdata)
{
	if (event == CV_EVENT_RBUTTONDBLCLK)
		cout << "Right mouse butteon is clicked\n ";
	else if (event == CV_EVENT_LBUTTONDOWN)
		cout << "left mouse butteon is pushedDown\n ";
	else if (event == CV_EVENT_MOUSEMOVE)
		cout << "Mouse is moved over the window \n";
	else if (flag == CV_EVENT_FLAG_MBUTTON)
		cout << " mouse butteon is pushedDown\n ";
	else if (flag == (CV_EVENT_FLAG_ALTKEY + CV_EVENT_FLAG_LBUTTON))
		cout << "alt key+left mouse button is clicked\n ";
}
int main()
{
	Mat img = imread("emma.JPG", 1);
	if (img.data == false)
	{
		cout << "Image not loaded :";
		system("pause");
		return -1;
	}
	namedWindow("display", WINDOW_NORMAL);
	setMouseCallback("display", mouseEvents, NULL);
	imshow("display", img);
	waitKey(0);
    return 0;
}

