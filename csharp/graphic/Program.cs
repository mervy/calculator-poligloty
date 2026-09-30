using Avalonia;
using Avalonia.Controls;
using Avalonia.Layout;
using Avalonia.Markup.Xaml;
using System;

namespace CalculadoraAvalonia
{
    public class App : Application
    {
        public override void Initialize()
        {
            AvaloniaXamlLoader.Load(this);
        }

        public override void OnFrameworkInitializationCompleted()
        {
            if (ApplicationLifetime is Avalonia.Controls.ApplicationLifetimes.IClassicDesktopStyleApplicationLifetime desktop)
            {
                desktop.MainWindow = new MainWindow();
            }

            base.OnFrameworkInitializationCompleted();
        }
    }

    public class MainWindow : Window
    {
        private TextBox _campoNum1;
        private TextBox _campoNum2;
        private TextBlock _labelResultado;

        public MainWindow()
        {
            Title = "Calculadora em C#";
            Width = 300;
            Height = 250;
            CanResize = false;
            WindowStartupLocation = WindowStartupLocation.CenterScreen;

            var painelPrincipal = new StackPanel
            {
                Spacing = 10,
                Margin = new Thickness(20),
                HorizontalAlignment = HorizontalAlignment.Center
            };

            var titulo = new TextBlock
            {
                Text = "=== Calculadora Visual ===",
                FontWeight = Avalonia.Media.FontWeight.Bold,
                HorizontalAlignment = HorizontalAlignment.Center
            };
            painelPrincipal.Children.Add(titulo);

            _campoNum1 = new TextBox { Width = 200, Watermark = "Primeiro número" };
            _campoNum2 = new TextBox { Width = 200, Watermark = "Segundo número" };
            painelPrincipal.Children.Add(_campoNum1);
            painelPrincipal.Children.Add(_campoNum2);

            var gridBotoes = new UniformGrid { Columns = 4, Width = 200 };

            var btnMais = new Button { Content = "  +  ", HorizontalAlignment = HorizontalAlignment.Center };
            var btnMenos = new Button { Content = "  -  ", HorizontalAlignment = HorizontalAlignment.Center };
            var btnVezes = new Button { Content = "  *  ", HorizontalAlignment = HorizontalAlignment.Center };
            var btnDiv = new Button { Content = "  /  ", HorizontalAlignment = HorizontalAlignment.Center };

            btnMais.Click += (s, e) => Calcular("+");
            btnMenos.Click += (s, e) => Calcular("-");
            btnVezes.Click += (s, e) => Calcular("*");
            btnDiv.Click += (s, e) => Calcular("/");

            gridBotoes.Children.Add(btnMais);
            gridBotoes.Children.Add(btnMenos);
            gridBotoes.Children.Add(btnVezes);
            gridBotoes.Children.Add(btnDiv);
            painelPrincipal.Children.Add(gridBotoes);

            _labelResultado = new TextBlock
            {
                Text = "Resultado: ",
                FontWeight = Avalonia.Media.FontWeight.Bold,
                HorizontalAlignment = HorizontalAlignment.Center,
                Margin = new Thickness(0, 10, 0, 0)
            };
            painelPrincipal.Children.Add(_labelResultado);

            Content = painelPrincipal;
        }

        private void Calcular(string operacao)
        {
            if (!double.TryParse(_campoNum1.Text, out double n1) || !double.TryParse(_campoNum2.Text, out double n2))
            {
                _labelResultado.Text = "Erro: Digite números válidos!";
                return;
            }

            double res = 0;
            switch (operacao)
            {
                case "+": res = n1 + n2; break;
                case "-": res = n1 - n2; break;
                case "*": res = n1 * n2; break;
                case "/":
                    if (n2 == 0)
                    {
                        _labelResultado.Text = "Erro: Divisão por zero!";
                        return;
                    }
                    res = n1 / n2;
                    break;
            }

            _labelResultado.Text = $"Resultado: {res:F2}";
        }
    }
}
