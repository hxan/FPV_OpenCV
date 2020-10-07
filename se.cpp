#include<opencv2/opencv.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/tracking.hpp>
#include<opencv2/core/ocl.hpp>
#include<stdio.h>
#include<stdio.h>
#include <sys/socket.h>
#include<string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include<time.h>
using namespace cv;

void camera_fun(char ip[],int port ,int device,int quality){

	int sum=0;
	struct sockaddr_in addrRec;
	addrRec.sin_family = AF_INET;
	addrRec.sin_port = htons(port);//
	addrRec.sin_addr.s_addr = inet_addr(ip);//
	int sockClient = socket(AF_INET, SOCK_DGRAM, 0);
	int nLen = sizeof(sockaddr_in);
 

	cv::VideoCapture capture(device);
	cv::Mat capframe;
	std::vector<int> params;
	params.push_back(cv::IMWRITE_JPEG_QUALITY);
	params.push_back(quality);
	while (1)
	{
		capture >> capframe;
		std::vector<uchar> buff;
		cv::imencode(".jpg", capframe, buff, params);
		Mat frame= cv::imdecode(buff, -1);
		sendto(sockClient, (char *)&buff[0],buff.size() , 0, (struct sockaddr*)&addrRec, nLen);
		waitKey(10);
	}
}
int main(int argc,char **argv)
{
	char *ip=argv[1];
	int port = atoi(argv[2] );

	int device= atoi(argv[3]);
	int quality=atoi(argv[4]);
	
	camera_fun(ip,port,device,quality);
    return 0;
}
