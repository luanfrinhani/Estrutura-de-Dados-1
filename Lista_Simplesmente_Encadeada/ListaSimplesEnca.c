#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int ch;
    struct no *prox;
}tNo;
tNo* criaNo(int ch){
    tNo *novo=(tNo*)malloc(sizeof(tNo));
    novo->ch=ch;
    novo->prox=NULL;
    return novo;
}
tNo* insereInicio(tNo *L,tNo *novo){
    novo->prox = L;
    return novo;
}
void imprimeLista(tNo *L){
    tNo *aux = L;
    while(aux!=NULL){
        printf("%d\t",aux->ch);
        aux = aux->prox;
    }
}
tNo* insereFinal(tNo *L,tNo *novo){
    tNo *aux = L;
    while(aux!=NULL){
        if (aux->prox == NULL) {
            break;
        }
        aux = aux->prox;
    }
    if (aux == NULL) {
        return novo;
    }
    aux->prox = novo;
    return L;
}
void ocorrencia(tNo *L,int ch){
    tNo *aux = L;
    int cont = 0;
    while(aux!=NULL){
        if (aux->ch == ch){
            cont++;
        }
        aux = aux->prox;
    }
    printf("%d",cont);
}
void multiplica(tNo *L){
    tNo *aux = L;
    while(aux!=NULL){
        aux->ch = 10*(aux->ch);
        aux = aux->prox;
    }
}
void ordenada(tNo *L){
    tNo *ant = L;
    if (ant == NULL) {
        printf("Lista vazia");
    }
    tNo *aux = L->prox;
    int cont = 0;
    while(aux!=NULL){
        if (ant->ch>aux->ch){
            cont++;
        }
        ant = aux;
        aux = aux->prox;
    }
    if (cont!=0){
        printf("Nao ordenada");
    }
    else{
        printf("Lista ordenada");
    }
}
/*tNo* insereOrdenadolistas(tNo *L1,tNo *L2){
    tNo *aux1=L1,*aux2=L2,*L3=NULL,*ultimo=L3;
    while(aux1!=NULL && aux2!=NULL){}
        if (aux1<aux2){
            L1=L1->prox;
            aux1->prox=NULL;
            ultimo->prox=aux1;
            ultimo=ultimo->prox;
            aux1=L1;
        if (aux2<aux1){
            L2=L2->prox;
            aux2->prox=NULL;
            ultimo->prox=aux2;
            ultimo=ultimo->prox;
            aux2=L2;}}
    if (L1==NULL){
        ultimo->prox=L2;}
    if (L2==NULL){
        ultimo->prox=L1;}
    return L3;}*/
