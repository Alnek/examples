local this = {}

function test(callback)
    callback("Lua")
    --print("Hello from Lua library!")
end

this.test = test
return this

