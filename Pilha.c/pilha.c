#include "pilha.h"
*tpi criaNo(int ch){
    tpi *novo=(tpi*)malloc(sizeof(tpi));
    novo->ch=ch;
    return novo;
}
*tpi empilhar(tpi *P,tpi *novo){
    if (P==NULL) return novo;
    novo->prox=P;
    return novo;
}
int desempilhar(tpi *P){
    tpi *aux=P;
    int ch;
    if (P==NULL) {
        return P;
    }
    P=aux->prox;
    aux->prox=NULL;
    ch=aux->ch;
    return ch;
}
int verificaVazia(tpi *P){
    if (P==NULL) {
        return 1;
    }
    return 0;
}
void imprimir(tpi *P){
    tpi *aux=P;
    while(aux!=NULL){
        printf("%d\t",P->ch);
        aux=aux->prox;
    }
}
