use std::io::{self, Write}; // importa Write para usar flush()

fn verificar_senha(senha: &str) -> bool {
    if senha.len() < 8 {
        return false;
    }

    let mut tem_numero = false;
    let mut tem_maiuscula = false;

    for c in senha.chars() {
        if c.is_ascii_digit() {
            tem_numero = true;
        }
        if c.is_ascii_uppercase() {
            tem_maiuscula = true;
        }
    }

    tem_numero && tem_maiuscula
}

fn main() {
    loop {
        // essas duas linhas fazem com que o texto apareça antes do input, assim evita qualquer tipo de bug
        print!("Digite uma senha: "); // não pula linha
        io::stdout().flush().unwrap(); // força mostrar antes do input (precisa do use std::io::{self, Write})

        let mut senha = String::new();
        io::stdin().read_line(&mut senha).expect("Erro ao ler entrada");

        let senha = senha.trim(); // remove os espaços em branco

        if verificar_senha(senha) {
            println!("Senha válida! Acesso concedido.");
            break;
        } else {
            println!("Senha inválida. Tente novamente.");
        }
    }
}