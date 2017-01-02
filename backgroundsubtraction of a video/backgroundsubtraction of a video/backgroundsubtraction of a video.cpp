// backgroundsubtraction of a video.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"opencv2\core\core.hpp"
#include"opencv2\highgui\highgui.hpp"
#include"opencv2\imgproc\imgproc.hpp"
#include"opencv2\objdetect\objdetect.hpp"
#include"opencv2\video\video.hpp"
#include<iostream>
#include<stdio.h>
using namespace cv;
using namespace std;
//global variables
Mat frame;
Mat rframe;
Mat fgMOG;
Mat fgMOG2;
Mat fgGMG;



int main()
{
	Ptr<BackgroundSubtractorMOG>pMOG;
	Ptr<BackgroundSubtractorMOG2>pMOG2;
	Ptr<BackgroundSubtractorGMG>pGMG;
	pMOG = new BackgroundSubtractorMOG();
	pMOG2 = new BackgroundSubtractorMOG2();
	pGMG = new BackgroundSubtractorGMG();
	VideoCapture video;
	video.open("pv.mp4");
	if (!video.isOpened())
	{
		cout << "ERROR!!";
		system("pause");
		return -1;
	}
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(1, 1));
	while (true)
	{
		Mat dupframe;
		if (!(video.read(frame)))
			break;
		resize(frame, rframe, Size(frame.size().width / 4, frame.size().height / 4));
		pMOG->operator()(rframe, fgMOG);
		pMOG2->operator()(rframe, fgMOG2);
		pGMG->operator()(rframe, fgGMG);
		imshow("original", rframe);
		imshow("MOG", fgMOG);
		imshow("MOG2", fgMOG2);
		imshow("GMG", fgGMG);
		if (waitKey(30) >= 0)
			break;

	}
	destroyAllWindows();
    return 0;
}

