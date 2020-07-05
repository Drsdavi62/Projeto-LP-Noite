#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int results[], int ra[], int n);
void swap(int *xp, int *yp);

FILE *fResultFormat;
FILE *fResult;

int main()
{
    printf("Processando... \n");
    FILE *fResp, *fGab;
    int ra;
    int comp = 0;
    char resp[101] = "";
    char gab[101];
    char * respostas = "./resources/respostas.txt";
    char * gabarito = "./resources/gabarito.txt";
    char * resultado = "./resources/resultado.txt";
    char * resultadoFormatado = "./resources/resultadoFormatado.txt";
    int raArray[50] = {0};
    int respArray[50] = {0};
    fResp = fopen(respostas, "r");
    fGab = fopen(gabarito, "r");
    fResult = fopen(resultado, "w");
    fResultFormat = fopen(resultadoFormatado, "w");

    fgets(gab, 100, fGab);

    int i = 0;

    while (fgets(resp, 1000, fResp) != NULL){
        char * token = strtok(resp, " ");
       int index = 0;
        while( token != NULL ) {
            if(index == 0){
                raArray[i] = atoi(token);
            }else {
                for(int i = 0; i < strlen(token); i++){
                    if(gab[i] == token[i]){
                        comp++;
                    }
                }
                respArray[i] = comp;
                comp = 0;
            }
            token = strtok(NULL, "\n");
            index++;
        }
        i++;
    }

    bubbleSort(respArray, raArray, i);
    fclose(fResp);
    fclose(fGab);
    fclose(fResult);

    printf("Procesimento realizado com sucesso. \n");
    printf("Verifique os resultados em %s", resultadoFormatado);

    return 0;
}

void bubbleSort(int results[], int ra[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (results[j] < results[j+1]){
                swap(&results[j], &results[j+1]);
                swap(&ra[j], &ra[j + 1]);
            }
        }
    }
     for (int c = 0; c < n; c++){
        fprintf(fResult, "%d %d\n", ra[c], results[c]);
        fprintf(fResultFormat, "RA: %d - Resultado: %d\n", ra[c], results[c]);
     }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
