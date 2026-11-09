#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define TAM_NOME 100

typedef struct Departamento {
    int cod_dept;
    int sala;
    char nome[TAM_NOME];
} TDepartamento;

typedef struct Funcionario {
    int cod_func;
    int cod_dept;
    char nome[TAM_NOME];
} TFuncionario;

void salva_join(TDepartamento * dept ,TFuncionario * func, FILE * out) {
    fprintf(out, "%d", dept->cod_dept);
    fprintf(out, "%c", ';');
    fprintf(out, "%d", dept->sala);
    fprintf(out, "%c", ';');
    fprintf(out, "%s", dept->nome);
    fprintf(out, "%c", ';');
    fprintf(out, "%d", func->cod_func);
    fprintf(out, "%c", ';');
    fprintf(out, "%s", func->nome);
    fprintf(out, "%c", ';');
    fprintf(out, "%s", "\n");
}

TFuncionario *le_funcionario(FILE *in)
{
    TFuncionario *func = (TFuncionario *) malloc(sizeof(TFuncionario));
    char linha[150];
    if (fgets (linha, 150, in) == NULL ) {
        free(func);
        return NULL;
    }

    char delimitador[] = ";";
    char *ptr;
    int cod;

    //quebra a linha
    ptr = strtok(linha, delimitador);
    cod = atoi(ptr);
    func->cod_func = cod;
    ptr = strtok(NULL, delimitador);
    cod = atoi(ptr);
    func->cod_dept = cod;
    ptr = strtok(NULL, delimitador);
    strcpy(func->nome, ptr);

    return func;
}

TDepartamento *le_departamento(FILE *in)
{
    TDepartamento *dept = (TDepartamento *) malloc(sizeof(TDepartamento));
    char linha[150];
    if (fgets (linha, 150, in) == NULL ) {
        free(dept);
        return NULL;
    }

    char delimitador[] = ";";
    char *ptr;
    int cod, sala;

    //quebra a linha
    ptr = strtok(linha, delimitador);
    cod = atoi(ptr);
    dept->cod_dept = cod;
    ptr = strtok(NULL, delimitador);
    sala = atoi(ptr);
    dept->sala = sala;
    ptr = strtok(NULL, delimitador);
    strcpy(dept->nome, ptr);

    return dept;
}

void imprime_arquivo(char *name) {
    FILE *arq; //declara ponteiro para arquivo
    // abre arquivo para leitura
    arq = fopen(name, "r");
    if (arq != NULL) {// checa se não deu erro na abertura do arquivo
        char linha[150];
        fgets (linha, 150, arq);
        while (!feof(arq)) {//testa se chegou ao final do arquivo
            printf("%s", linha);
            fgets (linha, 150, arq);
        }
        fclose(arq); //fecha arquivo
    } else printf("Erro ao abrir arquivo\n");
}

void leftOuterJoin(char *nome_arq_dept, char *nome_arq_funcionarios, char *nome_arq_join) {
    FILE * dept = fopen(nome_arq_dept, "r");
    FILE * func = fopen(nome_arq_funcionarios, "r");
    FILE * join = fopen(nome_arq_join, "w");

    if(!dept || !func || !join) {
            printf("Erro na abertura de algum arquivo texto\n");
            if(dept) fclose(dept);
            if(func) fclose(func);
            if(join) fclose(join);
            return;
    }

    TDepartamento * deptStr = le_departamento(dept);
    int codDeptMinimo = deptStr->cod_dept;

    while (deptStr) {
            deptStr = le_departamento(dept);
            if(!deptStr) break;
            if(codDeptMinimo > deptStr->cod_dept){
                codDeptMinimo = deptStr->cod_dept;
            }
    }
    rewind(dept);
    deptStr = le_departamento(dept);

    while(deptStr) {
            if(deptStr->cod_dept != codDeptMinimo) {
                deptStr = le_departamento(dept);
                continue;
            }
            TFuncionario * funcStr = le_funcionario(func);
            int funcionariosJoin = 0;

            while (funcStr) {
                if(funcStr->cod_dept == deptStr->cod_dept) {
                    salva_join(deptStr, funcStr, join);
                    funcionariosJoin++;
                } 
                free(funcStr);
                funcStr = le_funcionario(func);
            }
            if(funcionariosJoin == 0){
                fprintf(join, "%d", deptStr->cod_dept);
                fprintf(join, "%c", ';');
                fprintf(join, "%d", deptStr->sala);
                fprintf(join, "%c", ';');
                fprintf(join, "%s", deptStr->nome);
                fprintf(join, "%c", ';');
                fprintf(join, "%d", 0);
                fprintf(join, "%c", ';');
                fprintf(join, "%c", ';');
                fprintf(join, "%s", "\n");
            }
            rewind(func);
            rewind(dept);
            free(deptStr);
            deptStr = le_departamento(dept);
            codDeptMinimo++;
    }

    fclose(dept);
    fclose(func);
    fclose(join);
}

int main() {
    leftOuterJoin("departamentos.txt", "funcionarios.txt", "join.txt");
    imprime_arquivo("join.txt");
}