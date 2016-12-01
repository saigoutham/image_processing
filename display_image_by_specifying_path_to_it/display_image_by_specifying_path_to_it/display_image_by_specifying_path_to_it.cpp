// display_image_by_specifying_path_to_it.cpp : Defines the entry point for the console application.
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
		cout << "Error:";
		system("pause");
		return -1;

	}
	namedWindow("my_window", WINDOW_AUTOSIZE);
	imshow("my_window", img);
	waitKey(0);
	destroyWindow("my_window");
    return 0;
}

