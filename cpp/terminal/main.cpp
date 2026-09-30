#include <iostream>

int main() {
    int escolha;
    double num1, num2, resultado;

    std::cout << "=== Calculadora em C++ ===\n";
    std::cout << "1. Adicao (+)\n";
    std::cout << "2. Subtracao (-)\n";
    std::cout << "3. Multiplicacao (*)\n";
    std::cout << "4. Divisao (/)\n";
    std::cout << "Escolha a operacao (1-4): ";
    std::cin >> escolha;

    std::cout << "Digite o primeiro numero: ";
    std::cin >> num1;

    std::cout << "Digite o segundo numero: ";
    std::cin >> num2;

    switch (escolha) {
        case 1:
            resultado = num1 + num2;
            std::cout << "Resultado: " << num1 << " + " << num2 << " = " << resultado << "\n";
            break;
        case 2:
            resultado = num1 - num2;
            std::cout << "Resultado: " << num1 << " - " << num2 << " = " << resultado << "\n";
            break;
        case 3:
            resultado = num1 * num2;
            std::cout << "Resultado: " << num1 << " * " << num2 << " = " << resultado << "\n";
            break;
        case 4:
            if (num2 == 0) {
                std::cout << "Erro: Divisao por zero nao e permitida!\n";
            } else {
                resultado = num1 / num2;
                std::cout << "Resultado: " << num1 << " / " << num2 << " = " << resultado << "\n";
            }
            break;
        default:
            std::cout << "Opcao invalida!\n";
    }

    return 0;
}
