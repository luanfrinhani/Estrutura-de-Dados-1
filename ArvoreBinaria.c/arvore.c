//#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct no{
	int info;
	struct no *dir,*esq;
} tno;
tno* criaNo(int info){
	tno *novo=(tno*)malloc(sizeof(tno));
	novo->info=info;
	novo->dir=NULL;
	novo->esq=NULL;
	return novo;
}
void imprime(tno *T,int nivel){
	int i;
	if (T!=NULL){
		imprime(T->dir,nivel+1);
		for (i=0;i<nivel;i++) {
			printf("\t");
		}
		printf("%d\n",T->info);
		imprime(T->esq,nivel+1);
	}
}
tno* busca(tno *T, int info, tno **paiaux){
	if (T==NULL) {
		return NULL;
	}
	if (T->info==info) {
		return T;
	}
	if (T->info>info){
		(*paiaux)=T;	
		return busca(T->esq,info,paiaux);
	}
	else{
		(*paiaux)=T;	
		return busca(T->dir,info,paiaux);
	}
}
tno* insere(tno *T, tno *novo){
	tno *aux=T,*ant=NULL;	
	if (T==NULL) return novo;
	while(aux!=NULL){ 
		if (aux->info==novo->info) {
			printf("Ja existe esse valor\n");			
			return T;
		}
		if ((aux->info)<(novo->info)){
			ant=aux;
			aux=aux->dir;
			if (aux==NULL){
				ant->dir=novo;
				break;
			}
		}
		if ((aux->info)>(novo->info)){
			ant=aux;
			aux=aux->esq;
			if (aux==NULL){
				ant->esq=novo;
				break;
			}
		}
	}
	return T;
}
tno* Sucessor(tno *x, tno **pai){
	tno *aux=x->dir;
	(*pai)=x;
	if(aux==NULL) {
		return aux;
	}
	else{
		while(aux->esq!=NULL){
			(*pai)=aux;
			aux=aux->esq;
		}
	}
	return aux;
}
int altura(tno *T){
	int e=0,d=0;
    	if (T==NULL) {
    		return -1;
    	}
    	e=altura(T->esq);
    	d=altura(T->dir);
    	if (e>d) {
    		return e+1;
    	}
    	else {
    		return d+1;
    	}
}
tno* removeArvore(tno *T, tno **paiaux,tno **paisuce, int info){	
	tno *aux=busca(T,info,paiaux);	
	if (aux==NULL) {
		return T;
	}
	tno *suc=Sucessor(aux,paisuce);	
	if (suc==NULL){
		if (T==aux){
			T=aux->esq;
			free(aux);
			return T;
		}
		if ((*paiaux)->esq==aux){
			(*paiaux)->esq=aux->esq;
			free(aux);
			return T;
		}
		if ((*paiaux)->dir==aux){
			(*paiaux)->dir=aux->esq;
			free(aux);
			return T;
		}
	}
	if ((*paisuce)==aux){
		aux->info=suc->info;
		(*paisuce)->dir=suc->dir;
		free(suc);
		return T;
	}
	if ((*paisuce)!=aux){	
		aux->info=suc->info;
		(*paisuce)->esq=suc->dir;
		free(suc);
		return T;
	}
}
//#include "arvore.h"
int main(){
	int op=-1, info=0, nivel=0,h;
	tno *T=NULL, *novo=NULL, *chave=NULL, *paiaux=NULL, *paisuce=NULL, *aux=NULL;
	while(op!=0){
		printf("\n==============MENU==============\
			\n1 - Insere na arvore\n2 - Busca chave\n3 - Remove\n4 - Altura de um no\n5 - Imprimir arvore\n0 - Sair\n");
		scanf("%d",&op);
		switch(op){
			case(1):
				printf("Entre com a chave: ");
				scanf("%d",&info);
				novo=criaNo(info);
				T=insere(T,novo);
				imprime(T,nivel);
				break;
			case(2):
				printf("Entre com a chave: ");
				scanf("%d",&info);
				chave=busca(T,info,&paiaux);
				printf("%d",chave->info);
				break;
			case(3):
				printf("Entre com a chave: ");
				scanf("%d",&info);
				T=removeArvore(T,&paiaux,&paisuce,info);
				imprime(T,nivel);
				break;
			case(4):
				printf("Entre com o valor: ");				
				scanf("%d",&info);
				chave=busca(T,info,&paiaux);			
				h=altura(chave);
				printf("A altura e: %d\n",h);
				break;
			case(5):
				imprime(T,nivel);
				break;
		}
	}
}