#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no {
    int info;
    struct no * esq;
    struct no * dir;
}Tnoa;

typedef struct list {
    Tnoa * no;
    int quant;
    struct list * prox;
}Tlist;

int powi(int a, int b) {
    int res = 1;
    for(int i = 0; i < b; i++) {
        res = res * a;
    }
    return res;
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

Tlist * implementaLista(Tlist * lista, Tnoa * bloco) {
    Tlist * novo = (Tlist*) malloc(sizeof(Tlist));
    novo->no = bloco;
    novo->prox = NULL;

    Tlist * p = lista;

    if(p == NULL) {
        return novo;
    }


    while(p->prox != NULL) {
        p = p->prox;
    }

    p->prox = novo;

    return lista;
}

void imprimeLista(Tlist * lista) {
    while(lista != NULL) {
        printf("%d ", lista->no->info);
        lista = lista->prox;
    }
}

Tlist * criaListaLargura(Tnoa * no) {
    Tlist * listaLarg = NULL;
    listaLarg = implementaLista(listaLarg, no);
    listaLarg->quant += 1;

    Tlist * aux = listaLarg;

    while(aux != NULL) {
        if(aux->no->esq || aux->no->dir != NULL) {
            aux = implementaLista(aux, aux->no->esq);
            aux = implementaLista(aux, aux->no->dir);
            listaLarg->quant += 2;
        }

        aux = aux->prox;
    } 
    return listaLarg;
}

int verificaNo(Tlist * lista) {
    int nivel = 0;
    int var = 0;
    while(var < lista->quant) {
        var += powi(2, nivel);
        nivel += 1;
    }
    var = 1;
    while(var < nivel) {
        int pule = powi(2, var - 1);
        for(int i = 0; i < pule; i++) {
            lista = lista->prox;
        }
        var += 1;
    }
    int quantTotal = 0;
    while(lista != NULL) {
        quantTotal += 1;
        lista = lista->prox;
    }
    if(quantTotal == powi(2, nivel - 1)) {
        return 1;
    }

    return 0;
}


int main() {
    Tnoa * head = (Tnoa*) malloc(sizeof(Tnoa));
    head->info = 5;

    implementaNo(head, 1, 3);
    implementaNo(head->esq, 34, 54);
    implementaNo(head->dir, 23, 85);

    Tlist * listahead = criaListaLargura(head);

    imprimeNo(head, 0);
    imprimeLista(listahead);
    printf("\n %d", listahead->quant);

    int resultado = verificaNo(listahead);
    if(resultado == 1) {
        printf("\n Cheia \n");
    } else {
        printf("\n não cheia \n");
    }

    return 0;
}