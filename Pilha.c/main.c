#include "pilha.h"
int main(){
    int ch,op=-1;
    tpi *P=NULL,*novo=NULL,verificar;
    while(op!=0){
        printf("============MENU============\
        \n1 - Criar pilha\n2 - Empilhar\n3 - Desempilhar\n4 - Verificar Vazia\n5 - Imprimir\n0 - Sair\n");
        scanf("%d",&op);
        switch(op){
       		case(1):
        		printf("Entre com a chave: ");
        		scanf("%d",&ch)
        		novo=criaPilha(novo);
        		break;
        	case(2):
        		printf("Entre com a chave: ");
        		scanf("%d",&ch);
        		P=empilha(P,novo);
        		break;
        	case(3):
        		ch=desempilha(P);
        		break;
       		case(4):
        		verificar=verificaVazia(P);
        		break;
        	case(5):
        		imprime(P);
        		break;
        }
    }
}
