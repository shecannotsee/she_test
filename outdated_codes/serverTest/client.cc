#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <WS2tcpip.h>
#include <WinSock2.h>
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll

int main()
{
	std::cout << "-----------client-----------" << std::endl;

	// 1.初始化
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);


	// 2.创建套接字
	SOCKET clientSocket = {};
	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (SOCKET_ERROR == clientSocket) {
		std::cout << "creatr socket error!" << std::endl;
	}
	else {
		std::cout << "creatr socket success!" << std::endl << std::endl;
	}


	//3.绑定套接字,指定绑定的IP地址和端口号
	sockaddr_in socketAddr;
	socketAddr.sin_family = PF_INET;
	socketAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	socketAddr.sin_port = htons(1234);
	int cRes = connect(clientSocket, (SOCKADDR*)&socketAddr, sizeof(SOCKADDR));
	if (SOCKET_ERROR == cRes) {
		std::cout << "Error to connect server....." << std::endl;	
	}
	else {
		std::cout << "Success to connect server....." << std::endl;		
	}


	//4.发送请求
	char sendBuf[1024] = "this is a data from client";
	send(clientSocket, sendBuf, strlen(sendBuf), 0);


	//5.发送/接受 数据
	char recvBuf[1024] = {};
	recv(clientSocket, recvBuf, 1024, 0);
	std::cout << "Get data from server:" << recvBuf << std::endl << std::endl;
	

	//6.关闭socket
	closesocket(clientSocket);


	//7.终止
	WSACleanup();

	std::cout << "Quit." << std::endl;
	return 0;
}
