#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NOS 255
#define VAZIO INT_MIN //valor usado internamente para marcar os nos informados como * (subarvore vazia)

typedef struct sNoA {
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

int ehZigueZague(TNoA * arvore) {
    if(arvore->dir == NULL && arvore->esq == NULL) {
        return 1;
    }

    if(arvore->dir && arvore->esq) {
        return 0;
    }

    if(arvore->dir != NULL && arvore->esq == NULL) {
        ehZigueZague(arvore->dir);
    } else if(arvore->dir == NULL && arvore->esq != NULL) {
        ehZigueZague(arvore->esq);
    }
}


void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%d\n", nodo->chave);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

void imprimeProfundidade(TNoA *nodo, int altura) {
    altura = altura - 1;
    if (nodo != NULL) {
        printf("%d", nodo->chave);
        if (altura > 0) {
            printf("-");
            imprimeProfundidade(nodo->esq, altura);
            printf("-");
            imprimeProfundidade(nodo->dir, altura);
        }
    } else {
        printf("*");
        //Trata caso de subarvore NULL em nível menor que altura da árvore
        if (altura > 0) {
            printf("-");
            imprimeProfundidade(NULL, altura);
            printf("-");
            imprimeProfundidade(NULL, altura);
        }
    }
}

TNoA *criaArvore(int entrada[MAX_NOS], int tamanho) {
    int novaEntrada[MAX_NOS];
    int i, j;
    TNoA *novo;
    novo = NULL;
    if ((tamanho > 0) && (entrada[0] != VAZIO)) {
        novo = (TNoA *) malloc(sizeof(TNoA));
        novo->chave = entrada[0];
        tamanho = tamanho / 2;

        //divide a entrada em duas partes e chama a função criaArvore recursivamente
        i = 1; //inicio da subarvore esquerda no vetor entrada
        j = 0; //cursor do novo vetor de entrada que conterá apenas a subárvore desejada
        while (i <= tamanho) {
            novaEntrada[j] = entrada[i];
            i++;
            j++;
        }
        novo->esq = criaArvore(novaEntrada, tamanho);

        i = tamanho + 1; //inicio da subarvore direita no vetor entrada
        j = 0; //cursor do novo vetor de entrada que conterá apenas a subárvore desejada
        while (i <= tamanho * 2) {
            novaEntrada[j] = entrada[i];
            i++;
            j++;
        }
        novo->dir = criaArvore(novaEntrada, tamanho);
    }
    return novo;
}

int main(void) {

    /* A função main lê os dados de entrada, cria a árvore e chama a função solicitada no problema
     * depois imprime o resultado solicitado
     * ELA NÃO DEVE SER MODIFICADA
     * */
    TNoA *raiz;
    raiz = NULL;

    char l[1000];
    char delimitador[] = "-";
    char *ptr;
    int entrada[MAX_NOS];
    int tam;

    /* lê valores para criar a arvore, usando a notação do percurso em profundidade
     * de uma árvore cheia. Os valores devem ser informados separados por traço e
     * os nós vazios devem ser representados por *
     * exemplo: 400-300-150-*-200-*-*-*-*-*-*-*-*-*-* */
    scanf("%s", l);

    //quebra a string de entrada
    tam = 0;
    ptr = strtok(l, delimitador);
    while ((ptr != NULL) && (tam < MAX_NOS)) {
        if (ptr[0] == '*') {
            entrada[tam] = VAZIO;
        } else {
            entrada[tam] = atoi(ptr);
        }
        tam++;
        ptr = strtok(NULL, delimitador);
    }

    raiz = criaArvore(entrada, tam);

    //Chama função
    printf("%d \n", ehZigueZague(raiz));
};