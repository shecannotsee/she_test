/* �ͻ��˳���ģ��
 * 1.��ʼ�� Winsock
 * 2.�����׽���
 * 3.���ӵ��÷�����
 * 4.���ͺͽ�������
 * 5.�Ͽ�����
 */
#include <WS2tcpip.h>
#include <Winsock2.h>
#include <Windows.h>
 //ʹ�� Winsock ��Ӧ�ó�������� Ws2 _ 32.lib ���ļ�����
#pragma comment(lib, "Ws2_32.lib")

#include "../Server/thread.hpp"

#include <iostream>
#include <string>

int main()
{   //__0.��������
    const char* ip   = "127.0.0.1"; //ip������ip������Ѷ������
    const char* port = "1234";     //�˿ںţ�DEFAULT_PORT
    int iResult = 0;

    //__1.��ʼ�� Winsock
    WSADATA wsaData;
    //��ʼ�����
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        /*��ʼ��ʧ��,�쳣�����*/
    }


    //__2.�����׽���
    struct addrinfo* result = NULL, * ptr = NULL, hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    //������������ַ�Ͷ˿�
    iResult = getaddrinfo(ip, port, &hints, &result);//����ip��˿ڣ��˿���ǰ������
    if (iResult != 0) {
        /*ʧ���쳣����*/
        WSACleanup();
    }
    SOCKET ConnectSocket = INVALID_SOCKET;
    //�������ӵ�����getaddrinfo���صĵ�һ����ַ
    ptr = result;
    //�����������ӵ���������SOCKET
    ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        /*�׽��ִ���ʧ�ܣ��쳣�����*/
        std::cout << "Create socket error.\n";
        freeaddrinfo(result);
        WSACleanup();
    }


    //__3.���ӵ��÷�����,������ip��˿�Ӧ�ڴ˲��趨��
    //���ӵ�������
    iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
    }
    //������Ӻ���ʧ��,��Ӧ��ʹ��getAddrinfo���ص���һ����ַ
    //��Ϊ����һ��������,����ֻ���ͷ���Դ
    freeaddrinfo(result);
    if (ConnectSocket == INVALID_SOCKET) {
        /*����ʧ��,һi����������*/
        std::cout << "Connection failed.\n";
        WSACleanup();
    }
    else {
        std::cout << "Connect server success.\n";
    }





    //__4.���ͺͽ�������
    //char recvbuf[1024];//������
    //char sendbuf[1024];//��������
    //int recvbuflen = 1024;//����������

    socketAndType* recvServer = new socketAndType;
    (*recvServer).c = ConnectSocket;
    (*recvServer).type = 1;//�����̱߳�ʶ
    (*recvServer).index = 2;//�ͻ���

    socketAndType* sendServer = new socketAndType;
    (*sendServer).c = ConnectSocket;
    (*sendServer).type = 2;//�����̱߳�ʶ
    (*sendServer).index = 2;//�ͻ���

    HANDLE hThread[2];//��ȡ���
    hThread[0] = CreateThread(NULL, 0, &transmmit, recvServer, 0, NULL);
    hThread[1] = CreateThread(NULL, 0, &transmmit, sendServer, 0, NULL);

    //�ȴ��߳����
    WaitForMultipleObjects(2, hThread, TRUE, INFINITE);

    delete recvServer; recvServer = nullptr;
    delete sendServer; sendServer = nullptr;

    

    

    ////_1.��������ģ��
    ////��ʼ�����ͻ�����
    //iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
    //if (iResult == SOCKET_ERROR) {
    //    /*��������ʧ��,�쳣�����*/
    //    closesocket(ConnectSocket);
    //    WSACleanup();
    //}
    //std::cout << "Bytes Sent:" << iResult << std::endl;

    ////�رշ���
    //iResult = shutdown(ConnectSocket, SD_SEND);
    //if (iResult == SOCKET_ERROR) {
    //    /*�ر�*/
    //    closesocket(ConnectSocket);
    //    WSACleanup();
    //}

    ////_2.��������ģ��
    ////��������,ֱ���������ر�����
    //do {
    //    iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
    //    if (iResult > 0) {
    //        std::cout << "Bytes received:" << iResult << std::endl;
    //        /*������ӽ������ݵ�չʾ*/
    //    }
    //    else if (iResult == 0) {
    //        /*���ӹر�,���쳣,�����*/
    //    }
    //    else {
    //        /*����ʧ��,�쳣�����*/
    //    }
    //} while (iResult > 0);






    //__5.�������Կͻ��˵�����
    //�رշ���һ�������,��Ϊû�и�������ݽ�������
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        /*�ر�����ʧ��,�쳣�����*/
        // closesocket(ConnectSocket);
        // WSACleanup();
    }
    //�ر��׽���,�ͷ���Դ
    closesocket(ConnectSocket);
    WSACleanup();
    std::cout << "Close socket.\n";



    return 0;
}