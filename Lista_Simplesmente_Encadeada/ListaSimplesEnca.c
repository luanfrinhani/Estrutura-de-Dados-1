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
int main (){
    int ch,op = -1;
    tNo *L1 = NULL,*L2 = NULL,*L3 = NULL,*novo = NULL;
    while(op!=0){
        printf("\n=============MENU=============\
               \n1 - Insere inicio lista 1\n2 - Insere final lista 1\n3 - Ocorrencia da chave lista 1\n4 - Multiplica por 10 lista 1\n5 - Verificar ordedada lista 1\n6 - Imprimir lista 1\
               \n7 - Insere inicio lista 2\n8 - Insere final lista 2\n9 - Ocorrencia lista 2\n10 - Multiplica lista 2\n11 - Verifica lista 2\
               \n12 - Imprime lista 2\n13 - Insere lista ordenada\nOpcao: ");
        scanf("%d",&op);
    switch(op){
        case(1):
            printf("Entre com a chave: ");
            scanf("%d",&ch);
            novo = criaNo(ch);
            L1 = insereInicio(L1,novo);
            break;
        case(2):
            printf("Entre com a chave: ");
            scanf("%d",&ch);
            novo = criaNo(ch);
            L1 = insereFinal(L1,novo);
            break;
        case(3):
            printf("Entre com a chave procurada: ");
            scanf("%d",&ch);
            ocorrencia(L1,ch);
            break;
        case(4):
            multiplica(L1);
            break;
        case(5):
            ordenada(L1);
            break;
        case(6):
            imprimeLista(L1);
            break;
        case(7):
            printf("Entre com a chave: ");
            scanf("%d",&ch);
            novo = criaNo(ch);
            L2 = insereInicio(L2,novo);
            break;
        case(8):
            printf("Entre com a chave: ");
            scanf("%d",&ch);
            novo = criaNo(ch);
            L2 = insereFinal(L2,novo);
            break;
        case(9):
            printf("Entre com a chave procurada: ");
            scanf("%d",&ch);
            ocorrencia(L2,ch);
            break;
        case(10):
            multiplica(L2);
            break;
        case(11):
            ordenada(L2);
            break;
        case(12):
            imprimeLista(L2);
            break;
        case(13):
            L3 = insereOrdenadolistas(L1,L2);
            break;
        }
    }
}
