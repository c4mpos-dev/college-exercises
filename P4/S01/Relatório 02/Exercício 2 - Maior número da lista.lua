function maiorValor(tabela)
    local maior = tabela[1]

    -- o # retorna pega tamanho da tabela
    for i = 2, #tabela do
        if tabela[i] > maior then
            maior = tabela[i]
        end
    end

    return maior
end

print("Digite uma lista de números separados por espaço:")
local entrada = io.read()

local numeros = {}
-- regex que pega qualquer sequência de caracteres que não seja espaço
for num in string.gmatch(entrada, "%S+") do
    table.insert(numeros, tonumber(num))
end

local resultado = maiorValor(numeros)

print("\nO maior valor é: " .. resultado)