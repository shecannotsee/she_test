#include "read.hpp"
#include <iostream>

int main()
{
    

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
    getchar();
#endif
    return 0;
};
