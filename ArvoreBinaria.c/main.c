#include "arvore.h"
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