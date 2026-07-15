#include <iostream>
#include <vector>
#include "bubbleSort.h"

using namespace std;

/*
Bubble Sort - O(n²)

A ideia é percorrer o vetor várias vezes comparando pares de elementos
que estão lado a lado. Se o elemento da esquerda for maior que o da direita, eles
trocam de posição. A cada passagem completa, o maior valor restante
é encaminhado até a posição correta no final do vetor.

Essa é a versão SEM otimização de parada antecipada, ou seja, o número
de comparações é sempre o mesmo (n-1 + n-2 + ... + 1), independente da
disposição inicial do vetor. Já o número de trocas varia bastante:
zero se o vetor já vier ordenado, e próximo do número de comparações
se vier em ordem decrescente (pior caso).
*/
void bubbleSort(vector <int> &vetor, int &comparacoes, int &trocas) {
    int n = vetor.size();

    comparacoes = 0;
    trocas = 0;

    /*
    Primeira iteração: 0...(n-2)
    Controla o número de passagens completas pelo vetor.
    A cada passagem, o maior elemento entre os que restam
    é "empurrado" até sua posição final, então a próxima
    passagem não precisa mais olhar pra ele.
    */
    for (int i = 0; i < n - 1; i++) {

        /*
        Segunda iteração: 0...(n-2-i)
        Percorre o vetor comparando pares vizinhos.
        O limite (n-1-i) diminui a cada passagem porque o final
        do vetor já está ordenado pelas passagens anteriores.
        */
        for (int j = 0; j < n - 1 - i; j++) {
            comparacoes++;

            if (vetor[j] > vetor[j + 1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                trocas++;
            }
        }
    }
}