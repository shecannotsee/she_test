#include "read.hpp"

#include <fstream>//read and write

she::ReadUserIp::ReadUserIp()
{
    ReadUserIp( "user.init" ) ;
};

she::ReadUserIp::ReadUserIp(char* p_fileName)
{
    std::ifstream readFile ;
    readFile.open( p_fileName , std::ios::in) ;
    if( readFile.is_open() ){//判断打开是否成功

    }else{//打开失败
        start();
    }
};


she::ReadUserIp::~ReadUserIp()
{

};


std::string she::ReadUserIp::m_parsing(std::string p_data)
{
    std::string t_return = "";
    int flag = 0 ;
    for( int i=0 ; i<p_data.size() ; i++ ){
        if( p_data[i] == ';' ){
            flag = 0 ;
        }

        if(flag){
            t_return += p_data[i] ;
        }

        if( p_data[i] == ':' ){
            flag = 1 ;
        }
    }

    return t_return ;
};


int she::ReadUserIp::start()
{
    std::ifstream readFile ;


    readFile.open( "user.init" , std::ios::in) ;
};