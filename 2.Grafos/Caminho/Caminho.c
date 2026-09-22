#include <stdio.h>
#include <stdlib.h>

typedef struct TVizinho {
    int VizinhoId;
    struct TVizinho * prox;
}TVizinho;

typedef struct TGrafo {
    int chave;
    TVizinho * prim_vizinho;
    struct TGrafo * prox;
}TGrafo;

typedef struct Tlista {
    int chave;
    struct Tlista * prox;
}TLista;

int temVizinho(TGrafo * g, int a) {
    TVizinho * auxviz = g->prim_vizinho;
    while(auxviz != NULL) {
        if(auxviz->VizinhoId == a) {
            return 1;
        } else {
            auxviz = auxviz->prox;
        }
    }
    return 0;
}

int caminho(TGrafo * g, TLista * c) {
    TLista * next = c->prox;
    while(next != NULL) {
        TGrafo * aux = g;
        while(aux != NULL) {
            if(c->chave == aux->chave) {
                break;
            } else {
                aux = aux->prox;
            }
        }
        if(!aux) return 0;
        int verifica = temVizinho(aux, next->chave);
        if(!verifica) return 0;
        c = next;
        next = next->prox;
    }

    return 1;
}