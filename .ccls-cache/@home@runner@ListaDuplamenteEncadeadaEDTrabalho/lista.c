#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create(Lista *lista) {
  lista->inicio = NULL;
  lista->fim = NULL;
  lista->tamanho = 0;
}

void insertByName(Lista *lista, Produto *produto) {
  No *novo = malloc(sizeof(No));
  if (novo == NULL) {
    printf("Erro ao alocar memória!\n");
    return;
  }
  novo->produto = produto;
  novo->anterior = NULL;
  novo->proximo = NULL;

  if (lista->inicio == NULL) {
    lista->inicio = novo;
    lista->fim = novo;
  } else {
    No *aux = lista->inicio;
    while (aux != NULL && strcmp(novo->produto->nome, aux->produto->nome) > 0) {
      aux = aux->proximo;
    }

    if (aux == NULL) {
      novo->anterior = lista->fim;
      lista->fim->proximo = novo;
      lista->fim = novo;
    } else if (aux->anterior == NULL) {
      novo->proximo = aux;
      aux->anterior = novo;
      lista->inicio = novo;
    } else {
      novo->anterior = aux->anterior;
      novo->proximo = aux;
      aux->anterior->proximo = novo;
      aux->anterior = novo;
    }
  }
  lista->tamanho++;
}

void insert(Lista *lista, Produto *produto) {
  No *novo = malloc(sizeof(No));

  if (novo) {
    novo->produto = produto;
    novo->anterior = NULL;
    novo->proximo = NULL;
    if (lista->inicio == NULL) {
      lista->inicio = novo;
      lista->fim = novo;
      lista->inicio->anterior = novo;
      lista->fim->proximo = novo;
    } else {
      novo->anterior = lista->fim;
      lista->fim->proximo = novo;
      lista->fim = novo;
      lista->fim->proximo = lista->inicio;
    }
    lista->tamanho++;

  } else {
    printf("Erro ao alocar memoria!\n");
  }
}

void print(Lista lista) {
  No *no = lista.inicio;
  printf("\nLista\n");

  for (int x = 0; x < lista.tamanho; x++) {
    printProduto(no->produto);
    no = no->proximo;
    printf("\n");
  }

  printf("\n");
  printf("Tamanho: %i\n", lista.tamanho);
}

void printReverse(Lista lista) {
  No *no = lista.fim;
  printf("\nListaReversa\n");

  for (int x = 0; x < lista.tamanho; x++) {
    printProduto(no->produto);
    no = no->anterior;
    printf("\n");
  }

  printf("\n");
  printf("Tamanho: %i\n", lista.tamanho);
}

Produto *removeProduct(Lista *lista, int cod) {
  if (!lista)
    return NULL;

  No *aux = lista->inicio;

  while (aux != NULL && aux->produto->codigo != cod) {
    aux = aux->proximo;
  }

  if (aux != NULL && aux->produto->codigo == cod) {
    if (aux == lista->inicio) {
      lista->inicio = aux->proximo;
      if (lista->inicio) {
        lista->inicio->anterior = lista->fim;
      }
    } else if (aux == lista->fim) {
      lista->fim = aux->anterior;
      if (lista->fim) {
        lista->fim->proximo = lista->inicio;
      }
    } else {
      aux->anterior->proximo = aux->proximo;
      aux->proximo->anterior = aux->anterior;
    }

    Produto *removido = aux->produto;

    free(aux);

    lista->tamanho--;

    if (lista->tamanho == 0) {
      lista = NULL;
    }

    return removido;
  }

  return NULL;
}

Produto *find(Lista *lista, int cod) {
  No *aux = lista->inicio;

  while (aux) {
    if (aux->produto->codigo == cod)
      return aux->produto;

    aux = aux->proximo;
  }

  return NULL;
}