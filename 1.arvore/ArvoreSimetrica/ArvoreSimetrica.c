#include<stdlib.h>
#include<stdio.h>

typedef struct Arvore {
    int chave;
    struct Arvore * esq;
    struct Arvore * dir;
}TNoA;

typedef struct Lista {
    TNoA * no;
    struct Lista * prox;
}TLista;

void push(TNoA * a, TLista ** lista) {
    TLista * novo = (TLista*) malloc(sizeof(TLista));
    novo->no = a;
    novo->prox = *lista;

    *lista = novo;
}

TLista * crialistaesq(TNoA * a, TLista ** lista) {
    if(!a) return NULL;
    push(a, lista);
    crialistaesq(a->esq, lista);
    crialistaesq(a->dir, lista);
    return lista;
}


TLista * crialistadir(TNoA * a, TLista ** lista) {
    if(!a) return NULL;
    push(a, lista);
    crialistadir(a->dir, lista);
    crialistadir(a->esq, lista);
    return lista;
}

int eh_simetrico(TNoA * a) {
    TLista * esq = NULL;
    TLista * dir = NULL;
    esq = crialistaesq(a->esq, &esq);
    dir = crialistadir(a->dir, &dir);
    while(esq || dir) {
        if(!esq) return 0;
        if(!dir) return 0;
        if(esq->no->chave != dir->no->chave) {
            return 0;
        }
        esq = esq->prox;
        dir = dir->prox;
    }
    return 1;
}