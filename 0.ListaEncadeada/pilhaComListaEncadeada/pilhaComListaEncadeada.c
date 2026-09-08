#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

TLista * implementaNo(TLista * li, int valor) {
    TLista * novo = (TLista*) malloc(sizeof(TLista));
    novo->info = valor;
    novo->prox = li;
    li = novo;

    return li;
}

TLista * excluiNo(TLista * li) {
    TLista * temp = li;
    li = li->prox;
    free(temp);

    return li;
}

void imprime_lista(TLista *li) {
    TLista* p;
    for (p = li; p != NULL; p = p->prox)
        printf("%d ", p->info);
}

TLista* insere_fim (TLista* li, int i) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;
    TLista* p = li;
    TLista* q = li;
    while (p != NULL) {
        /* encontra o ultimo elemento */
        q = p;
        p = p->prox;
    }
    if (q != NULL) /* se a lista original não estiver vazia */
        q->prox = novo;
    else
        li = novo;
    return li;
}

int main (void) {
    /* A função main lê os dados de entrada, cria a lista e chama a função altera
     * depois imprime a lista resultante
     * Ela NÃO DEVE SER MODIFICADA
     * */
    TLista* lista = NULL;
    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int valor;


    /* lê valores para criar a lista
     * valores devem ser informados separados por traço
     * exemplo: 1-3-5-2-7-9-21-6 */
    scanf("%s", l);
    //quebra a string de entrada
    ptr = strtok(l, delimitador);
    while(ptr != NULL) {
        valor = atoi(ptr);
        lista = insere_fim(lista, valor);
        ptr = strtok(NULL, delimitador);
    }

    while(true) {
        printf("deseja implementar(1) ou excluir(0) um nó da lista ou finalizar(2) programa? \n");
        scanf(" %d", &valor);

        if(valor == 1) {
            printf("digite o valor a ser implementado \n");
            int novo;
            scanf("%d", &novo);
            lista = implementaNo(lista, novo);
            imprime_lista(lista);
        } else if(valor == 0) {
            lista = excluiNo(lista);
        } else if(valor == 2) {
            break;
        } else {
            printf("valor invalido");
        }
    }

    imprime_lista(lista);
}