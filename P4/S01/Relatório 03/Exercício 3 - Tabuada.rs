use std::io::{self, Write};

fn imprimir_tabuada(numero: i32, limite_inferior: i32, limite_superior: i32) {
    for i in limite_inferior..=limite_superior {
        println!("{} x {} = {}", numero, i, numero * i);
    }
}

fn main() {
    // numero da tabuada
    print!("Digite o número da tabuada: ");
    io::stdout().flush().unwrap();
    let mut entrada = String::new();
    io::stdin().read_line(&mut entrada).unwrap();
    let numero: i32 = entrada.trim().parse().expect("Digite um número válido");

    // limite inferior
    print!("Digite o limite inferior: ");
    io::stdout().flush().unwrap();
    entrada.clear(); // limpa a entrada para o próximo input (pois é a mesma variável)
    io::stdin().read_line(&mut entrada).unwrap();
    let limite_inferior: i32 = entrada.trim().parse().expect("Digite um número válido");

    // limite superior
    print!("Digite o limite superior: ");
    io::stdout().flush().unwrap();
    entrada.clear(); // limpa a entrada para o próximo input (pois é a mesma variável)
    io::stdin().read_line(&mut entrada).unwrap();
    let limite_superior: i32 = entrada.trim().parse().expect("Digite um número válido");

    println!("\nTabuada do {} de {} até {}:\n", numero, limite_inferior, limite_superior);

    imprimir_tabuada(numero, limite_inferior, limite_superior);
}