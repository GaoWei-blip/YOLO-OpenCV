# include "yolo.h"
# include "yolov5.h"



int main()
{
	// 读取模型结构和参数
	/*
	Net_config yolo_nets[4] = {
	{0.5, 0.4, 416, 416,"../model/coco.names", "../model/yolov3/yolov3.cfg", "../model/yolov3/yolov3.weights", "yolov3"},
	{0.5, 0.4, 608, 608,"../model/coco.names", "../model/yolov4/yolov4.cfg", "../model/yolov4/yolov4.weights", "yolov4"},
	{0.5, 0.4, 320, 320,"../model/coco.names", "../model/yolo-fastest/yolo-fastest-xl.cfg", "../model/yolo-fastest/yolo-fastest-xl.weights", "yolo-fastest"},
	{0.5, 0.4, 320, 320,"../model/coco.names", "../model/yolobile/csdarknet53s-panet-spp.cfg", "../model/yolobile/yolobile.weights", "yolobile"}
	};
	YOLO yolo_model(yolo_nets[0]);  
	*/

	Net_config_v5 yolo_nets[5] = {
	{0.5, 0.5, 0.5, "../model/coco.names", "../model/yolov5/yolov5s.onnx", "yolov5s"},
	{0.5, 0.5, 0.5, "../model/coco.names", "../model/yolov5/yolov5s6.onnx", "yolov5s6"},
	{0.5, 0.5, 0.5, "../model/coco.names", "../model/yolov5/yolov5m.onnx", "yolov5m"},
	{0.5, 0.5, 0.5, "../model/coco.names", "../model/yolov5/yolov5l.onnx", "yolov5l"},
	{0.5, 0.5, 0.5, "../model/coco.names", "../model/yolov5/yolov5x.onnx", "yolov5x"}
	};
	YOLOv5 yolo_model(yolo_nets[0]);  
	
	// 读取、推理、显示
	string imgpath = "../images/person.jpg";
	Mat srcimg = imread(imgpath);
	yolo_model.detect(srcimg);

	static const string kWinName = "Deep learning object detection in OpenCV";
	namedWindow(kWinName, WINDOW_NORMAL);
	imshow(kWinName, srcimg);
	waitKey(0);
	destroyAllWindows();
}