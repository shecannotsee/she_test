#include <sys/socket.h>
@brief socket函数：返回套接字
@param int family:指名协议族
	AF_INET		IPv4
	AF_INET6	IPv6
	AF_LOCAL	Unix域协议
	AF_ROUTE	路由套接字
	AF_KEY		密钥套接字
@param int type:指名套接字类型
	SOCK_STREAM		字节流套接字
	SOCK_DGRAM		数据包套接字
	SOCK_SEQPACKET	有序分组套接字
	SOCK_RAW		原始套接字
@param int protocol:设置为0或某个协议类型常值
	IPPROTO_CP		TCP传输协议
	IPPROTO_UDP		UDP传输协议
	IPPROTO_SCTP	SCTP传输协议
@return 成功时返回一个非负的套接字描述符，出错返回-1
参考表
				AF_INET		AF_INET6	AF_ROUTE	AF_ROUTE	AF_KEY
SOCK_STREAM		TCP|SCTP	TCP|SCTP	是
SOCK_DGRAM		UDP			UDP			是
SOCK_SEQPACKET	SCTP		SCTP		是
SOCK_RAW		IPV4		IPv6					是			否


#include <sys/socket.h>
@brief connect函数：TCP客户端使用该函数来连接TCP服务器
@param int sockfd:含有服务器ip端口的套接字描述符
@param const struct *servaddr:服务器套接字的地址结构指针
@param socklen_t addrlen:服务器套接字的结构大小
@return 成功则返回0，出错则返回-1
出错可能的原因
1.TCP客户端没有收到SYN分节相应，返回ETIMEDOUT
2.若对客户的端的SYN的相应是RST(表示复位)，则表明该服务器主机在我们指定的端口上没有进程在等待与之连接
3.客户端发出的SYN在中间的某个路由器上引发目的不可达的ICMP错误


#include <sys/socket.h>
@brief bind函数：把一个本地协议地址赋予给一个套接字
@param int sockfd:
@param const struct sockaddr *myaddr:
@param socklen_t addrlen:
@return 成功则返回0，出错则返回-1




