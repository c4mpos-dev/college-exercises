data Servico = Servico {
    nome :: String,
    tipo :: String,
    precoBase :: Double
} deriving (Show)

data StatusAtendimento = EmAndamento | Finalizado | Cancelado
    deriving (Show, Eq)

data Atendimento = Atendimento {
    servicos :: [Servico],
    status :: StatusAtendimento
} deriving (Show)

bonusEspiritual :: [Servico] -> Double
bonusEspiritual [] = 0.0
bonusEspiritual lista =
    let 
        totalBase = sum (map precoBase lista)
        
        totalComBonus
            | length lista > 3 = totalBase * 1.25
            | otherwise        = totalBase
        
        totalFinal
            | totalComBonus > 500 = totalComBonus * 0.90
            | otherwise           = totalComBonus
    in 
        totalFinal

valorFinalAtendimento :: Atendimento -> Double
valorFinalAtendimento (Atendimento _ Cancelado) = 0.0
valorFinalAtendimento (Atendimento lista _)     = bonusEspiritual lista

descricaoPrimeiroServico :: Atendimento -> String
descricaoPrimeiroServico (Atendimento [] _) = "Nenhum serviço neste atendimento."
descricaoPrimeiroServico (Atendimento (s:_) _) = (nome s) ++ " (Tipo: " ++ (tipo s) ++ ")"

s1 = Servico "Banho de Ervas Raras" "Banho" 80.0
s2 = Servico "Massagem Shiatsu Espiritual" "Massagem" 150.0
s3 = Servico "Banquete dos Deuses (Pequeno)" "Banquete" 300.0
s4 = Servico "Limpeza de Aura" "Banho" 200.0
s5 = Servico "Acupuntura Milenar" "Massagem" 120.0

at1 = Atendimento [s1, s2] Finalizado
at2 = Atendimento [s1, s2, s4, s5] EmAndamento
at3 = Atendimento [s3, s2, s1] Finalizado
at4 = Atendimento [s3, s1] Cancelado
at5 = Atendimento [] EmAndamento

main :: IO ()
main = do
    putStrLn "--- Controle da Casa de Banhos da Yubaba ---"

    putStrLn "\n--- Atendimento 1 (Simples) ---"
    putStrLn ("Serviços: " ++ show (servicos at1))
    putStrLn ("Status: " ++ show (status at1))
    putStrLn ("Primeiro Serviço: " ++ descricaoPrimeiroServico at1)
    putStrLn ("Valor Final: R$ " ++ show (valorFinalAtendimento at1))

    putStrLn "\n--- Atendimento 2 (Bônus + Desconto) ---"
    putStrLn ("Serviços: " ++ show (servicos at2))
    putStrLn ("Status: " ++ show (status at2))
    putStrLn ("Primeiro Serviço: " ++ descricaoPrimeiroServico at2)
    putStrLn ("Valor Final: R$ " ++ show (valorFinalAtendimento at2))

    putStrLn "\n--- Atendimento 3 (Apenas Desconto) ---"
    putStrLn ("Serviços: " ++ show (servicos at3))
    putStrLn ("Status: " ++ show (status at3))
    putStrLn ("Primeiro Serviço: " ++ descricaoPrimeiroServico at3)
    putStrLn ("Valor Final: R$ " ++ show (valorFinalAtendimento at3))

    putStrLn "\n--- Atendimento 4 (Cancelado) ---"
    putStrLn ("Serviços: " ++ show (servicos at4))
    putStrLn ("Status: " ++ show (status at4))
    putStrLn ("Primeiro Serviço: " ++ descricaoPrimeiroServico at4)
    putStrLn ("Valor Final: R$ " ++ show (valorFinalAtendimento at4))

    putStrLn "\n--- Atendimento 5 (Vazio) ---"
    putStrLn ("Serviços: " ++ show (servicos at5))
    putStrLn ("Status: " ++ show (status at5))
    putStrLn ("Primeiro Serviço: " ++ descricaoPrimeiroServico at5)
    putStrLn ("Valor Final: R$ " ++ show (valorFinalAtendimento at5))