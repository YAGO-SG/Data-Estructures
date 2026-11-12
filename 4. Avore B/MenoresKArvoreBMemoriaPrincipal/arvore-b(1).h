#ifndef ARVORE_B_ARVORE_B_H
#define ARVORE_B_ARVORE_B_H

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int m; //quantidade de chaves armazenadas no nó
    struct No *pai;
    int *s; //array de chaves
    struct No **p; //ponteiro para array de ponteiros para os filhos
} TNo;

typedef struct lista{
    int info;
    struct lista *prox;
} TLista;

TLista* insere_ordenado(TLista* li, int i);
void imprime_lista(TLista *li);
TNo *cria(int d);
TNo *libera(TNo *a, int d);
void imprime_arvore(TNo *a, int nivel);
void imprime_no(TNo *a);
int posicao(int chave, TNo *no);
TNo *busca(TNo *no, int chave);
void particiona(TNo *P, int d, int pos, int chave, TNo *pt);
void insere(TNo *no, int d, int pos, int chave, TNo *pt);
TNo *insere_folha(TNo *raiz, int d, int chave);
TLista *menor_k(TNo *raiz, int k);


#endif //ARVORE_B_ARVORE_B_H
