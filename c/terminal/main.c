#include <stdio.h>

int main() {
    int escolha;
    double num1, num2, resultado;

    printf("=== Calculadora em C ===\n");
    printf("1. Adição (+)\n");
    printf("2. Subtração (-)\n");
    printf("3. Multiplicação (*)\n");
    printf("4. Divisão (/)\n");
    printf("Escolha a operação (1-4): ");
    scanf("%d", &escolha);

    printf("Digite o primeiro número: ");
    scanf("%lf", &num1);

    printf("Digite o segundo número: ");
    scanf("%lf", &num2);

    switch (escolha) {
        case 1:
            resultado = num1 + num2;
            printf("Resultado: %.2f + %.2f = %.2f\n", num1, num2, resultado);
            break;
        case 2:
            resultado = num1 - num2;
            printf("Resultado: %.2f - %.2f = %.2f\n", num1, num2, resultado);
            break;
        case 3:
            resultado = num1 * num2;
            printf("Resultado: %.2f * %.2f = %.2f\n", num1, num2, resultado);
            break;
        case 4:
            if (num2 == 0) {
                printf("Erro: Divisão por zero não é permitida!\n");
            } else {
                resultado = num1 / num2;
                printf("Resultado: %.2f / %.2f = %.2f\n", num1, num2, resultado);
            }
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
