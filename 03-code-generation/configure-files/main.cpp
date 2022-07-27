#include <iostream>
#include "ver.h"
#include "path.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello Version " << ver << "!" << std::endl;
    std::cout << "Path is " << path << std::endl;

    // 测死set, 而后代码直接使用
    #ifdef WORLD_VALUE
    std::cout << "world vlue: " << WORLD_VALUE << std::endl;
    #else
    std::cout << "not def world vlue." << std::endl;
    #endif

   return 0;
}


/*
cmakelist: cmake var (inside, option , set)
config.h.in: #cmakedefine  或  代码直接使用: const char* path = "@CMAKE_SOURCE_DIR@";
config.h:    #define or #undef or decde code( const char* ver = "0.2.1"; )

关联关键字:
option set #cmakedefine configure_file

configure_file(ver.h.in ${PROJECT_BINARY_DIR}/ver.h)
cmake 命令语句, 把变量模板 头文件, 通过cmake上下文变量替换, 模板--->实际可用头文件 (也可通过 -D 而后直接在.cpp中使用, 但需要少量, 此处可批量)
https://www.cnblogs.com/the-capricornus/p/4717566.html
https://www.jianshu.com/p/2946eeec2489   -----  使用例程

config.h.in  中的   #cmakedefine LIFE_VALUE
需要配合 CmakeList.txt 中的 option 使用, 否则生成  // #undef LIFE_VALUE  
option(LIFE_VALUE "the value of life" ON)   后生成    #define LIFE_VALUE
也可通过 set (var2 13)    #cmakedefine var2 "@var2@"    #define var2 "13" 
*/