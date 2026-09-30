using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("=== Calculadora em C# ===");
        Console.WriteLine("1. Adição (+)");
        Console.WriteLine("2. Subtração (-)");
        Console.WriteLine("3. Multiplicação (*)");
        Console.WriteLine("4. Divisão (/)");
        Console.Write("Escolha a operação (1-4): ");
        int escolha = int.Parse(Console.ReadLine());

        Console.Write("Digite o primeiro número: ");
        double num1 = double.Parse(Console.ReadLine());

        Console.Write("Digite o segundo número: ");
        double num2 = double.Parse(Console.ReadLine());

        switch (escolha)
        {
            case 1:
                Console.WriteLine($"Resultado: {num1} + {num2} = {num1 + num2}");
                break;
            case 2:
                Console.WriteLine($"Resultado: {num1} - {num2} = {num1 - num2}");
                break;
            case 3:
                Console.WriteLine($"Resultado: {num1} * {num2} = {num1 * num2}");
                break;
            case 4:
                if (num2 == 0)
                {
                    Console.WriteLine("Erro: Divisão por zero não é permitida!");
                }
                else
                {
                    Console.WriteLine($"Resultado: {num1} / {num2} = {num1 / num2}");
                }
                break;
            default:
                Console.WriteLine("Opção inválida!");
                break;
        }
    }
}
