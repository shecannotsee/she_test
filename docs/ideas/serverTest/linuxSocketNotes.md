#include <sys/socket.h>
@brief socket�����������׽���
@param int family:ָ��Э����
	AF_INET		IPv4
	AF_INET6	IPv6
	AF_LOCAL	Unix��Э��
	AF_ROUTE	·���׽���
	AF_KEY		��Կ�׽���
@param int type:ָ���׽�������
	SOCK_STREAM		�ֽ����׽���
	SOCK_DGRAM		���ݰ��׽���
	SOCK_SEQPACKET	��������׽���
	SOCK_RAW		ԭʼ�׽���
@param int protocol:����Ϊ0��ĳ��Э�����ͳ�ֵ
	IPPROTO_CP		TCP����Э��
	IPPROTO_UDP		UDP����Э��
	IPPROTO_SCTP	SCTP����Э��
@return �ɹ�ʱ����һ���Ǹ����׽�����������������-1
�ο���
				AF_INET		AF_INET6	AF_ROUTE	AF_ROUTE	AF_KEY
SOCK_STREAM		TCP|SCTP	TCP|SCTP	��
SOCK_DGRAM		UDP			UDP			��
SOCK_SEQPACKET	SCTP		SCTP		��
SOCK_RAW		IPV4		IPv6					��			��


#include <sys/socket.h>
@brief connect������TCP�ͻ���ʹ�øú���������TCP������
@param int sockfd:���з�����ip�˿ڵ��׽���������
@param const struct *servaddr:�������׽��ֵĵ�ַ�ṹָ��
@param socklen_t addrlen:�������׽��ֵĽṹ��С
@return �ɹ��򷵻�0�������򷵻�-1
������ܵ�ԭ��
1.TCP�ͻ���û���յ�SYN�ֽ���Ӧ������ETIMEDOUT
2.���Կͻ��Ķ˵�SYN����Ӧ��RST(��ʾ��λ)��������÷���������������ָ���Ķ˿���û�н����ڵȴ���֮����
3.�ͻ��˷�����SYN���м��ĳ��·����������Ŀ�Ĳ��ɴ��ICMP����


#include <sys/socket.h>
@brief bind��������һ������Э���ַ�����һ���׽���
@param int sockfd:
@param const struct sockaddr *myaddr:
@param socklen_t addrlen:
@return �ɹ��򷵻�0�������򷵻�-1




