#ifndef _THREAD_HPP_
#define _THREAD_HPP_

#include <WS2tcpip.h>
#include <Winsock2.h>
#include <Windows.h>
#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <string>
/*
 * @param SOCKET c:套接字字符 
 * @param int type:1为接收，2为发送
 * @param int index:1为服务器，2为客户端
 */
struct socketAndType{
	SOCKET c;
	int type;
	int index;
};

DWORD WINAPI transmmit(const LPVOID arg)
{
	socketAndType* temp = (socketAndType*)arg;

	int flag = 1;
	int iResult;
	std::string recvString;//接收缓冲区
	std::string sendString;//发送缓冲区
	int buflen = 1024;//缓冲区大小
	char recvbuf[1024];


	if ((*temp).type == 1) {//接收
		while (flag) {
			iResult = recv((*temp).c, recvbuf, 1024, 0);
			if (iResult > 0) {
				/* 接收到数据需要把char*转为string */
				for (int i = 0; i < iResult; i++) {
					recvString += recvbuf[i];
				}
				/* 转换结束 */

				if ((*temp).index == 1){//服务器收到的消息是来自客户端的
					std::cout << "Client:";
				}
				else if ((*temp).index == 2) {//客户端
					std::cout << "Server:";//
				}
				else {
					std::cout << "error.";
					return 0;
				}
				std::cout << recvString << std::endl;

			}
			recvString = "";
		}
	}
	else if ((*temp).type == 2) {//发送
		while (flag) {
			std::cin >> sendString;
			/* 发送前先要把string转为char* */
			//在函数里使用sendString.c_str()
			/* 转换结束 */
			iResult = send((*temp).c, sendString.c_str(), sendString.size(), 0);
			if (iResult > 0) {
				
			}
			sendString = "";
		}

	}
	else {//异常

	};
	return 0;
}



#endif // !_THREAD_HPP_




