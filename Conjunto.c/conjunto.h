/*Nome: conjunto.h
Observacoes: Criacao de conjuntos numericos e operacoes feitas entre esses conjuntos utilizando lista duplamente encadeada*/

    #ifndef _CONJUNTO_H
    #define _CONJUNTO_H
    #include <stdio.h>
    #include <stdlib.h>
/*Estrutura de dados utilizada no codigo
    typedef struct conj{
        int num;
        struct conj *prox,*ant;} tCon;

    /*Nome: criaNo Objetivo: recebe como parametro a chave e retorna um no*/
    tCon* criaNo(int num);

    /*Nome: removeConj Objetivo: recebe como paramentro o conjunto e uma chave para ser removida, retorna o conjunto sem o no*/
    tCon* removeConj;

    /*Nome: insere  Objetivo: recebe como parametro o conjunto e um no criado para ser inserido no conjunto, retorna o conjunto com o no inserido*/
    tCon* insere(tCon *A,tCon *novo);

    /*Nome: verificaVazio Objetivo: recebe o conjunto como paramentro, printa se ele e vazio ou nao e retorna verdadeiro ou falso*/
    int verificaVazio(tCon *A);

    /*Nome: cardinalidade Objetivo: recebe o conjunto e retorna o seu tamanho*/
    int cardinalidade(tCon *A);

    /*Nome: verificaNum Objetivo: recebe como parametro o conjunto, uma chave e retorna essa chave*/
    int verificaNum(tCon *A,int num);

    /*Nome: imprime Objetivo: recebe como parametro o conjunto e printa as chaves desse conjunto*/
    void imprime(tCon *A);

    /*Nome: subConj Objetivo: recebe 2 conjuntos como parametro, analisa se o primeiro e subconjunto do segundo, retorna 0 se nao for e printa na tela*/
    int subConj(tCon *A1,tCon *A2);

    /*Nome: diferenca Objetivo: tem como parametro dois conjuntos, faz a diferenca entre os dois e retorna um conjunto contendo a solucao*/
    tCon* diferenca(tCon *A1,tCon *A2);

    /*Nome: verifica Objetivo: recebe como parametro dois conjuntos e printa se os dois sao iguais*/
    void verifica(tCon *A1,tCon *A2);

    /*Nome: uniao Objetivo: recebe 2 conjuntos como parametro e retorna o conjunto solucao contendo a uniao*/
    tCon* uniao(tCon *A1,tCon *A2);

    /*Nome: intersecao Objetivo: recebe dois conjuntos como parametro, retorna um novo conjunto contendo a intersecao entre ele*/
    tCon* intersecao(tCon *A1,tCon *A2);

    #endif
