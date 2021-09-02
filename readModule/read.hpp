#ifndef _READ_HPP_
#define _READ_HPP_
#include <string>
#include <vector>

namespace she{

/* @brief 该类从文件中读取相关网络数据

 * 
 */
class ReadUserIp{
    public:
        ReadUserIp();
        ReadUserIp(char*);
        ~ReadUserIp();

    public:
        //网络地址结构体
        struct user{
            std::string name;
            std::string ip  ;
            std::string port;
        };

    private:
        /*
         * 按行解析:从:到;之间的内容
         */
        std::string m_parsing(std::string);

        char* m_fileName;//文件名

        /*
         * 从文件读取的主流程
         */
        int start();
    
    public:
        std::vector<user> m_data;//从文件中读到的数据

};//class ReadFromInit

};//namespace she




#endif// !_READ_HPP_
