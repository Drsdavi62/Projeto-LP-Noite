#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fResp, *fGab, *fResult;
    char ra;
    char resp[101];
    char gab[101];
    char * respostas = "./resources/respostas.txt";
    char * gabarito = "./resources/gabarito.txt";
    char * resultado = "./resources/resultado.txt";

    fResp = fopen(respostas, "r");
    fGab = fopen(gabarito, "r");
    fResult = fopen(resultado, "w");

    while (fgets(resp, 1000, fResp) != NULL){
        char aux[256];
        printf("%s \n", strncpy(aux, resp, 100));
//        while (c < length) {
//            sub[c] = string[position+c-1];
//            c++;
//        }
    }
    return 0;
}
