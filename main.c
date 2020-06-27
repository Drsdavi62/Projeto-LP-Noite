#include <stdio.h>
#include <stdlib.h>
#include "banco.c"

float entrada();

int main()
{

  int opc = 0;
  // iniciar();
  criarConta();
  do
  {
    printf("\nSelecione a opcao que deseja realizar\n\n");
    printf("\t 1 - Deposito\n");
    printf("\t 2 - Saque\n");
    printf("\t 3 - Ver saldo\n");
    printf("\t 4 - Sair\n");

    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
      depositar(entrada());
      break;
    case 2:
      saque(entrada());
      break;
    case 3:
      imprimirSaldo();
      break;
    case 4:
      fclose(fPtr);
      return 0;
    default:
      printf("Opcao invalida\n");
    }
  } while (opc != 4);
  return 0;
}

float entrada()
{
  float valor;
  printf("Digite o valor\n");
  scanf("%f", &valor);
  return valor;
}
