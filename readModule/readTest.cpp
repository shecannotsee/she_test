#include "read.hpp"
#include <iostream>

int main()
{
    she::ReadUserIp t_read( "users.init" ) ;
    t_read.run();

    for( int i=0 ; i<t_read.getNumber() ; i++ ){
        std::cout << (t_read.getData(i)).name << std::endl ;
        std::cout << (t_read.getData(i)).ip   << std::endl ;
        std::cout << (t_read.getData(i)).port << std::endl ;
    }



/* Operating system
 * linux:__linux__
 * windows:_WIN32
 * 
 * Compiler
 * msvc:_MSC_VER
 * gun:__GNUC__
 * 
 * Programming language
 * c++:__cplusplus
 */
#ifdef _WIN32
    std::cout << "run over." << std::endl ;
    getchar();
#endif
    return 0;
};
