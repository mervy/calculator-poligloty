const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function fazerPergunta(query) {
    return new Promise(resolve => rl.question(query, resolve));
}

async function main() {
    console.log("=== Calculadora em JavaScript ===");
    console.log("1. Adição (+)");
    console.log("2. Subtração (-)");
    console.log("3. Multiplicação (*)");
    console.log("4. Divisão (/)");

    const escolha = parseInt(await fazerPergunta("Escolha a operação (1-4): "));
    const num1 = parseFloat(await fazerPergunta("Digite o primeiro número: "));
    const num2 = parseFloat(await fazerPergunta("Digite o segundo número: "));

    switch (escolha) {
        case 1:
            console.log(`Resultado: ${num1} + ${num2} = ${num1 + num2}`);
            break;
        case 2:
            console.log(`Resultado: ${num1} - ${num2} = ${num1 - num2}`);
            break;
        case 3:
            console.log(`Resultado: ${num1} * ${num2} = ${num1 * num2}`);
            break;
        case 4:
            if (num2 === 0) {
                console.log("Erro: Divisão por zero não é permitida!");
            } else {
                console.log(`Resultado: ${num1} / ${num2} = ${num1 / num2}`);
            }
            break;
        default:
            console.log("Opção inválida!");
    }

    rl.close();
}

main();
