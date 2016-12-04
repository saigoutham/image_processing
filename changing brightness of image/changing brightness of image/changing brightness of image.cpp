// changing brightness of image.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\highgui\highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;


int main()
{
	Mat img = imread("emma.JPG", CV_LOAD_IMAGE_COLOR);
	if (img.empty())
	{
		cout << "image not loaded ";
		system("pause");
		return -1;
	}
	namedWindow("original", WINDOW_NORMAL);
	namedWindow("hb", WINDOW_NORMAL);
	namedWindow("lb", WINDOW_NORMAL);
	imshow("original", img);
	waitKey(0);
	

	Mat imgh = img + Scalar(75, 75, 75);
	Mat imgl = img + Scalar(-75, -75, -75);
	imshow("hb", imgh);
	waitKey(0);

	imshow("lb", imgl);
	waitKey(0);
	destroyAllWindows();
    return 0;
}

