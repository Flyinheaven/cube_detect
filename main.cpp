/*
	1.白色块和红色块容易丢失，不能大量出现在边上,狗则可能会丢失蓝色快导致出错
	2.棕色木板光照强时不易去除干净

	**可修改**：
				去背景阈值:木板背景去除问题
*/

	
#include "cube.hpp"



int main()
{
	cube_detector cube;
	Mat frame, dstImage1,result;
	int key=0;
	
	VideoCapture cap;
	// open the default camera using default API
	cap.open(0);
	// OR advance usage: select any API backend
	int deviceID = 0;             // 0 = open default camera
	int apiID = cv::CAP_ANY;      // 0 = autodetect default API
	// open selected camera using selected API
	cap.open(deviceID + apiID);
	if (!cap.isOpened()) {
		std::cerr << "ERROR! Unable to open camera\n";
		return -1;
	}
	else
	{
		cap >> frame;
		if (frame.empty()) {
			std::cerr << "ERROR! blank frame grabbed\n";
		}
		resize(frame, dstImage1, Size(frame.cols / 3, frame.rows / 3), 0, 0, INTER_LINEAR);
		//提取魔方，拿到魔方提取图
		result = cube.cube_Find(dstImage1);
		//拿到颜色分割图片，然后检测颜色
		key = cube.check_color(result);
	}
	return 0;
}
