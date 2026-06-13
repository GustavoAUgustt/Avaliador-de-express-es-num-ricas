#include <stdio.h>
#include <string.h>
#include "calculadora.h"

int main() {

    char expr[512];

    printf("Digite a expressao pos-fixa:\n");

    if (fgets(expr, sizeof(expr), stdin) == NULL) {
        printf("Erro na leitura.\n");
        return 1;
    }

    expr[strcspn(expr, "\n")] = '\0';

    char *infixa = getInFixa(expr);

    if (infixa == NULL) {
        printf("Expressao invalida!\n");
        return 1;
    }

    printf("\nForma infixa:\n%s\n", infixa);
    printf("\nResultado:\n%.4f\n", getValor(expr));

    return 0;
}
