int PesquisaBinaria (int x, int *v, int Li, int n) {
    int meio;
    meio = ((n+Li)/2);
    if (v[meio] == x){  //encontrou o numero
        printf("%d",meio);
    } 
    if (Li > n) {//nao encontrou
        return -1;
    } 
    else {
        if (v[meio] < x){
            return PesquisaBinaria(x,v, meio+1,n);
        }
        else {
            return PesquisaBinaria(x,v,Li,meio-1);
        }
    }
}