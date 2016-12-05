// Modify Brightness Contrast Of image.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;


int main()
{
	Mat img = imread("emma.JPG", CV_LOAD_IMAGE_COLOR);
	if (img.empty())
	{
		cout << "Error : Image is not loaded ";
		system("pause");
		return -1;
	}
		namedWindow("original", 1);
		imshow("original", img);
Mat imghb, imglb, imghc, imglc;
	img.convertTo(imghb, -1, 1, 75);
	namedWindow("highBrightness", 1);
	imshow("highBrightness", imghb);
		img.convertTo(imglb, -1, 1, -75);
		namedWindow("LowBrightness", 1);
		imshow("LowBrightness", imglb);
	img.convertTo(imghc, -1, 2, 0);
	namedWindow("highContrast", 1);
	imshow("highContrast", imghc);
		img.convertTo(imglc, -1, 0.5, 75);
		namedWindow("lowContrast", 1);
		imshow("lowContrast", imglc);
		waitKey(0);
		destroyAllWindows();
    return 0;
}

