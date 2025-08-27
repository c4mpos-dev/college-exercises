print("Digite o valor de M (início do intervalo): ")
local M = tonumber(io.read())

print("Digite o valor de N (fim do intervalo): ")
local N = tonumber(io.read())

print("Digite o valor de X: ")
local X = tonumber(io.read())

print("\nMúltiplos de " .. X .. " no intervalo de " .. M .. " até " .. N .. ":")

for i = M, N do
    if i % X == 0 then
        print(i)
    end
end