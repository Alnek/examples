local hello = require "hello"
local native = require "libhello"

local function callback(arg)
    print(string.format("callback in Lua from %s", arg))
end

local function main()
    hello.test(callback)
    native.test(callback)
end

main()

