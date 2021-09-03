/* 服务器常规模型
 * 1.初始化 Winsock
 * 2.创建套接字
 * 3.绑定套接字
 * 4.在套接字上侦听客户端
 * 5.接受来自客户端的连接
 * 6.接收和发送数据
 * 7.断开连接
 */
#define _WIN32_WINNT 0x0501//getaddrinfo
#include <WS2tcpip.h>
#include <Winsock2.h>
#include <Windows.h>
//使用 Winsock 的应用程序必须与 Ws2 _ 32.lib 库文件链接
#pragma comment(lib, "Ws2_32.lib")

#include <iostream>

int main(){
    //__0.备用数据
    const char* port = "27011" ;//端口号，DEFAULT_PORT
    int iResult = 0 ;
    int iSendResult ;
    char recvbuf[1024] ;//接收缓冲区
    int recvbuflen = 1024 ;//缓冲区大小


    //__1.初始化 Winsock
    WSADATA wsaData;
    //初始化检测
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        /*初始化失败,异常待添加*/
    }


    //__2.创建套接字
    //Getaddrinfo函数用于确定sockaddr结构中的值,Addrinfo结构由getaddrinfo函数使用。
    struct addrinfo *result = NULL, *ptr = NULL, hints;
    ZeroMemory(&hints, sizeof (hints)); //分配内存并用0初始化,仅windows
    hints.ai_family   = AF_INET;        //IPv4
    hints.ai_socktype = SOCK_STREAM;    //流套接字
    hints.ai_protocol = IPPROTO_TCP;    //用于tcp协议
    hints.ai_flags    = AI_PASSIVE;     //
    //解决服务器使用的本地地址和端口
    iResult = getaddrinfo(NULL, port, &hints, &result);
    if (iResult != 0) {
        /*失败异常处理*/
        WSACleanup();
    }
    SOCKET ListenSocket = INVALID_SOCKET;
    //为服务器创建一个套接字以侦听客户端连接
    ListenSocket = socket((*result).ai_family, (*result).ai_socktype, (*result).ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        /*创建套接字失败,异常待添加*/
        freeaddrinfo(result);
        WSACleanup();
    };MSG_DONTROUTE;


    //__3.绑定套接字
    //设置TCP侦听套接字
    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        /*套接字绑定网络地址失败,异常待添加*/

        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
    }
    //不再需要 getaddrinfo 函数返回的地址信息,释放分配内存
    freeaddrinfo(result);


    //__4.在套接字上侦听客户端
    if ( listen( ListenSocket, SOMAXCONN ) == SOCKET_ERROR ) {
        /*侦听失败，异常待添加*/
        closesocket( ListenSocket );
        WSACleanup();
    }


    //__5.接受来自客户端的连接
    //创建名为ClientSocket的临时套接字对象,以接受来自客户端的连接
    SOCKET ClientSocket = INVALID_SOCKET;
    //对于高性能服务器，通常使用多个线程来处理多个客户端连接
    //有几种不同的编程技术使用Winsock,可用于侦听多个客户端连接
    //一种编程方法是创建一个连续循环,该循环使用listen函数检查连接请求
    //如果出现连接请求,应用程序将调用accept,AcceptEx,WSAAccept 函数
    //并将工作传递到另一个线程来处理请求
    ClientSocket = accept( ListenSocket , NULL , NULL );
    if (ClientSocket == INVALID_SOCKET) {
        /*接受客户端失败，异常待添加*/
        closesocket(ListenSocket);
        WSACleanup();
    }

    //__6.接收和发送数据
    //接收，直到对方关闭连接
    do {
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            std::cout << "Bytes received: "<< iResult << std::endl ;

            //将缓冲区回传给发送方
            iSendResult = send(ClientSocket, recvbuf, iResult, 0);
            if (iSendResult == SOCKET_ERROR) {
                /*发送数据失败,异常待添加*/
                closesocket(ClientSocket);
                WSACleanup();
            }
            std::cout << "Bytes sent:" << iSendResult << std::endl ;
        } else if (iResult == 0){
            /*连接已断开,异常待添加*/
        }
        else {
            /*接收数据失败,异常待添加*/
            closesocket(ClientSocket);
            WSACleanup();
        }
    } while (iResult > 0);


    //__7.断开连接
    //关闭发送一半的连接,因为没有更多的数据将被发送
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        /*断开套接字失败,异常待添加*/
        closesocket(ClientSocket);
        WSACleanup();
    }
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}



