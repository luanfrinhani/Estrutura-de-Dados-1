    /* Nome: pilha.h
       Observacoes: Criacao e operacoes com pilhas utilizando estrutura de dados e lista simplesmente encadeada*/

   #ifndef _PILHA_H
   #define _PILHA_H
   #include <stdio.h>
   #include <stdlib.h>
/*Estrutura utilizada no programa*/
typedef struct pilha{
    int ch;
    struct pilha *prox;} tpi;
/*Nome: criaPilha Objetivo: Criar pilha para depois utiliza-las em operacoes, tem como parametro a chave e retorna um no pilha*/

*tpi criaNo(int ch);

/*Nome: empilha Objetivo: Tem como parametro a pilha e o novo no, retorna o inicio da pilha*/

*tpi empilha(tpi *P,tpi *novo);

/*Nome: desempilhar Objetivo: Tem como parametro a pilha, retorna o campo chave do no removido*/

int desempilhar(tpi *P);

/*Nome: verificaVazia Objetivo: Tem como parametro a pilha, e retorna true ou false*/

int verificaVazia(tpi *P);

/*Nome: imprime Objetivo: Recebe a pilha como parametro e imprime os valores dos nos*/

void imprimir(tpi *P);
   #endif
