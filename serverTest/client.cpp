/* 客户端常规模型
 * 1.初始化 Winsock
 * 2.创建套接字
 * 3.连接到该服务器
 * 4.发送和接收数据
 * 5.断开连接
 */
#include <WS2tcpip.h>
#include <Winsock2.h>
#include <Windows.h>
 //使用 Winsock 的应用程序必须与 Ws2 _ 32.lib 库文件链接
#pragma comment(lib, "Ws2_32.lib")

#include "../Server/thread.hpp"

#include <iostream>
#include <string>

int main()
{   //__0.备用数据
    const char* ip   = "127.0.0.1"; //ip，外网ip：，腾讯服务器
    const char* port = "1234";     //端口号，DEFAULT_PORT
    int iResult = 0;

    //__1.初始化 Winsock
    WSADATA wsaData;
    //初始化检测
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        /*初始化失败,异常待添加*/
    }


    //__2.创建套接字
    struct addrinfo* result = NULL, * ptr = NULL, hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    //解析服务器地址和端口
    iResult = getaddrinfo(ip, port, &hints, &result);//填入ip与端口，端口在前面填入
    if (iResult != 0) {
        /*失败异常处理*/
        WSACleanup();
    }
    SOCKET ConnectSocket = INVALID_SOCKET;
    //尝试连接到调用getaddrinfo返回的第一个地址
    ptr = result;
    //创建用于连接到服务器的SOCKET
    ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        /*套接字创建失败，异常待添加*/
        std::cout << "Create socket error.\n";
        freeaddrinfo(result);
        WSACleanup();
    }


    //__3.连接到该服务器,服务器ip与端口应在此步骤定向
    //连接到服务器
    iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
    }
    //如果连接呼叫失败,则应该使用getAddrinfo返回的下一个地址
    //因为这是一个简单例子,所以只是释放资源
    freeaddrinfo(result);
    if (ConnectSocket == INVALID_SOCKET) {
        /*连接失败,一i经代码待添加*/
        std::cout << "Connection failed.\n";
        WSACleanup();
    }
    else {
        std::cout << "Connect server success.\n";
    }





    //__4.发送和接收数据
    //char recvbuf[1024];//缓冲区
    //char sendbuf[1024];//发送内容
    //int recvbuflen = 1024;//缓冲区长度

    socketAndType* recvServer = new socketAndType;
    (*recvServer).c = ConnectSocket;
    (*recvServer).type = 1;//接收线程标识
    (*recvServer).index = 2;//客户端

    socketAndType* sendServer = new socketAndType;
    (*sendServer).c = ConnectSocket;
    (*sendServer).type = 2;//发送线程标识
    (*sendServer).index = 2;//客户端

    HANDLE hThread[2];//获取句柄
    hThread[0] = CreateThread(NULL, 0, &transmmit, recvServer, 0, NULL);
    hThread[1] = CreateThread(NULL, 0, &transmmit, sendServer, 0, NULL);

    //等待线程完成
    WaitForMultipleObjects(2, hThread, TRUE, INFINITE);

    delete recvServer; recvServer = nullptr;
    delete sendServer; sendServer = nullptr;

    

    

    ////_1.发送数据模块
    ////初始化发送缓冲区
    //iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
    //if (iResult == SOCKET_ERROR) {
    //    /*发送数据失败,异常待添加*/
    //    closesocket(ConnectSocket);
    //    WSACleanup();
    //}
    //std::cout << "Bytes Sent:" << iResult << std::endl;

    ////关闭发送
    //iResult = shutdown(ConnectSocket, SD_SEND);
    //if (iResult == SOCKET_ERROR) {
    //    /*关闭*/
    //    closesocket(ConnectSocket);
    //    WSACleanup();
    //}

    ////_2.接收数据模块
    ////接收数据,直到服务器关闭连接
    //do {
    //    iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
    //    if (iResult > 0) {
    //        std::cout << "Bytes received:" << iResult << std::endl;
    //        /*可以添加接收数据的展示*/
    //    }
    //    else if (iResult == 0) {
    //        /*连接关闭,非异常,待添加*/
    //    }
    //    else {
    //        /*接收失败,异常待添加*/
    //    }
    //} while (iResult > 0);






    //__5.接受来自客户端的连接
    //关闭发送一半的连接,因为没有更多的数据将被发送
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        /*关闭连接失败,异常待添加*/
        // closesocket(ConnectSocket);
        // WSACleanup();
    }
    //关闭套接字,释放资源
    closesocket(ConnectSocket);
    WSACleanup();
    std::cout << "Close socket.\n";



    return 0;
}