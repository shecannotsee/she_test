/* 客户端常规模型
 * 1.初始化 Winsock。
 * 2.创建套接字。
 * 3.连接到该服务器。
 * 4.发送和接收数据。
 * 5.接受来自客户端的连接。
 */
#include <WS2tcpip.h>
#include <Winsock2.h>
#include <Windows.h>
//使用 Winsock 的应用程序必须与 Ws2 _ 32.lib 库文件链接
#pragma comment(lib, "Ws2_32.lib")

#include <iostream>

int main()
{   //__0.备用数据
    const char* port = "27011" ;//端口号，DEFAULT_PORT
    int iResult = 0 ;
    
    //__1.初始化 Winsock
    WSADATA wsaData;
    //初始化检测
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        /*初始化失败,异常待添加*/
    }


    //__2.创建套接字
    struct addrinfo *result = NULL,*ptr = NULL, hints;
    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    //解析服务器地址和端口
    iResult = getaddrinfo(argv[1], port, &hints, &result);
    if (iResult != 0) {
        /*失败异常处理*/
        WSACleanup();
    }
    SOCKET ConnectSocket = INVALID_SOCKET;
    //尝试连接到调用getaddrinfo返回的第一个地址
    ptr=result;
    //创建用于连接到服务器的SOCKET
    ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        /*套接字创建失败，异常待添加*/
        freeaddrinfo(result);
        WSACleanup();
    }


    //__3.连接到该服务器
    // Connect to server.
    iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
    }

    // Should really try the next address returned by getaddrinfo
    // if the connect call failed
    // But for this simple example we just free the resources
    // returned by getaddrinfo and print an error message
    freeaddrinfo(result);
    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }


    //__4.发送和接收数据



    //__5.接受来自客户端的连接



    return 0;
}