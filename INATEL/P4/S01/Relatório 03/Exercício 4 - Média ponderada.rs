fn calcular_media(nota1: f64, nota2: f64, nota3: f64) -> f64 {
    let peso1 = 2.0;
    let peso2 = 3.0;
    let peso3 = 5.0;
    let soma_pesos = peso1 + peso2 + peso3;

    (nota1 * peso1 + nota2 * peso2 + nota3 * peso3) / soma_pesos
}

fn main() {
    let nota1 = 7.5;
    let nota2 = 8.0;
    let nota3 = 9.2;

    let media = calcular_media(nota1, nota2, nota3);

    println!("Notas: {}, {}, {}", nota1, nota2, nota3);
    println!("Média ponderada = {:.2}", media);

    if media >= 7.0 {
        println!("Aluno Aprovado!");
    } else {
        println!("Aluno Reprovado!");
    }
}