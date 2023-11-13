#ifndef PRODUTO
#define PRODUTO

typedef struct {
  char nome[50];
  int codigo;
  float valor;
} Produto;

Produto *createProduto(int *cod, char *nome, float valor);

void printProduto(Produto *produto);

#endif