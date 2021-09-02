#include "read.hpp"

#include <fstream>//read and write
#include <iostream>

she::ReadUserIp::ReadUserIp()
{
    ReadUserIp( "user.init" ) ;
};

she::ReadUserIp::ReadUserIp(char* p_fileName)
{
    m_fileName = p_fileName ;
    start();
};


she::ReadUserIp::~ReadUserIp()
{
    //清空并回收元素
    std::vector<user>().swap(m_data);
    m_fileName = nullptr ;
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
    // 1.打开文件
    std::ifstream readFile ;
    readFile.open( m_fileName , std::ios::in) ;

    std::string t_dataFromFile ;
    user t_user ;

    if( readFile.is_open() ){//判断打开是否成功
        while( std::getline( readFile , t_dataFromFile ) ){
            if( !t_dataFromFile.empty() ){//不为空进行数据解析

                // 2.按行读取
                if( t_dataFromFile[0] == 'n' ){
                    t_user.name = m_parsing( t_dataFromFile ) ;
                    // std::cout << "Insert name is:" << t_user.name << std::endl ;
                } else if ( t_dataFromFile[0] == 'i' ){
                    t_user.ip = m_parsing( t_dataFromFile ) ;
                    // std::cout << "Insert ip   is:" << t_user.ip << std::endl ;
                }else if( t_dataFromFile[0] == 'p' ){
                    t_user.port = m_parsing( t_dataFromFile ) ;
                    // std::cout << "Insert port is:" << t_user.port << std::endl ;
                }

                // 3.数据保存至类中
                if( !t_user.name.empty() && 
                    !t_user.ip.empty() && 
                    !t_user.port.empty()
                 ){
                     std::cout << "Insert to send." << std::endl << std::endl ;
                     m_data.push_back( t_user) ;
                     t_user.name = "";
                     t_user.ip   = "";
                     t_user.port = "";
                 }
                

            }
        }
    }else{//打开失败
        
    }

};