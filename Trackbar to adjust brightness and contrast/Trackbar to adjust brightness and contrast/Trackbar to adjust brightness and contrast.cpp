// Trackbar to adjust brightness and contrast.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include <iostream>
using namespace cv;
using namespace std;
Mat src;
int maxBrightness = 100;
int maxContrast = 100;

void brightnessControl(int brightnessValue, void *userdata)
{
	Mat img;
	;
	int brightness;
	brightness = brightnessValue - 50;
	
	src.convertTo(img, -1, 1, brightness);
	imshow("w", img);
}
void contrastControl(int contrastValue, void *userdata)
{
	Mat img;
	double contrast = contrastValue / 50.0;
	src.convertTo(img, -1, contrast, 0);
	imshow("w", img);
}

int main()
{
	 src = imread("emma.JPG", 1);
	if (src.data == false)
	{
		cout << "Image is not loaded ";
		system("pause");
		return -1;
	}
	namedWindow("w", 1);
	imshow("w", src);
	int brightnessValue = 50;
	int contrastValue = 50;
	createTrackbar("Brightness", "w", &brightnessValue, maxBrightness, brightnessControl, 0);

	createTrackbar("Contrast", "w", &contrastValue, maxContrast,contrastControl, 0);
	waitKey(0);
	destroyAllWindows();
    return 0;
}

