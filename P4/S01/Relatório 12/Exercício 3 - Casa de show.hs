data Banda = Banda {
    nome :: String,
    genero :: String,
    cache :: Double
} deriving (Show)

data StatusEvento = Ativo | Encerrado | Cancelado
    deriving (Show, Eq) 

data Evento = Evento {
    bandas :: [Banda],
    status :: StatusEvento
} deriving (Show)

custoTotalEvento :: Evento -> Double
custoTotalEvento (Evento _ Cancelado) = 0.0
custoTotalEvento (Evento lista _) = totalCaches * 1.20
    where
        totalCaches = sum (map cache lista)

bandaAbertura :: Evento -> String
bandaAbertura (Evento [] _) = "Nenhuma banda cadastrada."
bandaAbertura (Evento (b:_) _) = nome b

bandaFechamento :: Evento -> String
bandaFechamento (Evento [] _) = "Nenhuma banda cadastrada."
bandaFechamento (Evento lista _) = nome (last lista)

banda1 = Banda "Os Alquimistas" "Indie Rock" 5000.0
banda2 = Banda "Byte Groove" "Eletrônica" 8000.0
banda3 = Banda "Sintaxe Errada" "Punk" 3500.0

eventoAtivo = Evento [banda1, banda2] Ativo
eventoEncerrado = Evento [banda1, banda2, banda3] Encerrado
eventoCancelado = Evento [banda3] Cancelado
eventoVazio = Evento [] Ativo

main :: IO ()
main = do
    putStrLn "--- Sistema de Eventos da Casa de Shows ---"

    putStrLn "\n--- Evento 1 (Ativo) ---"
    putStrLn ("Custo Total: " ++ show (custoTotalEvento eventoAtivo))
    putStrLn ("Banda Abertura: " ++ bandaAbertura eventoAtivo)
    putStrLn ("Banda Fechamento: " ++ bandaFechamento eventoAtivo)

    putStrLn "\n--- Evento 2 (Encerrado) ---"
    putStrLn ("Custo Total: " ++ show (custoTotalEvento eventoEncerrado))
    putStrLn ("Banda Abertura: " ++ bandaAbertura eventoEncerrado)
    putStrLn ("Banda Fechamento: " ++ bandaFechamento eventoEncerrado)

    putStrLn "\n--- Evento 3 (Cancelado) ---"
    putStrLn ("Custo Total: " ++ show (custoTotalEvento eventoCancelado))
    putStrLn ("Banda Abertura: " ++ bandaAbertura eventoCancelado)
    putStrLn ("Banda Fechamento: " ++ bandaFechamento eventoCancelado)
    
    putStrLn "\n--- Evento 4 (Vazio) ---"
    putStrLn ("Custo Total: " ++ show (custoTotalEvento eventoVazio))
    putStrLn ("Banda Abertura: " ++ bandaAbertura eventoVazio)
    putStrLn ("Banda Fechamento: " ++ bandaFechamento eventoVazio)