#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calculadora.h"

#define MAX 512

typedef struct {
    float itens[MAX];
    int topo;
} PilhaFloat;

typedef struct {
    char itens[MAX][MAX];
    int topo;
} PilhaString;

void pushFloat(PilhaFloat *p, float v) {
    p->itens[++p->topo] = v;
}

float popFloat(PilhaFloat *p) {
    return p->itens[p->topo--];
}

void pushString(PilhaString *p, char *s) {
    strcpy(p->itens[++p->topo], s);
}

char *popString(PilhaString *p) {
    return p->itens[p->topo--];
}

int operador(char *s) {
    return !strcmp(s, "+") ||
           !strcmp(s, "-") ||
           !strcmp(s, "*") ||
           !strcmp(s, "/") ||
           !strcmp(s, "%") ||
           !strcmp(s, "^");
}

int funcao(char *s) {
    return !strcmp(s, "sen") ||
           !strcmp(s, "cos") ||
           !strcmp(s, "tan") ||
           !strcmp(s, "log") ||
           !strcmp(s, "sqrt");
}

float graus(float x) {
    return x * M_PI / 180.0;
}

float getValor(char *Str) {

    PilhaFloat p;
    p.topo = -1;

    char copia[MAX];
    strcpy(copia, Str);

    char *token = strtok(copia, " ");

    while(token) {

        if(operador(token)) {

            if(p.topo < 1)
                return NAN;

            float b = popFloat(&p);
            float a = popFloat(&p);

            if(!strcmp(token, "+"))
                pushFloat(&p, a+b);

            else if(!strcmp(token, "-"))
                pushFloat(&p, a-b);

            else if(!strcmp(token, "*"))
                pushFloat(&p, a*b);

            else if(!strcmp(token, "/")) {

                if(b == 0)
                    return NAN;

                pushFloat(&p, a/b);
            }

            else if(!strcmp(token, "%")) {

                if(b == 0)
                    return NAN;

                pushFloat(&p, (int)a % (int)b);
            }

            else if(!strcmp(token, "^"))
                pushFloat(&p, pow(a,b));

        }
        else if(funcao(token)) {

            if(p.topo < 0)
                return NAN;

            float a = popFloat(&p);

            if(!strcmp(token, "sen"))
                pushFloat(&p, sin(graus(a)));

            else if(!strcmp(token, "cos"))
                pushFloat(&p, cos(graus(a)));

            else if(!strcmp(token, "tan"))
                pushFloat(&p, tan(graus(a)));

            else if(!strcmp(token, "log")) {

                if(a <= 0)
                    return NAN;

                pushFloat(&p, log10(a));
            }

            else if(!strcmp(token, "sqrt")) {

                if(a < 0)
                    return NAN;

                pushFloat(&p, sqrt(a));
            }

        }
        else {
            pushFloat(&p, atof(token));
        }

        token = strtok(NULL, " ");
    }

    if(p.topo != 0)
        return NAN;

    return popFloat(&p);
}

char *getInFixa(char *Str) {

    static char resultado[MAX];

    PilhaString p;
    p.topo = -1;

    char copia[MAX];
    strcpy(copia, Str);

    char *token = strtok(copia, " ");

    while(token) {

        if(operador(token)) {

            if(p.topo < 1)
                return NULL;

            char b[MAX];
            char a[MAX];
            char expr[MAX];

            strcpy(b, popString(&p));
            strcpy(a, popString(&p));

            sprintf(expr, "(%s %s %s)", a, token, b);

            pushString(&p, expr);
        }
        else if(funcao(token)) {

            if(p.topo < 0)
                return NULL;

            char a[MAX];
            char expr[MAX];

            strcpy(a, popString(&p));

            sprintf(expr, "%s(%s)", token, a);

            pushString(&p, expr);
        }
        else {
            pushString(&p, token);
        }

        token = strtok(NULL, " ");
    }

    if(p.topo != 0)
        return NULL;

    strcpy(resultado, popString(&p));

    return resultado;
}
