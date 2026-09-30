# Calculator Poligloty

Projeto para comparar implementações de uma calculadora simples em diferentes linguagens de programação, separando versões que rodam no terminal e versões que podem evoluir para interface gráfica.

A ideia principal é demonstrar como a mesma funcionalidade pode ser escrita em diversas linguagens, mantendo a lógica de operação e o comportamento do usuário em cada ambiente.

## Estrutura do projeto

```text
calculator-poligloty/
├── docs/
├── go/
│   ├── terminal/
│   └── graphic/
├── cpp/
│   ├── terminal/
│   └── graphic/
├── rust/
│   ├── terminal/
│   └── graphic/
├── python/
│   ├── terminal/
│   └── graphic/
├── java/
│   ├── terminal/
│   └── graphic/
├── javascript/
│   ├── terminal/
│   └── graphic/
├── typescript/
│   ├── terminal/
│   └── graphic/
├── csharp/
│   ├── terminal/
│   └── graphic/
├── kotlin/
│   ├── terminal/
│   └── graphic/
├── README.md
├── rascunho.md
└── docs/
```

## Linguagens incluídas

- Go
- C++
- Rust
- Python
- Java
- JavaScript
- TypeScript
- C#
- Kotlin

## Como executar as versões de terminal

### Go

```bash
cd go/terminal
go run main.go
```

### C++

```bash
cd cpp/terminal
g++ main.cpp -o calculadora
./calculadora
```

### Rust

```bash
cd rust/terminal
rustc main.rs -o calculadora
./calculadora
```

### Python

```bash
cd python/terminal
python3 main.py
```

### Java

```bash
cd java/terminal
javac Main.java
java Main
```

### JavaScript

```bash
cd javascript/terminal
node main.js
```

### TypeScript

```bash
cd typescript/terminal
tsc main.ts
node main.js
```

### C#

```bash
cd csharp/terminal
dotnet run
```

### Kotlin

```bash
cd kotlin/terminal
kotlinc Main.kt -include-runtime -d calculadora.jar
java -jar calculadora.jar
```

## Descrição da divisão

- `terminal`: versões de linha de comando, com menu e leitura de números pelo console.
- `graphic`: estrutura preparada para versões futuras com interface visual.
- `docs`: documentação e comparativos do projeto.

## Objetivo

O projeto serve como base para estudo, comparação de sintaxe e organização de código entre diversas linguagens, além de permitir evoluir para versões com interface gráfica no futuro.
