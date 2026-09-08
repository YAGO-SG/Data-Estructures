#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no {
    int info;
    struct no * esq;
    struct no * dir;
}Tnoa;

void implementaNo(Tnoa * a, int x, int y) {
    Tnoa * novo1 = (Tnoa*) malloc(sizeof(Tnoa));
    Tnoa * novo2 = (Tnoa*) malloc(sizeof(Tnoa));
    novo1->info = x;
    novo1->esq = NULL;
    novo1->dir = NULL;
    novo2->info = y;
    novo2->esq = NULL;
    novo2->dir = NULL;
    a->esq = novo1;
    a->dir = novo2;
}

void imprimeNo(Tnoa * arv, int a) {

    if(arv != NULL) {
        char espaço[a + 1];
        for(int i = 0; i < a; i++) {
            espaço[i] = '-';
        }

        espaço[a] = '\0';

        printf("%s %d\n", espaço, arv->info);

        imprimeNo(arv->esq, a + 2);
        imprimeNo(arv->dir, a + 2);
    }
}


int verifica(Tnoa * arvore, int var) {
    if(arvore == NULL) {
        return var;
    }

    int comp1 = verifica(arvore->esq, var + 1);
    int comp2 = verifica(arvore->dir, var + 1);

    if(comp1 == comp2 && comp1 != 0 && comp2 != 0) {
        if(var == 0) {
            return 1;
        } else {
            return (comp1 + comp2);
        }
    }  else {
        return 0;
    }
}

int main() {
    Tnoa * head = (Tnoa*) malloc(sizeof(Tnoa));
    head->info = 5;

    implementaNo(head, 1, 3);
    implementaNo(head->esq, 34, 54);
    implementaNo(head->dir, 23, 85);

    imprimeNo(head, 0);

    int resultado = verifica(head, 0);
    if(resultado == 1) {
        printf("\n Cheia \n");
    } else {
        printf("\n não cheia \n");
    }

    return 0;
}