// background subtraction of images.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"opencv2\highgui\highgui.hpp"
#include"opencv2\imgproc\imgproc.hpp"
#include"opencv2\objdetect\objdetect.hpp"
#include"opencv2\video\video.hpp"
#include<iostream>
#include<stdio.h>
using namespace cv;
using namespace std;


int main()
{
	Mat src, des;
	src = imread("src.PNG",1);
	des = imread("des.PNG",1);
	//cvtColor(src, src, CV_BGR2GRAY);
	//cvtColor(des, des, CV_BGR2GRAY);
	namedWindow("src", CV_WINDOW_NORMAL);

	namedWindow("diff", CV_WINDOW_NORMAL);
	namedWindow("des", CV_WINDOW_NORMAL);
	Mat output;
	absdiff(src, des, output);
	threshold(output, output, 10, 255, THRESH_BINARY);
	//cvtColor(output, output, CV_GRAY2BGR);
	imshow("src", src);
	imshow("des", des);
	imshow("diff", output);
	waitKey(0);
	destroyAllWindows();
    return 0;
}

