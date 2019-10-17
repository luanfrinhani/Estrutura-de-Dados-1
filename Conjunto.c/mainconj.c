#include "conjunto.h"
int main (){
    tCon *A=NULL,*B=NULL,*novo=NULL,*S=NULL;
    int op=-1,num,v;
    while(op!=0){
        printf("\n\n==============MENU==============\
               \n1 - Inserir valor no conjunto A\n2 - Inserir valor no conjunto B\n3 - Remover no conjunto A\n4 - Remover no conjunto B\
               \n5 - Verificar conjunto A vazio\n6 - Verificar conjunto B vazio\n7 - Cardinalidade conjunto A\n8 - Cardinalidade conjunto B\
               \n9 - Verificar valor em A\n10 - Verificar valor em B\n11 - Imprimir A\n12 - Imprimir B\n13 - Verificar A subconjunto de B\
               \n14 - Verificar B subconjunto de A\n15 - Diferenca de A em B\n16 - Diferenca de B em A\n17 - Verifica igual\n18 - Uniao\
               \n19 - Intersecao\n20 - Imprimir S\n21 - Resetar conjuntos\n0 - Sair\n");
        scanf("%d",&op);
        switch(op){
        case(1):
            printf("Entre com o valor para inserir no conjunto A: ");
            scanf("%d",&num);
            novo=criaNo(num);
            A=insere(A,novo);
            imprime(A);
            break;
        case(2):
            printf("Entre com o valor para inserir no conjunto B: ");
            scanf("%d",&num);
            novo=criaNo(num);
            B=insere(B,novo);
            imprime(B);
            break;
        case(3):
            printf("Entre com o numero para remover do conjunto A: ");
            scanf("%d",&num);
            A=removeConj(A,num);
            imprime(A);
            break;
        case(4):
            printf("Entre com o numero para remover do conjunto B: ");
            scanf("%d",&num);
            B=removeConj(B,num);
            imprime(B);
            break;
        case(5):
            v=verificaVazio(A);
            break;
        case(6):
            v=verificaVazio(B);
            break;
        case(7):
            v=cardinalidade(A);
            break;
        case(8):
            v=cardinalidade(B);
            break;
        case(9):
            printf("Entre com o valor: ");
            scanf("%d",&num);
            v=verificaNum(A,num);
            break;
        case(10):
            printf("Entre com o valor: ");
            scanf("%d",&num);
            v=verificaNum(B,num);
            break;
        case(11):
            imprime(A);
            break;
        case(12):
            imprime(B);
            break;
        case(13):
            v=subConj(A,B);
            break;
        case(14):
            v=subConj(B,A);
            break;
        case(15):
            S=diferenca(A,B);
            imprime(S);
            break;
        case(16):
            S=diferenca(B,A);
            imprime(S);
            break;
        case(17):
            verifica(A,B);
            break;
        case(18):
            S=uniao(A,B);
            imprime(S);
            break;
        case(19):
            S=intersecao(A,B);
            imprime(S);
            break;
        case(20):
            imprime(S);
            break;
        case(21):
            A=NULL;
            B=NULL;
            printf("\n\n==============MENU==============\
               \n1 - Inserir valor no conjunto A\n2 - Inserir valor no conjunto B\n3 - Remover no conjunto A\n4 - Remover no conjunto B\
               \n5 - Verificar conjunto A vazio\n6 - Verificar conjunto B vazio\n7 - Cardinalidade conjunto A\n8 - Cardinalidade conjunto B\
               \n9 - Verificar valor em A\n10 - Verificar valor em B\n11 - Imprimir A\n12 - Imprimir B\n13 - Verificar A subconjunto de B\
               \n14 - Verificar B subconjunto de A\n15 - Diferenca de A em B\n16 - Diferenca de B em A\n17 - Verifica igual\n18 - Uniao\
               \n19 - Intersecao\n20 - Resetar conjuntos\n0 - Sair\n");
            scanf("%d",&op);}}}
