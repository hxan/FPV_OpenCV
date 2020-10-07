
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
#include <vector>
using namespace cv;
//头文件可以不用包含这么多
/*
	这个为摄像头数据接收端，在笔记本上运行,运行时可以把没必要的输出关闭
	命令./re 5099 & 运行
	killall re 结束运行
*/	
void camera_fun(int port)
{				
	/*
		port为笔记本接收端口,注意和工控机发送端口保持一zhi
	*/

	struct sockaddr_in addrRec;
	addrRec.sin_family = AF_INET;
	addrRec.sin_port = htons(port);//port
	addrRec.sin_addr.s_addr = inet_addr("127.0.0.1");//ip
	int sockClient = socket(AF_INET, SOCK_DGRAM, 0);

	bind(sockClient, (struct sockaddr*)&addrRec, sizeof(sockaddr_in));

	struct sockaddr_in addrSend;
	int nLen = sizeof(struct sockaddr_in);
		
	Mat frame;
		
	while (1)
	{
		std::vector<uchar> buff(65546);
		recvfrom(sockClient,&buff[0],65546, 0, NULL,NULL);//接收压缩的数据

		Mat frame= cv::imdecode(buff, -1);//解压
		imshow("receive", frame);//显示
		waitKey(1);
	}	

}


int main(int argc,char **argv)
{
    int port = atoi(argv[1] );
    camera_fun(port);
    return 0;
}        
