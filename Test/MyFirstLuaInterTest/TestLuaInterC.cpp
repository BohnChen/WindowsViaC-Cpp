/**
 * Read data from lua stack
 * BohnChen 2022-06-27 13:31
 */
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
#include <iostream>
#include <string.h>
using namespace std;

// define some error num.
#define MY_PCALL_ERROR -1
#define MY_LUASTATEACQUIRE_ERROR -2
#define MY_LOAD_FILE_ERROR -3

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

int main() {
    // 1. Create Lua state
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    std::cout << "Here. " << std::endl;
    if (L == NULL) {
        std::cout << "The lua state is nullptr. " << std::endl;
        // return MY_LUASTATEACQUIRE_ERROR;
    }

    // 2. load the lua file
    int _bRet = luaL_loadfile(L, "test.lua");
    if (_bRet) {
        std::cout << "Load file error." << std::endl;
        // return MY_LOAD_FILE_ERROR;
    }

    // 3. run the lua file
    _bRet = lua_pcall(L, 0, 0, 0);
    if (_bRet) {
        std::cout << "pcall error." << std::endl;
        // return MY_PCALL_ERROR;
    }

    // 4. Read the variable.
    lua_getglobal(L, "str");
    string str = lua_tostring(L, -1);
    std::cout << "str = " << str.c_str() << std::endl; // str = I am so cool~

    // 5. Read the table
    lua_getglobal(L, "tbl");
    lua_getfield(L, -1, "name");
    str = lua_tostring(L, -1);
    std::cout << "tbl:name = " << str.c_str() << std::endl; // tbl:name = shun

    // 6. Read the function
    lua_getglobal(L, "add"); // 获取函数，压入栈中
    lua_pushnumber(L, 10);   // 压入第一个参数
    lua_pushnumber(L, 20);   // 压入第二个参数
    int _iRet = lua_pcall(
        L, 2, 1,
        0); // 调用函数，然后会把返回值压入栈中，2表示参数个数，1表示返回结果个数
    if (lua_isnumber(L, -1)) {
        double fValue = lua_tonumber(L, -1);
        std::cout << "Result is " << fValue << std::endl;
    }
    /***********************************************************************
     * 至此，栈中的内容是：
     * =========================== 栈顶 ====================================
     * 4	int:		30
     * 3	string: shun
     * 2  table:  tbl
     * 1	string: I am so cool~
     * =========================== 栈顶 ====================================
     * */
    lua_close(L);
    // return 0;
}
