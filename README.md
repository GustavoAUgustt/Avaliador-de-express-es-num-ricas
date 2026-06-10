# Avaliador de expressões numéricas

O que deve ser feito
O presente trabalho prático tem como objetivo desenvolver um programa em linguagem C capaz de avaliar
expressões matemáticas, com suporte às operações básicas e a funções matemáticas especiais. Além da
avaliação, o sistema deverá converter expressões da forma pós-fixa para a infixa, utilizando pilhas como
estrutura de dados fundamental.
Funcionalidades obrigatórias
O código-fonte deve contemplar as seguintes operações:
1. Converter expressões da notação pós-fixa para notação infixa; e, na versão final, para a notação pr-efixada.
2. Implementar as operações aritméticas básicas: +, –, *, /, % e ^;
3. Implementar raiz (raiz quadrada), sen (seno), cos (cosseno), tg (tangente) e log (logaritmo decimal);
4. Considerar que os ângulos utilizados em sen, cos e tg estão em graus; e, na versão final, considere ângulos em radianos.
5. As operações indicadas no item 3 devem operar sobre apenas um operando; e
6. Avaliar corretamente as expressões de teste apresentadas na tabela a seguir.
Teste Notação Posfixa Notação Infixa Valor
1 3 4 + 5 * (3 + 4) * 5 35
2 7 2 * 4 + 7 * 2 + 4 18
3 8 5 2 4 + * + 8 + (5 * (2 + 4)) 38
4 6 2 / 3 + 4 * (6 / 2 + 3) * 4 24
5 9 5 2 8 * 4 + * + 9 + (5 * (4 + 8 * 2)) 109
6 2 3 + log 5 / log(2 + 3) / 5 Aprox. 0.14
7 10 log 3 ^ 2 + log(10)^3 + 2 3
8 45 60 + 30 cos * (45 + 60) * cos(30) Aprox. 90.93
9 0.5 45 sen 2 ^ + 0.5+sen(45) ^2 1
Outros testes devem ser elaborados pelo aluno para validar integralmente o programa.
Critérios de avaliação
Durante a correção, serão analisados:
• O código fonte enviado pelo AVA;
• Estruturação modular do código com uso da linguagem C padrão;
• Identificação e tratamento de inconsistências nas entradas;
• Condições adequadas para execução das operações matemáticas.
Universidade Católica de Brasília – UCB
Estrutura de Dados – 1° semestre de 2026
Professor Marcelo Eustáquio
Atividade Avaliativa
2
Estrutura do projeto
O código deve ser organizado em três arquivos-fonte. O cabeçalho calculadora.h, abaixo, não deve ser
alterado:
#ifndef EXPRESSAO_H
#define EXPRESSAO_H
typedef struct {
char posFixa[512]; // Expressão na forma pos-fixa, como 3 12 4 + *
char inFixa[512]; // Expressão na forma infixa, como 3*(12+4)
float Valor; // Valor numérico da expressão
} Expressao;
char * getInFixa(char *Str); // Retorna a forma inFixa de Str (posFixa)
float getValor (char *Str); // Calcula o valor de Str (na forma posFixa)
#endif
Observações
1. Você deverá enviar somente um arquivo não compactado do tipo C, cujo nome deve ser formado pelos
dígitos do seu número de matrícula seguido de “.c”. Por exemplo, se seu número de matrícula é
UC26209999, o arquivo a ser enviado deve ter 26209999.c como nome. O mesmo será compilado
usando a seguinte instrução, considerando arquivo main.c presente nesta proposta de projeto:
gcc 26209999.c main.c -o calculadora.exe
2. Podem ser criadas funções auxiliares internas em calculadora.c, mas seus protótipos não devem ser
incluídos em calculadora.h.
3. Caso ocorra erro na função char *getInFixa(char *Str), esta deve retornar ponteiro NULL.
4. O código deve obedecer ao padrão C (bibliotecas, alocação de memória e escopo de variáveis),
compatível com Windows e compiladores como Dev-C++ ou VSCode.
5. A string de retorno de getInFixa() não deve conter espaços, nem parênteses além dos estritamente
necessários.
6. Para resultados aproximados, será aceita diferença absoluta máxima de 0.001.
7. Recomenda-se a criação de novos testes além dos fornecidos, para garantir o funcionamento completo
e robusto da solução;
8. Serão consideradas inválidas expressões com operadores desconhecidos, operandos insuficientes,
divisão por zero, logaritmo de número menor ou igual a zero e raiz de número negativo; e
9. Este trabalho prático é individual, vale 1,0 ponto e, caso seja entregue com atraso, será aplicada a
penalização de 10% por dia de atraso, passando a valer 𝟏, 𝟎 ∙ 𝟎, 𝟗
𝒏
, em que n é o número de dia de
atraso.
