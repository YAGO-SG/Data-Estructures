#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNoA {
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

int altura(TNoA * a) {
    if(!a) return 0;
    int dir = altura(a->dir);
    int esq = altura(a->esq);
    if(esq > dir) {
        return esq + 1;
    } else {
        return dir + 1;
    }
}

int verificaAVL(TNoA * a) {
    int esq = altura(a->esq);
    int dir = altura(a->dir);
    int dif = dir - esq;
    if(dif > 1 || dif < -1) {
        return 0;
    } else {
        return 1;
    }
}

int eh_avl(TNoA * a) {
    if(!a) return 1;
    TNoA * b = a->esq;
    TNoA * c = a->dir;
    if(b && b->chave >= a->chave) {
        return 0;
    } else if(c && a->chave >= c->chave) {
        return 0;
    }
    int res = verificaAVL(a);
    if(res == 0) return 0;
    int esq = eh_avl(a->esq);
    int dir = eh_avl(a->dir);
    if(esq == 0 || dir == 0) {
        return 0;
    } else {
        return 1;
    }
}