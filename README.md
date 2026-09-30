# Calculator Poligloty

Projeto para comparar implementações de uma calculadora simples em diferentes linguagens, separando versões de terminal e versões gráficas.

A estrutura foi organizada para seguir o conteúdo do rascunho, com as linguagens que aparecem nele. O TypeScript foi mantido como complemento manual, porque não estava no material original.

## Estrutura do projeto

```text
calculator-poligloty/
├── .docs/
│   └── rascunho.md
├── go/
│   ├── terminal/
│   └── graphic/
├── cpp/
│   ├── terminal/
│   └── graphic/
├── rust/
│   ├── terminal/
│   └── graphic/
├── javascript/
│   ├── terminal/
│   └── graphic/
├── php/
│   ├── terminal/
│   └── graphic/
├── python/
│   ├── terminal/
│   └── graphic/
├── java/
│   ├── terminal/
│   └── graphic/
├── csharp/
│   ├── terminal/
│   └── graphic/
├── c/
│   ├── terminal/
│   └── graphic/
├── typescript/
│   ├── terminal/
│   └── graphic/
├── README.md
└── .gitignore
```

## Linguagens incluídas

- Go
- C++
- Rust
- JavaScript
- PHP
- Python
- Java
- C#
- C
- TypeScript (manual)

## Sites oficiais

- Go — https://go.dev/
- C++ — https://isocpp.org/
- Rust — https://www.rust-lang.org/
- JavaScript — https://tc39.es/
- PHP — https://www.php.net/
- Python — https://www.python.org/
- Java — https://www.java.com/
- C# — https://learn.microsoft.com/dotnet/csharp/
- C — https://www.open-std.org/jtc1/sc22/wg14/
- TypeScript — https://www.typescriptlang.org/

## Mockup visual da calculadora

```mermaid
flowchart TB
    A[Calculadora] --> B[Display]
    B --> C[7]
    B --> D[8]
    B --> E[9]
    B --> F[/]
    G[4] --> B
    H[5] --> B
    I[6] --> B
    J[*] --> B
    K[1] --> B
    L[2] --> B
    M[3] --> B
    N[-] --> B
    O[0] --> B
    P[.] --> B
    Q[=] --> B
    R[+ ] --> B
    B --> S[Resultado]
```

Esse mockup representa a estrutura visual comum das versões gráficas: display central, teclas numéricas e operadores, e botão de resultado.

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

### JavaScript

```bash
cd javascript/terminal
node main.js
```

### PHP

```bash
cd php/terminal
php calculadora.php
```

### Python

```bash
cd python/terminal
python3 main.py
```

### Java

```bash
cd java/terminal
javac Calculadora.java
java Calculadora
```

### C#

```bash
cd csharp/terminal
dotnet run
```

### C

```bash
cd c/terminal
gcc main.c -o calculadora
./calculadora
```

### TypeScript

```bash
cd typescript/terminal
tsc main.ts
node main.js
```

## Descrição da divisão

- `terminal`: versões em linha de comando.
- `graphic`: versões com interface visual.
- `docs`: documentação do projeto.

## Objetivo

O projeto tem como objetivo comparar a mesma lógica de calculadora em diferentes linguagens e modelos de interface, mantendo a organização por linguagem e tipo de execução.
