void MaiorMenor(int maior,int menor,int *v){
    int i = 0,n;
    maior = v[0];
    menor = v[0];
    for (i=0;i<n;i++){
        if (v[i]>maior){
            maior = v[i];
        }
        if (v[i]<menor){
            menor = v[i];
        }
    }
    printf("%d %d",maior,menor);
}