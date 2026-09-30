package main

import (
	"fmt"
)

func main() {
	var escolha int
	var num1, num2, resultado float64

	fmt.Println("=== Calculadora em Go ===")
	fmt.Println("1. Adição (+)")
	fmt.Println("2. Subtração (-)")
	fmt.Println("3. Multiplicação (*)")
	fmt.Println("4. Divisão (/)")
	fmt.Print("Escolha a operação (1-4): ")
	fmt.Scan(&escolha)

	fmt.Print("Digite o primeiro número: ")
	fmt.Scan(&num1)

	fmt.Print("Digite o segundo número: ")
	fmt.Scan(&num2)

	switch escolha {
	case 1:
		resultado = num1 + num2
		fmt.Printf("Resultado: %.2f + %.2f = %.2f\n", num1, num2, resultado)
	case 2:
		resultado = num1 - num2
		fmt.Printf("Resultado: %.2f - %.2f = %.2f\n", num1, num2, resultado)
	case 3:
		resultado = num1 * num2
		fmt.Printf("Resultado: %.2f * %.2f = %.2f\n", num1, num2, resultado)
	case 4:
		if num2 == 0 {
			fmt.Println("Erro: Divisão por zero não é permitida!")
		} else {
			resultado = num1 / num2
			fmt.Printf("Resultado: %.2f / %.2f = %.2f\n", num1, num2, resultado)
		}
	default:
		fmt.Println("Opção inválida!")
	}
}
