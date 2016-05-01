#include "hello.h"

#include <lua.hpp>
#include <iostream>

void test()
{
    std::cout << "Hello from native library!" << std::endl;
}

static int luaCallback(lua_State* L)
{
    if (lua_gettop(L) == 1 &&   // make sure exactly one argument is passed
        lua_isfunction(L, -1))  // and that argument (which is on top of the stack) is a function
    {
        lua_pushliteral(L, "native");   // push first argument to the function
        lua_pcall(L, 1, 0, 0);  // call a function with one argument and no return values
        //lua_pcall(L, 0, 0, 0);
    }
    return 0; // no values are returned from this function
}

static int testLua(lua_State* L)
{
    test();
    luaCallback(L);

    //lua_pushliteral(L, "sukatest1");
    //lua_pushnumber(L, 123);
    //return 2;
    return 0;
}

//LUALIB_API int luaopen_hello(lua_State *L)
extern "C" int luaopen_libhello(lua_State *L)
{
    lua_pushcfunction(L, testLua);
    lua_setglobal(L, "test");
    //lua_register(L, "test", testLua); // register global function


    lua_newtable(L);
    lua_pushnumber(L, 3.14159);
    lua_setfield(L, -2, "m1");
    lua_pushliteral(L, "sukatest");
    lua_setfield(L, -2, "m2");
    lua_pushcfunction(L, testLua);
    lua_setfield(L, -2, "test");

    return 1;
}

