#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Produto *createProduto(int *cod, char nome[], float valor) {
  *cod += 1;
  Produto *produto = malloc(sizeof(Produto));
  produto->codigo = *cod;
  strncpy(produto->nome, nome, sizeof(produto->nome) - 1);
  produto->nome[sizeof(produto->nome) - 1] = '\0';
  produto->valor = valor;
  return produto;
}

void printProduto(Produto *produto) {
  if (produto) {
    printf("codigo: %i | Nome: %s | valor: %.2f", produto->codigo,
           produto->nome, produto->valor);
  }
}
