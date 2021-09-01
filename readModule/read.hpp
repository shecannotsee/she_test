#ifndef _READ_HPP_
#define _READ_HPP_
#include <string>
#include <vector>

namespace she{

class ReadUserIp{
    public:
        ReadUserIp();
        ReadUserIp(char*);
        ~ReadUserIp();

    public:
        struct user{
            std::string name;
            std::string ip  ;
            std::string port;
        };

    private:
        std::string m_parsing(std::string);

        int start();
    
    public:
        std::vector<user> m_data;//从文件中读到的数据

};//class ReadFromInit

};//namespace she




#endif// !_READ_HPP_
