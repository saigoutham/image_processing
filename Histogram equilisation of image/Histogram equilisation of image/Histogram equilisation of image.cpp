// Histogram equilisation of image.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include<iostream>
using namespace cv;
using namespace std;


int main()
{
	Mat imgb = imread("emma.JPG", 1);//converting image into grayscale and then equilising it 
	namedWindow("display", 1);
	imshow("display", imgb);
	if (imgb.empty())
	{
		cout << "Error : Image cannot be loaded ";
		system("pause");
		return -1;
	}
	
		Mat img;//changing image into grayscale and then equilising it
		cvtColor(imgb, img, CV_BGR2GRAY);
		equalizeHist(img, img);
		namedWindow("display1", 1);
		imshow("display1", img);
	
	Mat imgc = imread("emma.JPG", 1);
	if (imgc.empty())
	{
		cout << "Error : Image cannot be loaded ";
		system("pause");
		return -1;
	}
	
		//split image and then equilising one channel and then merging it
		Mat img1;
		cvtColor(imgc, img1, CV_BGR2YCrCb);
		vector<Mat>channels;
		split(img1, channels);
		equalizeHist(channels[0], channels[0]);
		merge(channels, img1);
		namedWindow("display2", 1);
		imshow("display2", img1);
		
	
	waitKey(0);
	destroyAllWindows();
	
    return 0;
}

