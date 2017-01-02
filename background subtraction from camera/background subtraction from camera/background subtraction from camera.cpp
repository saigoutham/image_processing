// background subtraction from camera.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"opencv2\core\core.hpp"
#include"opencv2\highgui\highgui.hpp"
#include"opencv2\objdetect\objdetect.hpp"
#include"opencv2\imgproc\imgproc.hpp"
#include"opencv2\video\video.hpp"
#include<iostream>
#include<stdio.h>
using namespace cv;
using namespace std;

Mat frame;
Mat rframe;
Mat fgGMG;

int main()
{
	Ptr<BackgroundSubtractorGMG>pGMG;
	pGMG = new BackgroundSubtractorGMG();
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		cout << "Error : ";
		system("pause");
		return -1;
	}
	while (true)
	{
		if (!cap.read(frame))
			break;
		resize(frame, rframe, Size(frame.size().width / 4, frame.size().height / 4));
		pGMG->operator()(rframe, fgGMG);
		imshow("original", rframe);
		imshow("GMG", fgGMG);
		if (waitKey(30) == 27)
			break;
		
	}

	destroyAllWindows();
    return 0;
}

