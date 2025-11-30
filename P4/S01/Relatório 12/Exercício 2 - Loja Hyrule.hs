data Item = Item {
    nome :: String,
    categoria :: String,
    preco :: Double
} deriving (Show)

data CompraZelda = CompraZelda {
    itens :: [Item]
} deriving (Show)

valorTotalItens :: [Item] -> Double
valorTotalItens lista = sum (map preco lista)

calculaDesconto :: [Item] -> Double
calculaDesconto lista
    | total > 200 = total * 0.10
    | otherwise   = 0.0
    where
        total = valorTotalItens lista

valorFinal :: CompraZelda -> Double
valorFinal (CompraZelda lista)
    | total > 200 = total * 0.90 
    | otherwise   = total + 15.0
    where
        total = valorTotalItens lista

masterSword = Item "Master Sword" "Arma" 150.0
hylianShield = Item "Hylian Shield" "Equipamento" 100.0
redPotion = Item "Red Potion" "Poção" 20.0
bombBag = Item "Bomb Bag" "Equipamento" 50.0

compraCara = CompraZelda [masterSword, hylianShield]
compraBarata = CompraZelda [redPotion, bombBag]
compraMedia = CompraZelda [masterSword, bombBag]

main :: IO ()
main = do
    putStrLn "--- Bem-vindo à Loja de Hyrule ---"

    putStrLn "\n--- Compra 1 (Cara) ---"
    putStrLn "Itens da Compra:"
    print (itens compraCara)
    putStrLn "Valor Final:"
    print (valorFinal compraCara) 

    putStrLn "\n--- Compra 2 (Barata) ---"
    putStrLn "Itens da Compra:"
    print (itens compraBarata)
    putStrLn "Valor Final:"
    print (valorFinal compraBarata) 

    putStrLn "\n--- Compra 3 (Limite 200) ---"
    putStrLn "Itens da Compra:"
    print (itens compraMedia)
    putStrLn "Valor Final:"
    print (valorFinal compraMedia) 
    
    putStrLn "\n--- Teste da funcao calculaDesconto (separada) ---"
    putStrLn "Desconto para Compra 1 (250.0):"
    print (calculaDesconto (itens compraCara)) 
    putStrLn "Desconto para Compra 2 (70.0):"
    print (calculaDesconto (itens compraBarata))