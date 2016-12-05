// split image into HSV.cpp : Defines the entry point for the console application.
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
	Mat src = imread("emma.JPG", CV_LOAD_IMAGE_COLOR);
	namedWindow("original", WINDOW_AUTOSIZE);
	imshow("original", src);
	Mat zero = Mat::zeros(src.size(), CV_8UC1);
	Mat img,h_img,v_img,s_img;
	cvtColor(src, img, CV_BGR2HSV);
	vector<Mat>channels;
	split(img, channels);
	vector<Mat>h;
	////////////////////////////////////////////////////hue Componenent////////////////////////////////
	h.push_back(channels[0]);
	h.push_back(zero);
	h.push_back(zero);
	merge(h, h_img);
	namedWindow("hue", 1);
	imshow("hue", h_img);
	//////////////////////////////////////satuaration Component/////////////////////////////////////
	vector<Mat>s;
	s.push_back(zero);
	s.push_back(channels[1]);
	s.push_back(zero);
	merge(s, s_img);
	namedWindow("sat", 1);
	imshow("sat", s_img);
	////////////////////////////value component/////////////////////////////////////////////////
	vector<Mat>v;
	v.push_back(zero);
	v.push_back(zero);
	v.push_back(channels[2]);

	merge(v, v_img);
	namedWindow("value", 1);
	imshow("value", v_img);
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	waitKey(0);
	destroyAllWindows();
	
    return 0;
}

