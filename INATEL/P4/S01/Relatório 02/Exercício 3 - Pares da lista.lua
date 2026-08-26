function filtrarPares(tabela)
    local pares = {}

    -- o # retorna pega tamanho da tabela
    for i = 1, #tabela do
        if tabela[i] % 2 == 0 then
            table.insert(pares, tabela[i])
        end
    end

    return pares
end

print("Digite uma lista de números separados por espaço:")
local entrada = io.read()

local numeros = {}
-- regex que pega qualquer sequência de caracteres que não seja espaço
for num in string.gmatch(entrada, "%S+") do
    table.insert(numeros, tonumber(num))
end

local pares = filtrarPares(numeros)

print("\nNúmeros pares encontrados:")
-- o # retorna pega tamanho da tabela
if #pares == 0 then
    print("Nenhum número par encontrado.")
else
    for i = 1, #pares do
        io.write(pares[i] .. " ")
    end
    print()
end