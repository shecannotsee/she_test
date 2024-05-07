/* ����������ģ��
 * 1.��ʼ�� Winsock
 * 2.�����׽���
 * 3.���׽���
 * 4.���׽����������ͻ���
 * 5.�������Կͻ��˵�����
 * 6.���պͷ�������
 * 7.�Ͽ�����
 */
//#define _WIN32_WINNT 0x0501//getaddrinfo
#include <WS2tcpip.h>
#include <Winsock2.h>
#include <Windows.h>
 //ʹ�� Winsock ��Ӧ�ó�������� Ws2 _ 32.lib ���ļ�����
#pragma comment(lib, "Ws2_32.lib")

#include "thread.hpp"
#include <iostream>

int main() {
    //__0.��������
    const char* ip = "127.0.0.1"; //ip������ip��
    const char* port = "1234";//�˿ںţ�DEFAULT_PORT
    int iResult = 0;


    //__1.��ʼ�� Winsock
    WSADATA wsaData;
    //��ʼ�����
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        /*��ʼ��ʧ��,�쳣�����*/
    }


    //__2.�����׽���
    //Getaddrinfo��������ȷ��sockaddr�ṹ�е�ֵ,Addrinfo�ṹ��getaddrinfo����ʹ�á�
    struct addrinfo* result = NULL, * ptr = NULL, hints;
    ZeroMemory(&hints, sizeof(hints)); //�����ڴ沢��0��ʼ��,��windows
    hints.ai_family = AF_INET;        //IPv4
    hints.ai_socktype = SOCK_STREAM;    //���׽���
    hints.ai_protocol = IPPROTO_TCP;    //����tcpЭ��
    hints.ai_flags = AI_PASSIVE;     //
    //���������ʹ�õı��ص�ַ�Ͷ˿�
    iResult = getaddrinfo(ip, port, &hints, &result);
    if (iResult != 0) {
        /*ʧ���쳣����*/
        std::cout << "getaddrinfo error.\n";
        WSACleanup();
    }
    SOCKET ListenSocket = INVALID_SOCKET;
    //Ϊ����������һ���׽����������ͻ�������
    ListenSocket = socket((*result).ai_family, (*result).ai_socktype, (*result).ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        /*�����׽���ʧ��,�쳣�����*/
        std::cout << "Create socket error.\n";
        freeaddrinfo(result);
        WSACleanup();
    }; MSG_DONTROUTE;


    //__3.���׽���
    //����TCP�����׽���
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        /*�׽��ְ������ַʧ��,�쳣�����*/
        std::cout << "Bind error.\n";
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
    }
    //������Ҫ getaddrinfo �������صĵ�ַ��Ϣ,�ͷŷ����ڴ�
    //freeaddrinfo(result);


    //__4.���׽����������ͻ���
    if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
        /*����ʧ�ܣ��쳣�����*/
        std::cout << "Listen socket error.\n";
        closesocket(ListenSocket);
        WSACleanup();
    }


    //__5.�������Կͻ��˵�����
    //������ΪClientSocket����ʱ�׽��ֶ���,�Խ������Կͻ��˵�����
    SOCKET ClientSocket = INVALID_SOCKET;
    //���ڸ����ܷ�������ͨ��ʹ�ö���߳����������ͻ�������
    //�м��ֲ�ͬ�ı�̼���ʹ��Winsock,��������������ͻ�������
    //һ�ֱ�̷����Ǵ���һ������ѭ��,��ѭ��ʹ��listen���������������
    //���������������,Ӧ�ó��򽫵���accept,AcceptEx,WSAAccept ����
    //�����������ݵ���һ���߳�����������
    std::cout << "Wait to accept from client.\n";
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        /*���ܿͻ���ʧ�ܣ��쳣�����*/
        std::cout << "Accept socket error.\n";
        closesocket(ListenSocket);
        WSACleanup();
    }






    //__6.���պͷ�������
    //int iSendResult;
    //char recvbuf[1024];//���ջ�����
    //char sendbuf[1024];//���ͻ�����
    //int recvbuflen = 1024;//��������С

    socketAndType* recvClient = new socketAndType;
    (*recvClient).c     = ClientSocket;
    (*recvClient).type  = 1;//�����̱߳�ʶ
    (*recvClient).index = 1;//�ͻ���
    //������
    socketAndType* sendClient = new socketAndType;
    (*sendClient).c = ClientSocket;
    (*sendClient).type = 2;//�����̱߳�ʶ
    (*sendClient).index = 1;//������

    HANDLE hThread[2];//��ȡ���
    hThread[0] = CreateThread(NULL, 0,&transmmit , recvClient, 0, NULL);
    hThread[1] = CreateThread(NULL, 0, &transmmit, sendClient, 0, NULL);

    //�ȴ��߳����
    WaitForMultipleObjects(2, hThread, TRUE, INFINITE);

    ////���գ�ֱ���Է��ر�����
    //do {
    //    iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
    //    if (iResult > 0) {
    //        std::cout << "Bytes received: " << iResult << std::endl;

    //        //���������ش������ͷ�
    //        iSendResult = send(ClientSocket, recvbuf, iResult, 0);
    //        if (iSendResult == SOCKET_ERROR) {
    //            /*��������ʧ��,�쳣�����*/
    //            closesocket(ClientSocket);
    //            WSACleanup();
    //        }
    //        std::cout << "Bytes sent:" << iSendResult << std::endl;
    //    }
    //    else if (iResult == 0) {
    //        /*�����ѶϿ�,�쳣�����*/
    //    }
    //    else {
    //        /*��������ʧ��,�쳣�����*/
    //        closesocket(ClientSocket);
    //        WSACleanup();
    //    }
    //} while (iResult > 0);






    //__7.�Ͽ�����
    //�رշ���һ�������,��Ϊû�и�������ݽ�������
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        /*�Ͽ��׽���ʧ��,�쳣�����*/
        closesocket(ClientSocket);
        WSACleanup();
    }
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}



