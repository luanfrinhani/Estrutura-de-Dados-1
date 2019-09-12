/*arvore.h
Observacoes: Criacao de arvore binaria de busca, remocao, insercao, busca e altura de um no, utilizando o tipo inteiro*/	

	#ifndef _ARVORE_H
	#define _ARVORE_H
	#include <stdio.h>
	#include <stdlib.h>
/*Estrutura utilizada no programa*/
typedef struct no{
	int info;
	struct no *dir,*esq;
} tno;

/*Nome: criaNo Objetivo: recebe o valor como parametro, cria um no da arvore e o retorna*/

tno* criaNo(int info);

/*Nome: imprime Objetivo: recebe como parametro a arvore, e o nivel, imprime os nos da arvore*/

void imprime(tno *T,int nivel);

/*Nome: busca Objetivo: recebe a arvore  e o valor a ser buscado, retorna o no e altera a variavel paiaux*/

tno* busca(tno *T, int info, tno **paiaux);

/*Nome: insere Objetivo: recebe a arvore e o novo no, insere o no e retorna a arvore com o no inserido*/

tno* insere(tno *T, tno *novo);

/*Nome: Sucessor Objetivo: recebe a arvore e o endereco da variavel pai, encontra seu sucessor e seu pai e retorna o sucessor*/

tno* Sucessor(tno *T, tno **pai);

/*Nome: removeArvore Objetivo: recebe a arvore, o endereco de paiaux, paisuc e a chave, remove a chave e retorna a arvore*/

tno* removeArvore(tno *T, tno **paiaux, tno **paisuc, int ch);

/*Nome: altura Objetivo: recebe o no e retorna a sua altura*/

int altura(tno *T);




	#endif
