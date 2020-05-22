#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat frame, bgMat, subMat, bny_subMat;
	VideoCapture capVideo(0);
	int cnt = 0;

	while (1)
	{
		capVideo >> frame;
		cvtColor(frame,frame,COLOR_BGR2GRAY);

		if (cnt == 0)
		{
			//第一帧，获得背景图像
			frame.copyTo(bgMat);
		}
		else
		{
			//第二帧开始背景差分
			//背景图像和当前图像相减
			absdiff(frame, bgMat, subMat);
			//差分结果二值化
			threshold(subMat, bny_subMat, 50, 255, THRESH_BINARY);
			
			imshow(" bny_subMat", bny_subMat);
			imshow(" subMat", subMat);
			waitKey(30);
		}
		cnt++;
	}
	return 0;
}

