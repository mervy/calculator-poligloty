import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalculadoraGUI extends JFrame implements ActionListener {
    private JTextField campoNum1, campoNum2;
    private JButton btnMais, btnMenos, btnVezes, btnDiv;
    private JLabel labelResultado;

    public CalculadoraGUI() {
        setTitle("Calculadora em Java");
        setSize(300, 250);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10));

        JLabel titulo = new JLabel("=== Calculadora Visual ===");
        titulo.setFont(new Font("Arial", Font.BOLD, 14));
        add(titulo);

        campoNum1 = new JTextField(20);
        campoNum1.setHorizontalAlignment(JTextField.CENTER);
        add(campoNum1);

        campoNum2 = new JTextField(20);
        campoNum2.setHorizontalAlignment(JTextField.CENTER);
        add(campoNum2);

        JPanel painelBotoes = new JPanel();
        painelBotoes.setLayout(new GridLayout(1, 4, 10, 0));

        btnMais = new JButton("+");
        btnMenos = new JButton("-");
        btnVezes = new JButton("*");
        btnDiv = new JButton("/");

        btnMais.addActionListener(this);
        btnMenos.addActionListener(this);
        btnVezes.addActionListener(this);
        btnDiv.addActionListener(this);

        painelBotoes.add(btnMais);
        painelBotoes.add(btnMenos);
        painelBotoes.add(btnVezes);
        painelBotoes.add(btnDiv);
        add(painelBotoes);

        labelResultado = new JLabel("Resultado: ");
        labelResultado.setFont(new Font("Arial", Font.BOLD, 12));
        add(labelResultado);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            double n1 = Double.parseDouble(campoNum1.getText());
            double n2 = Double.parseDouble(campoNum2.getText());
            double res = 0;

            Object fonte = e.getSource();

            if (fonte == btnMais) {
                res = n1 + n2;
            } else if (fonte == btnMenos) {
                res = n1 - n2;
            } else if (fonte == btnVezes) {
                res = n1 * n2;
            } else if (fonte == btnDiv) {
                if (n2 == 0) {
                    labelResultado.setText("Erro: Divisão por zero!");
                    return;
                }
                res = n1 / n2;
            }

            labelResultado.setText(String.format("Resultado: %.2f", res));

        } catch (NumberFormatException ex) {
            labelResultado.setText("Erro: Digite números válidos!");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new CalculadoraGUI().setVisible(true);
        });
    }
}
