use std::io::{self, Write};

fn eh_par(numero: i32) -> bool {
    numero % 2 == 0
}

fn main() {
    // jogador 1 escolhe par ou ímpar
    print!("Obs: cuidado com o acento agudo! \nJogador 1, escolha (par/ímpar): ");
    io::stdout().flush().unwrap();

    let mut escolha = String::new();
    io::stdin().read_line(&mut escolha).expect("Erro ao ler entrada");
    let escolha = escolha.trim().to_lowercase();

    // jogador 1 escolhe o número
    print!("Jogador 1, digite seu número: ");
    io::stdout().flush().unwrap();

    let mut entrada1 = String::new();
    io::stdin().read_line(&mut entrada1).expect("Erro ao ler número");
    let num1: i32 = entrada1.trim().parse().expect("Digite um número válido");

    // jogador 2 escolhe o número
    print!("Jogador 2, digite seu número: ");
    io::stdout().flush().unwrap();

    let mut entrada2 = String::new();
    io::stdin().read_line(&mut entrada2).expect("Erro ao ler número");
    let num2: i32 = entrada2.trim().parse().expect("Digite um número válido");

    let soma = num1 + num2;

    let soma_par = eh_par(soma);

    println!("\nA soma dos números foi: {}", soma);
    if soma_par {
        println!("A soma é PAR.");
    } else {
        println!("A soma é ÍMPAR.");
    }

    if (soma_par && escolha == "par") || (!soma_par && escolha == "ímpar") {
        println!("Jogador 1 venceu!");
    } else {
        println!("Jogador 2 venceu!");
    }
}