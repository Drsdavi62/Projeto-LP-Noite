#include <stdio.h>
#include <stdlib.h>
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

void criarConta(){
	printf("Digite seu nome\n");
    scanf("%s", &pCliente.nome);
    fflush(stdin);
  	printf("Digite seu CPF\n");
  	scanf("%ld", &pCliente.cpf);

  	pConta.numero = 1234;
  	pConta.cliente = pCliente;
  	pConta.saldo = 0;

  	imprimirSaldo();
}

void depositar(float valor){
	if (valor > 0) {
    	pConta.saldo += valor;
  	  	printf("Seu saldo atual eh de R$%.2f\n", pConta.saldo);
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


