package main

import (
	"strconv"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/app"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/widget"
)

func main() {
	meuApp := app.New()
	janela := meuApp.NewWindow("Calculadora em Go")
	janela.Resize(fyne.NewSize(300, 400))

	campoNum1 := widget.NewEntry()
	campoNum1.SetPlaceHolder("Primeiro número")

	campoNum2 := widget.NewEntry()
	campoNum2.SetPlaceHolder("Segundo número")

	labelResultado := widget.NewLabel("Resultado: ")

	calcular := func(operacao string) {
		n1, err1 := strconv.ParseFloat(campoNum1.Text, 64)
		n2, err2 := strconv.ParseFloat(campoNum2.Text, 64)

		if err1 != nil || err2 != nil {
			labelResultado.SetText("Erro: Digite números válidos!")
			return
		}

		var res float64
		switch operacao {
		case "+":
			res = n1 + n2
		case "-":
			res = n1 - n2
		case "*":
			res = n1 * n2
		case "/":
			if n2 == 0 {
				labelResultado.SetText("Erro: Divisão por zero!")
				return
			}
			res = n1 / n2
		}
		labelResultado.SetText("Resultado: " + strconv.FormatFloat(res, 'f', 2, 64))
	}

	janela.SetContent(container.NewVBox(
		widget.NewLabel("=== Calculadora Visual ==="),
		campoNum1,
		campoNum2,
		container.NewGridWithColumns(4,
			widget.NewButton("+", func() { calcular("+") }),
			widget.NewButton("-", func() { calcular("-") }),
			widget.NewButton("*", func() { calcular("*") }),
			widget.NewButton("/", func() { calcular("/") }),
		),
		labelResultado,
	))

	janela.ShowAndRun()
}
