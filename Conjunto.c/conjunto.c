tCon* criaNo(int num){
    tCon *novo=(tCon*)malloc(sizeof(tCon));
    novo->num=num;
    novo->prox=NULL;
    novo->ant=NULL;
    return novo;}
tCon* removeConj(tCon *A, int num){
    tCon *aux=A;
    if (A==NULL) return A;
    while(aux!=NULL && aux->num!=num) aux=aux->prox;
    if (aux->num==num){
        if (aux->prox==NULL && aux->ant==NULL){
            A=NULL;
            free(aux);
            return A;}
        if (aux->ant==NULL && aux->prox!=NULL){
            aux->prox->ant=NULL;
            A=aux->prox;
            aux->prox=NULL;
            aux->ant=NULL;
            free(aux);
            return A;}
        if (aux->prox==NULL && aux->ant!=NULL){
            aux->ant->prox=NULL;
            aux->ant=NULL;
            free(aux);
            return A;}
        aux->prox->ant=aux->ant;
        aux->ant->prox=aux->prox;
        aux->prox=NULL;
        aux->ant=NULL;
        free(aux);
        return A;}
        else{
            printf("Nao existe esse numero nesse conjunto");
            return A;}}
tCon* insere(tCon *A,tCon *novo){
    tCon *aux=A;
    if (A==NULL) return novo;
    while(aux!=NULL){
    if (aux->num==novo->num) return A;
    aux=aux->prox;}
    aux=A;
    aux->ant=novo;
    novo->prox=aux;
    return novo;}
int verificaVazio(tCon *A){
    if (A==NULL){
        printf("Conjunto vazio");
        return 0;}
    else {
        printf("Não vazio");
        return 1;}}
int cardinalidade(tCon *A){
    tCon *aux=A;
    int cont=0;
    while(aux!=NULL){
        aux=aux->prox;
        cont++;}
    printf("%d",cont);
    return cont;}
int verificaNum(tCon *A,int num){
    tCon *aux=A;
    while(aux!=NULL){
        if (aux->num==num){
          printf("Existe");
          return aux->num;}
        aux=aux->prox;}
    if (aux==NULL){
        printf("Nao pertence");
        return 0;}}
void imprime(tCon *A){
    tCon *aux=A;
    printf("\n");
    while (aux!=NULL){
        printf("%d\t",aux->num);
        aux=aux->prox;}}
int subConj(tCon *A1,tCon *A2){
    tCon *aux1=A1,*aux2=A2;
    int contA1=cardinalidade(A1),k=0;
    if (A1==NULL || A2==NULL){
        printf("\nNao e subconjunto");
        return 0;}
    while (aux1!=NULL){
        aux2=A2;
        while(aux2!=NULL){
            if (aux1->num==aux2->num){
                k++;
                break;}
            aux2=aux2->prox;}
        aux1=aux1->prox;}
    if (contA1==k)  printf("\nE subconjunto");
    else    printf("\nNao e subconjunto");}
tCon* diferenca(tCon *A1,tCon *A2){
    tCon *S=NULL,*novo=NULL,*aux1=A1,*aux2=A2;
    int x,cont=0;
    if (A1==NULL && A2==NULL) return S;
    if (A1==NULL) return S;
    if (A2==NULL) return A1;
    while(aux1!=NULL){
        aux2=A2;
        while(aux2!=NULL){
            if (aux1->num==aux2->num){
                cont++;
                break;}
            aux2=aux2->prox;}
        if (cont==0){
            x=aux1->num;
            novo=criaNo(x);
            S=insere(S,novo);}
        cont=0;
        aux1=aux1->prox;}
    return S;}
void verifica(tCon *A1,tCon *A2){
    tCon *aux1=A1,*aux2=A2;
    int card,cont=0;
    card=cardinalidade(A1);
    while(aux1!=NULL){
        aux2=A2;
        while(aux2!=NULL){
            if (aux1->num==aux2->num){
                cont++;
                break;}
            aux2=aux2->prox;}
        aux1=aux1->prox;}
    if (cont==card) printf("Sao iguais");
    else printf("Nao sao iguais");}
tCon* uniao(tCon *A1,tCon *A2){
    tCon *aux1=A1,*aux2=A2,*S=NULL,*novo=NULL;
    int x;
    if (A1==NULL && A2==NULL) return S;
    while(aux1!=NULL){
        x=aux1->num;
        novo=criaNo(x);
        S=insere(S,novo);
        aux1=aux1->prox;}
    while(aux2!=NULL){
        x=aux2->num;
        novo=criaNo(x);
        S=insere(S,novo);
        aux2=aux2->prox;}
    aux1=S;
    while(aux1!=NULL){
        aux2=aux1->prox;
        while(aux2!=NULL){
            if (aux1->num==aux2->num){
                x=aux1->num;
                S=removeConj(S,x);}
            aux2=aux2->prox;}
        aux1=aux1->prox;}
    return S;}
tCon* intersecao(tCon *A1,tCon *A2){
    tCon *aux1=A1,*aux2=A2,*S=NULL,*novo=NULL;
    int x;
    if (A1==NULL || A2==NULL) return S;
    while(aux1!=NULL){
        aux2=A2;
        while(aux2!=NULL){
            if (aux1->num==aux2->num){
                x=aux1->num;
                novo=criaNo(x);
                S=insere(S,novo);}
            aux2=aux2->prox;}
        aux1=aux1->prox;}
    return S;}
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
