#ifndef LISTA
#define LISTA
#include "produto.h"

typedef struct no {
  struct no *proximo;
  struct no *anterior;
  Produto *produto;
} No;

typedef struct {
  No *inicio;
  No *fim;
  int tamanho;
} Lista;


void insertByName(Lista *lista, Produto *produto);
void insert(Lista *lista, Produto *produto);
void create(Lista *lista);
void print(Lista lista);
void printReverse(Lista lista);
Produto *removeProduct(Lista *lista, int cod);
Produto* find(Lista *lista, int cod);

#endif