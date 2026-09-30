<?php
// Inicializa as variáveis para não dar erro de aviso (Notice)
$resultado = "Resultado: ";
$num1 = "";
$num2 = "";

// Verifica se o formulário foi enviado via método POST
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $num1 = filter_input(INPUT_POST, 'num1', FILTER_VALIDATE_FLOAT);
    $num2 = filter_input(INPUT_POST, 'num2', FILTER_VALIDATE_FLOAT);
    $operacao = $_POST['operacao'] ?? '';

    if ($num1 === false || $num2 === false || $num1 === null || $num2 === null) {
        $resultado = "Erro: Digite números válidos!";
    } else {
        switch ($operacao) {
            case '+':
                $res = $num1 + $num2;
                $resultado = "Resultado: $res";
                break;
            case '-':
                $res = $num1 - $num2;
                $resultado = "Resultado: $res";
                break;
            case '*':
                $res = $num1 * $num2;
                $resultado = "Resultado: $res";
                break;
            case '/':
                if ($num2 == 0) {
                    $resultado = "Erro: Divisão por zero!";
                } else {
                    $res = $num1 / $num2;
                    $resultado = "Resultado: $res";
                }
                break;
            default:
                $resultado = "Erro: Operação inválida!";
        }
    }
}
?>

<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <title>Calculadora em PHP</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #f7f9fa;
        }
        .calculadora {
            background: white;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 4px 10px rgba(0,0,0,0.1);
            width: 280px;
        }
        h3 { margin-top: 0; text-align: center; color: #333; }
        input[type="number"] {
            width: 100%;
            padding: 8px;
            margin: 8px 0;
            box-sizing: border-box;
            border: 1px solid #ccc;
            border-radius: 4px;
        }
        .botoes {
            display: grid;
            grid-template-columns: repeat(4, 1fr);
            gap: 8px;
            margin: 12px 0;
        }
        button {
            padding: 10px;
            font-size: 16px;
            cursor: pointer;
            background-color: #28a745;
            color: white;
            border: none;
            border-radius: 4px;
        }
        button:hover { background-color: #218838; }
        .caixa-resultado {
            font-weight: bold;
            margin-top: 15px;
            color: #222;
            text-align: center;
        }
    </style>
</head>
<body>

<div class="calculadora">
    <h3>Calculadora PHP</h3>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
        <input type="number" step="any" name="num1" value="<?php echo htmlspecialchars($num1); ?>" placeholder="Primeiro número" required>
        <input type="number" step="any" name="num2" value="<?php echo htmlspecialchars($num2); ?>" placeholder="Segundo número" required>

        <div class="botoes">
            <button type="submit" name="operacao" value="+">+</button>
            <button type="submit" name="operacao" value="-">-</button>
            <button type="submit" name="operacao" value="*">*</button>
            <button type="submit" name="operacao" value="/">/</button>
        </div>
    </form>

    <div class="caixa-resultado">
        <?php echo $resultado; ?>
    </div>
</div>

</body>
</html>
