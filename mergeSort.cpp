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
    while (i <= meio && j <= fim) { //dividi as duas partes lá encima e aqui divide o vetor pra juntar encima
        contador++; //
        if (vetor[i] <= vetor[j]) { // se o indice 0 do vetor a for maior que o indice 0 do vetor b, ele vai pro vetor c
            aux.push_back(vetor[i]);
            i++;
        } else { // analogo ao que tá acima, ele pega o b e joga pro c
            aux.push_back(vetor[j]); 
            j++;
        }
        contador++;
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
    /*
    esses dois whiles de cima tratam pro caso de se um dos vetores ainda estiverem com elementos
    ele vai colocando eles no vetor c
    por que eles já são maiores do que qualquer coisa que está lá
    e eles só são usados se o while acima deles (da linha 23) acabar e ainda contiver elementos 
    */

    for (int p = 0; p < aux.size(); p++) { // joga os elementos do vetor c pro vetor original 
        vetor[inicio + p] = aux[p];
        contador++;
    }

}