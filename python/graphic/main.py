import tkinter as tk

def calcular(operacao):
    try:
        n1 = float(entry_num1.get())
        n2 = float(entry_num2.get())
    except ValueError:
        label_resultado.config(text="Erro: Digite números válidos!")
        return

    if operacao == "+":
        res = n1 + n2
    elif operacao == "-":
        res = n1 - n2
    elif operacao == "*":
        res = n1 * n2
    elif operacao == "/":
        if n2 == 0:
            label_resultado.config(text="Erro: Divisão por zero!")
            return
        res = n1 / n2

    label_resultado.config(text=f"Resultado: {res:.2f}".rstrip('0').rstrip('.'))

janela = tk.Tk()
janela.title("Calculadora em Python")
janela.geometry("300x250")
janela.resizable(False, False)

tk.Label(janela, text="=== Calculadora Visual ===", font=("Arial", 12, "bold")).pack(pady=10)

entry_num1 = tk.Entry(janela, justify="center", width=20)
entry_num1.insert(0, "Primeiro número")
entry_num1.pack(pady=5)

entry_num2 = tk.Entry(janela, justify="center", width=20)
entry_num2.insert(0, "Segundo número")
entry_num2.pack(pady=5)

frame_botoes = tk.Frame(janela)
frame_botoes.pack(pady=15)

tk.Button(frame_botoes, text="  +  ", command=lambda: calcular("+")).grid(row=0, column=0, padx=5)
tk.Button(frame_botoes, text="  -  ", command=lambda: calcular("-")).grid(row=0, column=1, padx=5)
tk.Button(frame_botoes, text="  *  ", command=lambda: calcular("*")).grid(row=0, column=2, padx=5)
tk.Button(frame_botoes, text="  /  ", command=lambda: calcular("/")).grid(row=0, column=3, padx=5)

label_resultado = tk.Label(janela, text="Resultado: ", font=("Arial", 10, "bold"))
label_resultado.pack(pady=5)

janela.mainloop()
