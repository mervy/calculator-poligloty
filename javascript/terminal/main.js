const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

console.log('=== Calculadora em JavaScript ===');
console.log('1. Adição (+)');
console.log('2. Subtração (-)');
console.log('3. Multiplicação (*)');
console.log('4. Divisão (/)');

rl.question('Escolha a operação (1-4): ', (escolhaStr) => {
  const escolha = Number(escolhaStr);

  rl.question('Digite o primeiro número: ', (num1Str) => {
    const num1 = Number(num1Str);

    rl.question('Digite o segundo número: ', (num2Str) => {
      const num2 = Number(num2Str);

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
    });
  });
});
