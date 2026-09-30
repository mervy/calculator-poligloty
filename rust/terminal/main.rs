use std::io::{self, Write};

fn main() {
    println!("=== Calculadora em Rust ===");
    println!("1. Adição (+)");
    println!("2. Subtração (-)");
    println!("3. Multiplicação (*)");
    println!("4. Divisão (/)");

    print!("Escolha a operação (1-4): ");
    io::stdout().flush().unwrap();
    let escolha: u32 = ler_numero();

    print!("Digite o primeiro número: ");
    io::stdout().flush().unwrap();
    let num1: f64 = ler_numero();

    print!("Digite o segundo número: ");
    io::stdout().flush().unwrap();
    let num2: f64 = ler_numero();

    match escolha {
        1 => println!("Resultado: {} + {} = {}", num1, num2, num1 + num2),
        2 => println!("Resultado: {} - {} = {}", num1, num2, num1 - num2),
        3 => println!("Resultado: {} * {} = {}", num1, num2, num1 * num2),
        4 => {
            if num2 == 0.0 {
                println!("Erro: Divisão por zero não é permitida!");
            } else {
                println!("Resultado: {} / {} = {}", num1, num2, num1 / num2);
            }
        }
        _ => println!("Opção inválida!"),
    }
}

fn ler_numero<T: std::str::FromStr>() -> T {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Falha ao ler a linha");

    match input.trim().parse::<T>() {
        Ok(num) => num,
        Err(_) => {
            println!("Entrada inválida! Por favor, digite um número.");
            std::process::exit(1);
        }
    }
}
