#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int chave;
  char caractere;
} info;

typedef struct Elemento {
  info dados;
  struct Elemento *esq;
  struct Elemento *dir;
  int alt;
} elemento;

int altura(elemento *no) {
  int h = 0;
  if (no != NULL) {
    int alt_esq = altura(no->esq);
    int alt_dir = altura(no->dir);
    int max_alt = alt_esq > alt_dir ? alt_esq : alt_dir;
    h = 1 + max_alt;
  }
  return h;
}

elemento **criar() {
  elemento **novaArvore = (elemento **)malloc(sizeof(elemento *));
  if (novaArvore == NULL)
    *novaArvore = NULL;
  return novaArvore;
}

int fatorBalanceamento(elemento *no) {
  return labs(altura(no->esq) - altura(no->dir));
}

int maior(int a, int b) {
  if (a >= b)
    return a;
  else
    return b;
}

static void rotacao_simples_direita(elemento **raiz) {
  elemento *q = *raiz;
  elemento *p = q->esq;

  q->esq = p->dir;
  p->dir = q;

  q->alt = 1 + maior(altura(q->esq), altura(q->dir));
  p->alt = 1 + maior(altura(p->esq), q->alt);

  *raiz = p;
}

static void rotacao_simples_esquerda(elemento **raiz) {
  elemento *p = *raiz;
  elemento *q = p->dir;

  p->dir = q->esq;
  q->esq = p;

  p->alt = 1 + maior(altura(p->esq), altura(p->dir));
  q->alt = 1 + maior(altura(q->dir), p->alt);

  *raiz = q;
}

void insercao_arvore(elemento **raiz, info dados) {
  elemento *novo = (elemento *)malloc(sizeof(elemento));
  novo->dados = dados;
  novo->esq = NULL;
  novo->dir = NULL;
  novo->alt = 0;

  if (*raiz == NULL) {
    *raiz = novo;
    return;
  }

  elemento *atual = *raiz;
  elemento *antecessor = NULL;

  while (atual != NULL) {
    antecessor = atual;

    if (dados.chave < atual->dados.chave) {
      atual = atual->esq;
    } else {
      atual = atual->dir;
    }
  }

  if (dados.chave < antecessor->dados.chave) {
    antecessor->esq = novo;
  } else {
    antecessor->dir = novo;
  }
  while (antecessor != NULL) {
    antecessor->alt = 1 + maior(altura(antecessor->esq), altura(antecessor->dir));
    int fator_bal = fatorBalanceamento(antecessor);
    if (fator_bal < -1 && dados.chave < antecessor->esq->dados.chave) {
      rotacao_simples_direita(&antecessor);
      break;
    }
    if (fator_bal > 1 && dados.chave > antecessor->dir->dados.chave) {
      rotacao_simples_esquerda(&antecessor);
      break;
    }
    if (fator_bal > 1 && dados.chave < antecessor->dir->dados.chave) {
      rotacao_simples_direita(&(antecessor->dir));
      rotacao_simples_esquerda(&antecessor);
      break;
    }
    if (fator_bal < -1 && dados.chave > antecessor->esq->dados.chave) {
      rotacao_simples_esquerda(&(antecessor->esq));
      rotacao_simples_direita(&antecessor);
      break;
    }
    antecessor = (fator_bal > 1 && dados.chave < antecessor->dir->dados.chave) ? antecessor->dir : antecessor->esq;
  }
}

void pre_ordem(elemento *no) {
  if (no != NULL) {
    printf("%d ", no->dados.chave);
    pre_ordem(no->esq);
    pre_ordem(no->dir);
  }
}

void em_ordem(elemento *no) {
  if (no != NULL) {
    em_ordem(no->esq);
    printf("%d ", no->dados.chave);
    em_ordem(no->dir);
  }
}

void pos_ordem(elemento *no) {
  if (no != NULL) {
    pos_ordem(no->esq);
    pos_ordem(no->dir);
    printf("%d ", no->dados.chave);
  }
}

void main() {
  elemento **arvore = criar();

  info dados1 = {10, 'A'};
  insercao_arvore(arvore, dados1);

  info dados2 = {5, 'B'};
  insercao_arvore(arvore, dados2);

  info dados3 = {15, 'C'};
  insercao_arvore(arvore, dados3);

  info dados4 = {3, 'D'};
  insercao_arvore(arvore, dados4);

  info dados5 = {7, 'E'};
  insercao_arvore(arvore, dados5);

  info dados6 = {12, 'F'};
  insercao_arvore(arvore, dados6);

  info dados7 = {2, 'G'};
  insercao_arvore(arvore, dados7);
  pos_ordem(*arvore);
}