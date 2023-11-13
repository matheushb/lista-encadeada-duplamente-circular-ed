#include "lista.h"
#include "produto.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE_NAME 50

int main(void) {
  int option;
  setlocale(LC_ALL, "Portuguese");

  Lista *lista = malloc(sizeof(Lista));
  char *nome = malloc(sizeof(char) * MAX_SIZE_NAME);
  double valor;
  int codigo = 0;
  int cod = 0;

  create(lista);

  Produto *produto = createProduto(&cod, "Banana", 5.0);
  Produto *produto2 = createProduto(&cod, "Cebola", 20.0);
  Produto *produto3 = createProduto(&cod, "Carne", 17.0);
  Produto *produto4 = createProduto(&cod, "Frango", 8.0);
  Produto *produto5 = createProduto(&cod, "Caviar", 7.0);

  insertByName(lista, produto);
  insertByName(lista, produto2);
  insertByName(lista, produto3);
  insertByName(lista, produto4);
  insertByName(lista, produto5);

  do {
    system("clear");
    printf("O que deseja fazer?\n1 - Cadastrar Produto\n2 - Consultar "
           "Produtos\n3 - Consultar Produtos Reverso\n4 - Consultar Produto "
           "por codigo\n5 - Excluir Produto\n0 - Sair\n");
    scanf("%d", &option);
    getchar();
    switch (option) {
    case 1:
      system("clear");

      printf("Cadastro de Produto\nNome: ");
      fgets(nome, MAX_SIZE_NAME, stdin);
      nome[strcspn(nome, "\n")] = '\0';
      printf("Valor: ");
      scanf("%lf", &valor);

      Produto *produtoNovo = createProduto(&cod, nome, valor);
      insertByName(lista, produtoNovo);
      getchar();
      break;
    case 2:
      system("clear");
      print(*lista);
      printf("\nPressione ENTER para continuar.");
      getchar();

      break;
    case 3:
      system("clear");
      printReverse(*lista);
      getchar();
      break;
    case 4:
      system("clear");
      printf("Digite o código que deseja procurar:");
      scanf("%d", &codigo);
      getchar();
      Produto *produtoFind = find(lista, codigo);
      system("clear");
      if (produtoFind == NULL) {
        printf("\nProduto não encontrado com codigo: %d\n", codigo);
      } else {
        printProduto(produtoFind);
      }
      printf("\nPressione ENTER para continuar.");
      getchar();
      break;
    case 5:
      system("clear");
      print(*lista);
      printf("\nDigite o código que deseja excluir:");
      scanf("%d", &codigo);
      getchar();
      Produto *produtoRemovido = removeProduct(lista, codigo);
      system("clear");
      if (!produtoRemovido) {
        printf("\nProduto não encontrado com codigo: %d\n", codigo);
      } else {
        printf("\nProduto excluido: \n");
        printProduto(produtoRemovido);
      }
      printf("\nPressione ENTER para continuar.");
      getchar();
      break;
    default:
      system("clear");

      if (option != 0) {
        printf("Opcao %d não existe\nPressione ENTER para continuar.", option);
        getchar();
      }
    }

  } while (option != 0);
  printf("\nSistema finalizado.\n");

  return 0;
}