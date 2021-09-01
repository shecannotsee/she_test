#include <iostream>
#include <fstream>//read and write
#include <vector>
#include <string>

#define DEBUG()
//__LINE__:所在行数
//__FILE__   所在文件名

using namespace std;

struct user{
    string name;
    string ip;
    string port;
};

//对行数据进行提取
string parsing( string data ){
    string t_return = "";
    int flag = 0 ;
    for( int i=0 ; i<data.size() ; i++ ){
        if( data[i] == ';' ){
            flag = 0 ;
        }

        if(flag){
            t_return += data[i] ;
        }

        if( data[i] == ':' ){
            flag = 1 ;
        }
    }

    return t_return ;

};


int main(){

    ifstream readFile ;


    readFile.open( "user.init" , std::ios::in) ;

    string dataFromFile ;
    user t_user;
    vector<user> t_sendUsers;

    if( !readFile.is_open() ){//判断打开是否成功
        cout << "Open file error." << endl ;
        cout << "Maybe the file doesn't exist." << endl ;
        cout << "Maybe the file name is incorrect" << endl ;
        return 0;
    }
    else{
        int rows = 0 ;
        while( getline( readFile , dataFromFile) ){//按行读取
            if( dataFromFile.empty() ){//为空
                cout<<"read over."<<endl;
            }
            else{//不为空
                cout<<"The rows is "<<++rows<<",Content is:"; 
                cout<< dataFromFile << endl ;//对读取的内容进行查看
                cout<<"start to parsing..."<<endl;
                if( dataFromFile[0] == 'n' ){
                    t_user.name = parsing( dataFromFile ) ;
                    cout << "Insert name is:" << t_user.name << endl ;
                } else if ( dataFromFile[0] == 'i' ){
                    t_user.ip = parsing( dataFromFile ) ;
                    cout << "Insert ip   is:" << t_user.ip << endl ;
                }else if( dataFromFile[0] == 'p' ){
                    t_user.port = parsing( dataFromFile ) ;
                    cout << "Insert port is:" << t_user.port << endl ;
                }

                if( !t_user.name.empty() && 
                    !t_user.ip.empty() && 
                    !t_user.port.empty()
                 ){
                     cout << "Insert to send." << endl << endl ;
                     t_sendUsers.push_back( t_user) ;
                     t_user.name = "";
                     t_user.ip   = "";
                     t_user.port = "";
                 }

                //t_user = parsing( dataFromFile ) ;//读取数据信息提取
                //t_sendUsers.push_back( t_user ) ;//加入发送数组
            }
        }
    }

    for(int i=0;i<t_sendUsers.size();i++){
        cout<<"user-"<< (i+1) <<":"<<endl;
        cout<<"  name:"<<t_sendUsers[i].name<<endl;
        cout<<"  ip  :"<<t_sendUsers[i].ip  <<endl;
        cout<<"  port:"<<t_sendUsers[i].port<<endl;
    }

    // 关闭文件
    cout << "\nClose file." << endl ;
    readFile.close();

    return 1;
}

