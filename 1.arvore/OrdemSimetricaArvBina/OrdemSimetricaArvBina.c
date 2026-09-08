#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no {
    int info;
    struct no * esq;
    struct no * dir;
}Tnoa;

typedef struct lista {
    Tnoa * no;
    struct lista * prox;
} Tlista;

Tlista * push(Tnoa * no, Tlista * lista) {
    if(no == NULL) {
        return lista;
    }

    Tlista * novo = (Tlista*) malloc(sizeof(Tlista));
    novo->no = no;
    novo->prox = lista;

    return novo;
}

Tlista * pop(Tlista * lista) {
    Tlista * aux = lista->prox;
    free(lista);

    return aux;
}

Tlista * percorreEsq(Tlista * lista) {
    while(lista->no->esq != NULL) {
        lista = push(lista->no->esq, lista);
    }

    return lista;
}

void OrdemSimetrica(Tnoa * arvore) {
    Tlista * lista = NULL;
    lista = push(arvore, lista);
    lista = percorreEsq(lista);
    while(lista != NULL) {
        printf(" %d \n", lista->no->info);
        if(lista->no->dir != NULL) {
            Tnoa * aux = lista->no->dir;
            lista = pop(lista);
            lista = push(aux, lista);
            lista = percorreEsq(lista);
        } else {
            lista = pop(lista);
            if(lista == NULL) {
                break;
            }
            printf(" %d \n", lista->no->info);
            Tnoa * aux = lista->no->dir;
            lista = pop(lista);
            lista = push(aux, lista);
            if(aux != NULL) {
                lista = percorreEsq(lista);
            } 
        }
    }
}

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


int main() {
    Tnoa * head = (Tnoa*) malloc(sizeof(Tnoa));
    head->info = 5;

    implementaNo(head, 1, 3);
    implementaNo(head->esq, 34, 54);
    implementaNo(head->dir, 23, 85);

    OrdemSimetrica(head);

    return 0;
}