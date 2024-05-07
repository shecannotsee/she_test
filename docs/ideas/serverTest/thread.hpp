#ifndef _THREAD_HPP_
#define _THREAD_HPP_

#include <WS2tcpip.h>
#include <Winsock2.h>
#include <Windows.h>
#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <string>
/*
 * @param SOCKET c:�׽����ַ� 
 * @param int type:1Ϊ���գ�2Ϊ����
 * @param int index:1Ϊ��������2Ϊ�ͻ���
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
	std::string recvString;//���ջ�����
	std::string sendString;//���ͻ�����
	int buflen = 1024;//��������С
	char recvbuf[1024];


	if ((*temp).type == 1) {//����
		while (flag) {
			iResult = recv((*temp).c, recvbuf, 1024, 0);
			if (iResult > 0) {
				/* ���յ�������Ҫ��char*תΪstring */
				for (int i = 0; i < iResult; i++) {
					recvString += recvbuf[i];
				}
				/* ת������ */

				if ((*temp).index == 1){//�������յ�����Ϣ�����Կͻ��˵�
					std::cout << "Client:";
				}
				else if ((*temp).index == 2) {//�ͻ���
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
	else if ((*temp).type == 2) {//����
		while (flag) {
			std::cin >> sendString;
			/* ����ǰ��Ҫ��stringתΪchar* */
			//�ں�����ʹ��sendString.c_str()
			/* ת������ */
			iResult = send((*temp).c, sendString.c_str(), sendString.size(), 0);
			if (iResult > 0) {
				
			}
			sendString = "";
		}

	}
	else {//�쳣

	};
	return 0;
}



#endif // !_THREAD_HPP_




