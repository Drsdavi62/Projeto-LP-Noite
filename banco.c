#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"

struct Cliente{
	char nome[265];
    long int cpf;
};

struct Conta{
	int numero;
  	struct Cliente cliente;
  	float saldo;
};
 FILE * fPtr;
void criarConta(){
	printf("Digite seu nome\n");
    gets(pCliente.nome);
    fflush(stdin);
  	printf("Digite seu CPF\n");
  	scanf("%ld", &pCliente.cpf);

  	pConta.numero = 1234;
  	pConta.cliente = pCliente;
  	pConta.saldo = 0;

    fPtr = fopen("resultado.txt", "w");
    if(fPtr == NULL)    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    char conteudo[100] = "Criar conta: ";
    strcat(conteudo, pCliente.nome);

    fputs(conteudo, fPtr);

  	imprimirSaldo();
}

void depositar(float valor){
	if (valor > 0) {
    	pConta.saldo += valor;
  	  	printf("Seu saldo atual eh de R$%.2f\n", pConta.saldo);

        char conteudo[100] = "\n\n--Deposito: R$";
        char num[50];
        snprintf(num, 50, "%.2f", valor);
        strcat(conteudo, num);
        fputs(conteudo, fPtr);
        escreverSaldo();
    } else {
        printf("O valor deve ser positivo\n");
    }
    system("pause");
    system("cls");

}

void saque(float valor){
	if(pConta.saldo >= valor){
        pConta.saldo -= valor;
        printf("Seu saldo atual eh de R$%.2f\n", pConta.saldo);

        char conteudo[100] = "\n\n--Saque: R$";
        char num[50];
        snprintf(num, 50, "%.2f", valor);
        strcat(conteudo, num);
        fputs(conteudo, fPtr);
        escreverSaldo();
    } else {
        printf("Voce nao tem saldo suficiente\n");
    }
    system("pause");
    system("cls");
}

void imprimirSaldo(){
	printf("\nConta %d\n", pConta.numero);
  	printf("Nome: %s\n", pConta.cliente.nome);
  	printf("CPF: %ld\n", pConta.cliente.cpf);
  	printf("Seu saldo eh de R$%.2f\n", pConta.saldo);
  	system("pause");
    system("cls");
}

void escreverSaldo(){
    char conteudo[100] = "\n--Saldo atual: R$";
    char num[50];
    snprintf(num, 50, "%.2f", pConta.saldo);
    strcat(conteudo, num);
    fputs(conteudo, fPtr);
    fflush(stdin);
}

