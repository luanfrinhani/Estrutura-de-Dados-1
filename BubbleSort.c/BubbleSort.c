int* bubbleSort (int *v,int n){
    int i,j,aux;
    for (i=n-1;i>0;i--){
        for (j=0;j<i;j++){
            if (v[j]>v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
    return v;
}