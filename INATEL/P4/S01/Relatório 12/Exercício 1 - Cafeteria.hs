data Bebida = Bebida {
    nome :: String,
    tipo :: String,
    preco :: Double
} deriving (Show)

data StatusPedido = Aberto | Entregue | Cancelado
    deriving (Show, Eq) 

data Pedido = Pedido {
    bebidas :: [Bebida],
    status :: StatusPedido
} deriving (Show)

valorTotalPedido :: Pedido -> Double
valorTotalPedido (Pedido _ Cancelado) = 0.0
valorTotalPedido (Pedido lista _) = taxa + (sum (map preco lista))
    where
        taxa = 5.0

primeiraBebida :: Pedido -> String
primeiraBebida (Pedido [] _) = "Pedido vazio"
primeiraBebida (Pedido (b:_) _) = nome b


cafeDaCasa = Bebida "Café da Casa" "Café" 10.0
chaDeCamomila = Bebida "Chá de Camomila" "Chá" 7.5
sucoDeLaranja = Bebida "Suco de Laranja" "Suco" 8.0

pedido1 = Pedido [cafeDaCasa, chaDeCamomila] Aberto
pedido2 = Pedido [sucoDeLaranja] Cancelado
pedido3 = Pedido [] Entregue 

main :: IO ()
main = do
    putStrLn "--- Sistema do Café Leblanc ---"

    putStrLn "\n--- Teste valorTotalPedido ---"
    
    putStrLn "Pedido 1 (Aberto):"
    print (valorTotalPedido pedido1) 

    putStrLn "Pedido 2 (Cancelado):"
    print (valorTotalPedido pedido2)

    putStrLn "Pedido 3 (Vazio, Entregue):"
    print (valorTotalPedido pedido3)

    putStrLn "\n--- Teste primeiraBebida ---"
    
    putStrLn "Pedido 1:"
    putStrLn (primeiraBebida pedido1)

    putStrLn "Pedido 2:"
    putStrLn (primeiraBebida pedido2)

    putStrLn "Pedido 3:"
    putStrLn (primeiraBebida pedido3)