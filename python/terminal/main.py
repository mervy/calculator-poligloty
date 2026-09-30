def main():
    print("=== Calculadora em Python ===")
    print("1. Adição (+)")
    print("2. Subtração (-)")
    print("3. Multiplicação (*)")
    print("4. Divisão (/)")

    try:
        escolha = int(input("Escolha a operação (1-4): "))
        num1 = float(input("Digite o primeiro número: "))
        num2 = float(input("Digite o segundo número: "))
    except ValueError:
        print("Erro: Por favor, digite apenas números!")
        return

    match escolha:
        case 1:
            print(f"Resultado: {num1} + {num2} = {num1 + num2}")
        case 2:
            print(f"Resultado: {num1} - {num2} = {num1 - num2}")
        case 3:
            print(f"Resultado: {num1} * {num2} = {num1 * num2}")
        case 4:
            if num2 == 0:
                print("Erro: Divisão por zero não é permitida!")
            else:
                print(f"Resultado: {num1} / {num2} = {num1 / num2}")
        case _:
            print("Opção inválida!")

if __name__ == "__main__":
    main()
