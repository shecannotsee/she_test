#ifndef _READ_HPP_
#define _READ_HPP_
#include <string>
#include <vector>
#include <fstream>//read and write

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
        std::string m_parsing(std::string) ;

        std::ifstream m_readFile ;//文件句柄应存在于类的整个周期

        int m_number ;//数据个数

        std::vector<user> m_data;//从文件中读到的数据
    
    public:
        /*
         * 执行读取流程
         */
        int run() ;

        /* @brief 从动态数组中取单个数据
         * @param int 取的数据数组的下标
         */
        user getData(int) ;

        /*
         * 取已经存的数据个数
         */
        int getNumber();

};//class ReadFromInit

};//namespace she




#endif// !_READ_HPP_
