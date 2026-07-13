#include <iostream>
#include <vector>
#include "mergeSort.h"

void mergeSort(vector <double> &vetor, int inicio, int fim, int &contador) {
    int meio;

    if (inicio >= fim) return;

    meio = inicio + (fim - inicio) / 2; // definição do meio
    
    mergeSort(vetor, inicio, meio,contador); //divisão da esquerda, representa o vetor do inicio até o meio
    contador++;
    mergeSort(vetor, meio + 1, fim, contador); //divisão da direita, representa o vetor do meio + 1 até o fim
    contador++; // tanto esse quanto o contador acima fazem a contagem de quebra do vetor
    merge(vetor,inicio,meio,fim,contador); // chamada da função merge que vai organizar de modo crescente 
}

void merge(vector <double> &vetor, int inicio, int fim, int meio, int &contador) {
    vector <double> aux;
    int i = inicio;
    int j = meio + 1;
    while (i <= meio && j <= fim) {
        if (vetor[i] <= vetor[j]) {
            aux.push_back(vetor[i]);
            i++;
            contador++;
        } else {
            aux.push_back(vetor[j]);
            j++;
            contador++;
        }
    }

    while (i <= meio){
        aux.push_back(vetor[i]);
        i++;
        contador++;
    }
    while (j <= fim) {
        aux.push_back(vetor[j]);
        j++;
        contador++;
    }

    for (int p = 0; p < aux.size(); p++) {
        vetor[inicio + p] = aux[p];
        contador++;
    }

}