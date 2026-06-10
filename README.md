# Avaliador de expressões numéricas

# Calculadora de Expressões Pós-Fixas

## Descrição

Este projeto foi desenvolvido para a disciplina de Estrutura de Dados da Universidade Católica de Brasília (UCB), com o objetivo de implementar uma calculadora de expressões matemáticas utilizando a linguagem C e a estrutura de dados Pilha.

O sistema é capaz de converter expressões da notação pós-fixa (Reverse Polish Notation - RPN) para a notação infixa e realizar a avaliação numérica das expressões, incluindo operações aritméticas básicas e funções matemáticas especiais.

---

## Objetivos

* Converter expressões da forma pós-fixa para a forma infixa.
* Avaliar expressões matemáticas utilizando pilhas.
* Implementar operadores binários e unários.
* Tratar erros e inconsistências nas entradas.
* Aplicar conceitos de Estrutura de Dados utilizando Pilhas.

---

## Funcionalidades Implementadas

### Conversão de Expressões

Conversão de expressões pós-fixas para expressões infixas com uso adequado de parênteses.

Exemplo:

Posfixa:
3 4 + 5 *

Infixa:
(3+4)*5

---

### Operadores Aritméticos

| Operador | Descrição        |
| -------- | ---------------- |
| +        | Soma             |
| -        | Subtração        |
| *        | Multiplicação    |
| /        | Divisão          |
| %        | Resto da divisão |
| ^        | Potenciação      |

---

### Funções Matemáticas

| Função | Descrição         |
| ------ | ----------------- |
| raiz   | Raiz quadrada     |
| sen    | Seno              |
| cos    | Cosseno           |
| tg     | Tangente          |
| log    | Logaritmo decimal |

Observação: As funções trigonométricas recebem ângulos em graus.

---

## Estrutura do Projeto

O projeto foi desenvolvido seguindo a estrutura definida pelo professor.

### Arquivo de Cabeçalho

calculadora.h

Responsável pela definição da estrutura Expressao e dos protótipos das funções principais.

### Arquivo Principal

main.c

Responsável pela execução dos testes e interação com as funções implementadas.

### Arquivo de Implementação

matricula.c

Contém a implementação das funções:

```c
char *getInFixa(char *Str);
float getValor(char *Str);
```

bem como funções auxiliares internas necessárias para o funcionamento do sistema.

---

## Estrutura Utilizada

### Pilha

A pilha foi utilizada para:

* Conversão de expressões pós-fixas para infixas.
* Avaliação numérica das expressões.
* Armazenamento temporário de operandos e operadores.

---

## Tratamento de Erros

O programa verifica situações inválidas como:

* Operadores desconhecidos.
* Quantidade insuficiente de operandos.
* Divisão por zero.
* Logaritmo de número menor ou igual a zero.
* Raiz quadrada de número negativo.
* Expressões mal formadas.

Quando ocorre erro na conversão, a função:

```c
getInFixa()
```

retorna:

```c
NULL
```

---

## Casos de Teste

### Teste 1

Posfixa:

```text
3 4 + 5 *
```

Infixa:

```text
(3+4)*5
```

Resultado:

```text
35
```

---

### Teste 2

Posfixa:

```text
7 2 * 4 +
```

Infixa:

```text
7*2+4
```

Resultado:

```text
18
```

---

### Teste 3

Posfixa:

```text
8 5 2 4 + * +
```

Infixa:

```text
8+(5*(2+4))
```

Resultado:

```text
38
```

---

### Teste 4

Posfixa:

```text
6 2 / 3 + 4 *
```

Infixa:

```text
(6/2+3)*4
```

Resultado:

```text
24
```

---

## Compilação

O projeto deve ser compilado utilizando o comando:

```bash
gcc matricula.c main.c -o calculadora.exe
```

Substituindo "matricula.c" pelo número da matrícula do aluno.

Exemplo:

```bash
gcc 26209999.c main.c -o calculadora.exe
```

---

## Requisitos

* Linguagem C padrão.
* Compatível com Dev-C++.
* Compatível com VS Code + GCC.
* Compatível com Windows.

---

## Autor

Aluno: Gustavo Augusto

Disciplina: Estrutura de Dados

Professor: Marcelo Eustáquio

Universidade Católica de Brasília (UCB)

1º Semestre de 2026
