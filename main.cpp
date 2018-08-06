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
	
	//摄像头读入一张图片（原图）
	Mat frame = imread("E://picture/a.jpg");
	//imshow("原图", frame);
	
	//缩小尺寸
	Mat dstImage1;
	resize(frame, dstImage1, Size(frame.cols /5 , frame.rows / 5), 0, 0, INTER_LINEAR);
	imshow("缩小图", dstImage1);
	
	//提取魔方，拿到魔方提取图
	Mat result = cube.cube_Find(dstImage1);
	
	//拿到颜色分割图片，然后检测颜色
	int key = cube.check_color(result);
	if (key==1)
		cout << "not complete";
	else        
		cout << "complete";


	waitKey(0);
	return 0;
}
