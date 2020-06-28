#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fResp, *fGab, *fResult, *fResultFormat;
    int ra;
    int comp = 0;
    char resp[101] = "";
    char gab[101];
    char * respostas = "./resources/respostas.txt";
    char * gabarito = "./resources/gabarito.txt";
    char * resultado = "./resources/resultado.txt";
    char * resultadoFormatado = "./resources/resultadoFormatado.txt";

    fResp = fopen(respostas, "r");
    fGab = fopen(gabarito, "r");
    fResult = fopen(resultado, "w");
    fResultFormat = fopen(resultadoFormatado, "w");

    fgets(gab, 100, fGab);

    while (fgets(resp, 1000, fResp) != NULL){
        char * token = strtok(resp, " ");
       int index = 0;
        while( token != NULL ) {
            if(index == 0){
                fprintf(fResultFormat, "Ra: %s \n", token );
                fputs(token, fResult);
            }else {
                fprintf(fResultFormat, "Resposta: %s \n", token );
                for(int i = 0; i < strlen(token); i++){
                    if(gab[i] == token[i]){
                        comp++;
                    }
                }
                char res[50];
                snprintf(res, 50, "  %d", comp);
                fprintf(fResultFormat, "Resultado: %d \n\n", comp);
                fputs(res, fResult);
                comp = 0;
                fputs("\n", fResult);
            }
            token = strtok(NULL, "\n");
            index++;
        }
    }

    fclose(fResp);
    fclose(fGab);
    fclose(fResult);

    return 0;
}
