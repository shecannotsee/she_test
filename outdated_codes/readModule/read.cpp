#include "read.hpp"

#include <iostream>

she::ReadUserIp::ReadUserIp()
{
    ReadUserIp( "user.init" ) ;
};

she::ReadUserIp::ReadUserIp(char* p_fileName)
{
    m_number = 0 ;
    m_readFile.open( p_fileName , std::ios::in) ;
    if( !m_readFile.is_open() ){//打开失败
        //待添加异常代码
    }

};


she::ReadUserIp::~ReadUserIp()
{
    //清空并回收元素
    std::vector<user>().swap(m_data);
    //数据个数清零
    m_number = 0;
    //关闭文件句柄
    m_readFile.close();
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


int she::ReadUserIp::run()
{

    std::string t_dataFromFile ;
    user t_user ;

    while( std::getline( m_readFile , t_dataFromFile ) ){
        if( !t_dataFromFile.empty() ){//不为空进行数据解析
            // 1.按行读取
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
            // 2.数据保存至类中
            if( !t_user.name.empty() && !t_user.ip.empty() && !t_user.port.empty()){
                m_data.push_back( t_user) ;
                m_number ++ ;
                t_user.name = "";
                t_user.ip   = "";
                t_user.port = "";
            }
        }
    }

    // for(int i=0;i<data.size();i++){
    //     std::cout<<"user-"<< (i+1) <<":\n";
    //     std::cout<<"\n  name:"<<data[i].name;
    //     std::cout<<"\n  ip  :"<<data[i].ip  ;
    //     std::cout<<"\n  port:"<<data[i].port;
    //     std::cout<<"\n";
    // }

    return 1;

};


she::ReadUserIp::user she::ReadUserIp::getData(int index)
{
    user t_error ;
    t_error.name = "error";
    t_error.ip   = "error";
    t_error.port = "error";
    if( index<m_data.size() ){
        return m_data[index];
    }
    else{
        /*待添加越界的异常代码*/
        return t_error;
    }
};

int she::ReadUserIp::getNumber()
{
    return m_number;
};
