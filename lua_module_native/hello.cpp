#include "hello.h"

#include <lua.hpp>
#include <iostream>

namespace hello
{

void test()
{
    std::cout << "Hello from native library!" << std::endl;
}

int luaCallback(lua_State* L)
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

int testLua(lua_State* L)
{
    test();
    luaCallback(L);

    //lua_pushliteral(L, "test");
    //lua_pushnumber(L, 123);
    //return 2;
    return 0;
}

} // namespace

using namespace hello;

extern "C" int luaopen_libhello(lua_State *L)
{
    lua_pushcfunction(L, testLua);
    lua_setglobal(L, "test");
    //lua_register(L, "test", testLua); // register global function, same as two lines above


    lua_newtable(L);
    lua_pushnumber(L, 3.14159);
    lua_setfield(L, -2, "number");
    lua_pushliteral(L, "test");
    lua_setfield(L, -2, "literal");
    lua_pushcfunction(L, testLua);
    lua_setfield(L, -2, "test");    // this exports test as module member

    return 1;
}

