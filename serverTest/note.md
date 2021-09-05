@brief socket函数:创建绑定到特定传输服务提供商的套接字
@param int af:
    0   AF_UNSPEC       地址族未指定
    2   AF_INET         IPv4
    6   AF_IPX          IPX/SPX 地址族
    16  AF_APPLETALK    AppleTalk 地址族
    17  AF_NETBIOS      NetBIOS 地址族
    23  AF_INET6        IPv6
    26  AF_IRDA         红外数据协会 (IrDA) 地址族
    32  AF_BTH          蓝牙地址族
@param int type:
    1   SOCK_STREAM     TCP(IPv4,IPv6)
    2   SOCK_DGRAM      UDP(IPv4,IPv6)
    3   SOCK_RAW        提供原始套接字的套接字类型，允许应用程序操作下一个上层协议标头。要操作 IPv4 标头，必须在套接字上设置IP_HDRINCL套接字选项。要操作 IPv6 标头，必须在套接字上设置IPV6_HDRINCL套接字选项。
    4   SOCK_RDM        提供可靠消息数据报的套接字类型
    5   SOCK_SEQPACKET  一种基于数据报提供伪流数据包的套接字类型
@param int protocol:
    1   IPPROTO_ICMP    Internet控制消息协议(ICMP),af=AF_UNSPEC|IPv4|IPv6,type=SOCK_RAW
    2   IPPROTO_IGMP    Internet组管理协议(IGMP),af=AF_UNSPEC|IPv4|IPv6,type=SOCK_RAW
    3   BTHPROTO_RFCOMM 蓝牙射频通信(Bluetooth RFCOMM)协议,af=IPv4|IPv6,type=SOCK_STREAM
    6   IPPROTO_TCP     传输控制协议(TCP),af=IPv4|IPv6,type=SOCK_STREAM
    17  IPPROTO_UDP     用户数据报协议(UDP),af=IPv4|IPv6,type=SOCK_DGRAM
    58  IPPROTO_ICMPV6  Internet控制消息协议版本6(ICMPv6),af=AF_UNSPEC|IPv4|IPv6,type=SOCK_RAW
    113 IPPROTO_RM      用于可靠组播的PGM协议,af=IPv4,type=SOCK_RDM
@return 发生错误则返回一个INVALID_SOCKET值,否则返回一个套接字描述符


@brief bind函数:将本地地址与套接字联系起来
@param SOCKET s:                标识未绑定套接字的描述符
@param const sockaddr *addr:    指向要分配给绑定套接字的本地地址的sockaddr结构的指针
@param int namelen:             name参数指向的值的长度(以字节为单位)
@return 如果没有发生错误,bind返回零,否则它返回SOCKET_ERROR


@brief listen函数:将套接字放在侦听并且等待传入连接的状态下
@param SOCKET s:    标识绑定的未连接套接字的描述符
@param int backlog: 处理连接队列的最大长度
@return 如果没有发生错误,listen返回零,否则返回SOCKET_ERROR


@brief accept函数:在一个套接口接受一个连接
@param SOCKET s:一个描述符,用于标识已使用侦听功能置于侦听状态的套接字,该连接实际上是通过accept返回的套接字建立的
@param sockaddr *addr:一个可选的指向缓冲区的指针,该缓冲区接收连接实体的地址,如通信层所知
@param int *addrlen:一个指向整数的可选指针
@return 如果没有发生错误,accept返回一个SOCKET类型的值,它是新套接字的描述符


@brief select函数:该函数确定一个或多个套接字的状态,等待必要,执行同步I/O
@param int nfds:                Ignored
@param fd_set *readfds:         指向要检查可读性的一组套接字的可选指针
@param fd_set *writefds:        指向一组要检查可写性的套接字的可选指针
@param fd_set *exceptfds:       指向要检查错误的一组套接字的可选指针
@param const timeval *timeout:  select等待的最长时间,以TIMEVAL结构的形式提供,将超时参数设置为null以进行阻塞操作
@return 

@brief shutdown函数:该函数禁用在套接字上发送或接收
@param SOCKET s:    标识套接字的描述符
@param int how:     描述将不再允许的操作类型的标志
    0   SD_RECEIVE  关闭接收操作
    1   SD_SEND     关闭发送操作
    2   SD_BOTH     关闭发送和接收操作
@return 如果没有发生错误,shutdown返回零,否则返回 SOCKET_ERROR 的值


@brief closesocket函数:关闭现有套接字
@param SOCKET s:    标识要关闭的套接字的描述符
@return 如果没有发生错误,closesocket返回零,否则,返回SOCKET_ERROR的值
@notice 一旦发出closesocket函数，在s参数中传递的套接字描述符可能会立即被系统重用。因此，期望对s参数中传递的套接字描述符的进一步引用失败并出现错误WSAENOTSOCK是不可靠的。Winsock 客户端绝不能在s上与另一个 Winsock 函数调用同时发出closesocket。


@brief send函数:该函数在已连接的套接字上发送数据
@param SOCKET s:        识别连接socket的描述符
@param const char *buf: 指向包含要传输数据的缓冲区的指针
@param int len:         缓冲区中数据的长度
@param int flag:        一组标记，指定呼叫方式。此参数是使用具有以下任何值的位向或操作员构建的  
    1   MSG_OOB         仅发送 OOB 数据
    4   MSG_DONTROUTE   指定数据不应受路由限制。Windows 插座服务提供商可以选择忽略此标志。 
@return 如果没有发生错误，发送返回发送的字节总数,该字节可能小于请求发送的len参数中的字节总数,否则,将返回SOCKET_ERROR值


@brief recv函数:从已连接的套接字或绑定无连接套接字接收数据
@param SOCKET s:        标识连接socket的描述符
@param const char *buf: 接收传入数据的缓冲区的指针
@param int len:         缓冲区中数据的长度
@param int flag:        一组标记，指定呼叫方式。此参数是使用具有以下任何值的位向或操作员构建的  
@return 如果没有发生错误，recv会返回收到的字节数，缓冲参数指向的缓冲将包含收到的数据，如果连接已优雅的关闭,则返回值为零


@brief connect函数:建立与指定套接字的连接
@param SOCKET s:                识别未连接的socket描述符
@param const sockaddr *name:    A pointer to the sockaddr structure,服务器的信息
@param int namelen:             The length,in bytes,of the sockaddr structure pointed to by the name parameter.
@return 如果没有发生错误,连接返回零,否则它会返回SOCKET_ERROR
