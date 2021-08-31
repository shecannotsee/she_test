#define _WINSOCK_DEPRECATED_NO_WARNINGS 	//比较新版的vs,会警告我们不要使用一
											//下旧的函数,因为提供更新更安全的函数供我们使用,在这呢我们
											//还是用旧的吧,这个宏定义就是起屏蔽警告作用,VS下面也有提示的
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <WS2tcpip.h>
#include <WinSock2.h>//一般情况下,这个头文件位于windows.h之前,避免发生某些错误
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")//显示加载 ws2_32.dll	ws2_32.dll就是最新socket版本啦

int main()
{
	std::cout << "-----------server-----------" << std::endl;

	// 1.初始化
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);//make word,你把鼠标移到WSAStartup看看参数列表,是不是就是一个word啊


	// 2.创建服务器的套接字
	SOCKET serviceSocket;
	serviceSocket = socket(AF_INET, SOCK_STREAM, 0);//socket(协议族,socket数据传输方式,某个协议),我们默认为0,其实就是一个宏
	if (SOCKET_ERROR == serviceSocket) {	
		std::cout << "Create socket error!" << std::endl;
	}
	else {
		std::cout << "Create socket success!" << std::endl;
	}


	// 3.绑定套接字,指定绑定的IP地址和端口号
	sockaddr_in socketAddr;//一个绑定地址:有IP地址,有端口号,有协议族
	socketAddr.sin_family = AF_INET;
	socketAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//代码开头第一行我们定义的宏在这就其作用啦
	socketAddr.sin_port = htons(1234);
	int bRes = bind(serviceSocket, (SOCKADDR*)&socketAddr, sizeof(SOCKADDR));//绑定注意的一点就是记得强制类型转换
	if (SOCKET_ERROR == bRes) {
		std::cout << "Bind error!" << std::endl;
	}
	else {
		std::cout << "Bind success!" << std::endl;
	}

	// 4.服务器监听	
	int lLen = listen(serviceSocket, 5);//监听的第二个参数就是:能存放多少个客户端请求,到并发编程的时候很有用哦
	if (SOCKET_ERROR == lLen) {
		std::cout << "Listen client error!" << std::endl;
	}
	else {
		std::cout << "Listen client success!!" << std::endl;
	}


	// 5.接受请求
	sockaddr_in revClientAddr;
	SOCKET recvClientSocket = INVALID_SOCKET;//初始化一个接受的客户端socket
	int _revSize = sizeof(sockaddr_in);
	recvClientSocket = accept(serviceSocket, (SOCKADDR*)&revClientAddr, &_revSize);
	if (INVALID_SOCKET == recvClientSocket) {
		std::cout << "Failed to receive request!" << std::endl;
	}
	else {
		std::cout << "Received the request successfully!" << std::endl << std::endl;
	}


	// 6.发送/接受 数据
	char recvBuf[1024] = {};
	int reLen = recv(recvClientSocket, recvBuf, 1024, 0);
	int sLen = send(recvClientSocket, recvBuf, reLen, 0);
	if (SOCKET_ERROR == reLen) {
		std::cout << "Failed to send data!" << std::endl;
	}
	else {
		std::cout << "Send data:" << recvBuf << std::endl << std::endl;
	}
		

	// 7.关闭socket
	closesocket(recvClientSocket);
	closesocket(serviceSocket);

	// 8.终止
	WSACleanup();

	std::cout << "Stop." << std::endl;
	return 0;
}
