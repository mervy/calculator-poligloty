<?php

echo "=== Calculadora em PHP ===\n";
echo "1. Adição (+)\n";
echo "2. Subtração (-)\n";
echo "3. Multiplicação (*)\n";
echo "4. Divisão (/)\n";

echo "Escolha a operação (1-4): ";
$escolha = intval(fgets(STDIN));

echo "Digite o primeiro número: ";
$num1 = floatval(fgets(STDIN));

echo "Digite o segundo número: ";
$num2 = floatval(fgets(STDIN));

switch ($escolha) {
    case 1:
        $resultado = $num1 + $num2;
        echo "Resultado: $num1 + $num2 = $resultado\n";
        break;
    case 2:
        $resultado = $num1 - $num2;
        echo "Resultado: $num1 - $num2 = $resultado\n";
        break;
    case 3:
        $resultado = $num1 * $num2;
        echo "Resultado: $num1 * $num2 = $resultado\n";
        break;
    case 4:
        if ($num2 == 0) {
            echo "Erro: Divisão por zero não é permitida!\n";
        } else {
            $resultado = $num1 / $num2;
            echo "Resultado: $num1 / $num2 = $resultado\n";
        }
        break;
    default:
        echo "Opção inválida!\n";
        break;
}
