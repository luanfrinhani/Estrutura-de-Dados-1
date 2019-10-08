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
