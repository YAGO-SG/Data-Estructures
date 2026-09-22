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

int calcTam(TGrafo * g) {
    return 0;
}

int calcTam(TGrafo * g) {
    int quant = 0;
    while(g != NULL) {
        quant++;
        g = g->prox;
    }

    return quant;
}

int * num_vizinhos(TGrafo * g) {
    int TAM = calcTam(g);
    int * vetor = (int*) malloc(TAM * sizeof(int));
    int pos = 0;
    while(g != NULL) {
        TVizinho * auxviz = g->prim_vizinho;
        int quant = 0;
        while(auxviz != NULL) {
            quant++;
            auxviz = auxviz->prox;
        }
        vetor[pos] = quant;
        pos++;
        g = g->prox;
    }

    return vetor;
}