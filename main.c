#include <stdio.h>
#include "calculadora.h"

int main() {

    char expr[512];

    printf("Digite a expressao pos-fixa:\n");
    fgets(expr, sizeof(expr), stdin);

    expr[strcspn(expr, "\n")] = '\0';

    char *infixa = getInFixa(expr);

    if(infixa == NULL) {
        printf("Expressao invalida!\n");
        return 1;
    }

    printf("\nForma infixa:\n%s\n", infixa);

    printf("\nResultado:\n%.4f\n", getValor(expr));

    return 0;
}
