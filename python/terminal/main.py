def show_menu():
    print("=== Calculadora em Python ===")
    print("1. Adição (+)")
    print("2. Subtração (-)")
    print("3. Multiplicação (*)")
    print("4. Divisão (/)")


def read_number(label):
    while True:
        try:
            return float(input(label))
        except ValueError:
            print("Entrada inválida. Digite um número válido.")


show_menu()
choice = int(input("Escolha a operação (1-4): "))
num1 = read_number("Digite o primeiro número: ")
num2 = read_number("Digite o segundo número: ")

if choice == 1:
    result = num1 + num2
    print(f"Resultado: {num1} + {num2} = {result}")
elif choice == 2:
    result = num1 - num2
    print(f"Resultado: {num1} - {num2} = {result}")
elif choice == 3:
    result = num1 * num2
    print(f"Resultado: {num1} * {num2} = {result}")
elif choice == 4:
    if num2 == 0:
        print("Erro: Divisão por zero não é permitida!")
    else:
        result = num1 / num2
        print(f"Resultado: {num1} / {num2} = {result}")
else:
    print("Opção inválida!")
