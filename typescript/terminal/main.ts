import * as readline from 'readline';

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

function question(prompt: string): Promise<string> {
  return new Promise((resolve) => rl.question(prompt, resolve));
}

async function main() {
  console.log('=== Calculadora em TypeScript ===');
  console.log('1. Adição (+)');
  console.log('2. Subtração (-)');
  console.log('3. Multiplicação (*)');
  console.log('4. Divisão (/)');

  const escolha = Number(await question('Escolha a operação (1-4): '));
  const num1 = Number(await question('Digite o primeiro número: '));
  const num2 = Number(await question('Digite o segundo número: '));

  if (escolha === 1) {
    console.log(`Resultado: ${num1} + ${num2} = ${num1 + num2}`);
  } else if (escolha === 2) {
    console.log(`Resultado: ${num1} - ${num2} = ${num1 - num2}`);
  } else if (escolha === 3) {
    console.log(`Resultado: ${num1} * ${num2} = ${num1 * num2}`);
  } else if (escolha === 4) {
    if (num2 === 0) {
      console.log('Erro: Divisão por zero não é permitida!');
    } else {
      console.log(`Resultado: ${num1} / ${num2} = ${num1 / num2}`);
    }
  } else {
    console.log('Opção inválida!');
  }

  rl.close();
}

main();
