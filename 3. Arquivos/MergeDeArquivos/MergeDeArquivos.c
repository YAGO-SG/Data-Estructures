#include <stdio.h>

void merge(char *nomeArq1, char *nomeArq2, char *nomeArqMerge) {
    FILE * f1 = fopen(nomeArq1, "r");
    FILE * f2 = fopen(nomeArq2, "r");
    FILE * r = fopen(nomeArqMerge, "w");

    if(!f1 || !f2 || !r) {
        if(f1) fclose(f1);
        if(f2) fclose(f2);
        if(r) fclose(r);
        return ;
    }

    int a, b;
    int status1 = fscanf(f1, "%d", &a);
    int status2 = fscanf(f2, "%d", &b);

    while(status1 != EOF || status2 != EOF) {
        if(status1 == EOF) {

            fprintf(r, "%d\n", b);
            status2 = fscanf(f2, "%d", &b);
            continue;
        } else if(status2 == EOF) {

            fprintf(r, "%d\n", a);
            status1 = fscanf(f1, "%d", &a);
            continue;
        } 

        if(a == b) {
            fprintf(r, "%d\n", a);
            status2 = fscanf(f2, "%d", &b); 
            status1 = fscanf(f1, "%d", &a);
        } else if(a > b) {
            fprintf(r, "%d\n", b);
            status2 = fscanf(f2, "%d", &b);
        } else if(b > a) {
            fprintf(r, "%d\n", a); 
            status1 = fscanf(f1, "%d", &a);
        }
    }

    fclose(f1);
    fclose(f2);
    fclose(r);
}

int main() {
    char arq1[20] = "Num1.txt";
    char arq2[20] = "Num2.txt";
    char resMerge[20] = "NumResultado.txt";

    merge(arq1, arq2, resMerge);

    return 0;
}