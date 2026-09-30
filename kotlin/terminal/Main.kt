import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)

    println("=== Calculadora em Kotlin ===")
    println("1. Adição (+)")
    println("2. Subtração (-)")
    println("3. Multiplicação (*)")
    println("4. Divisão (/)")
    print("Escolha a operação (1-4): ")
    val escolha = scanner.nextInt()

    print("Digite o primeiro número: ")
    val num1 = scanner.nextDouble()

    print("Digite o segundo número: ")
    val num2 = scanner.nextDouble()

    when (escolha) {
        1 -> println("Resultado: ${num1} + ${num2} = ${num1 + num2}")
        2 -> println("Resultado: ${num1} - ${num2} = ${num1 - num2}")
        3 -> println("Resultado: ${num1} * ${num2} = ${num1 * num2}")
        4 -> {
            if (num2 == 0.0) {
                println("Erro: Divisão por zero não é permitida!")
            } else {
                println("Resultado: ${num1} / ${num2} = ${num1 / num2}")
            }
        }
        else -> println("Opção inválida!")
    }
}
