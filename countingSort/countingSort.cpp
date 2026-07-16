#include <iostream>
#include <vector>
#include "countingSort.h"

using namespace std;

int maximo(vector <int> &vetor) {
    int m = vetor[0];
    for (int num : vetor) { if (num > m) { m = num; } }
    return m;
};

void countingSort(vector <int> &vetor) {
    int maior = maximo(vetor);

    vector <int> aux(maior + 1, 0);
    vector <int> saida(vetor.size());

    /* 
    Primeira iteração: 0...(n-1)
    n = tamanho do vetor de entrada

    O valor x no vetor de entrada incrementa na posição x do 
    vetor auxiliar, sendo na prática um histograma.
    */
    for (int i = 0; i < vetor.size(); i++) {
        int j = vetor[i];
        aux[j]++;
    };

    /*
    Segunda iteração: 1...m
    m = tamanho do vetor auxiliar

    Soma cada posição do vetor auxiliar com a posição anterior,
    transformando as contagens individuais em contagens acumuladas
    (quantos elementos são menores ou iguais a cada valor).
    */
    for (int i = 1; i <= maior; i++) {
        aux[i] = aux[i] + aux[i - 1];
    }

    /*
    Terceira iteração: (n-1)...0
    n = tamanho do vetor de entrada

    O vetor auxiliar indica a posição de destino de cada elemento
    no vetor de saída. Subtraímos 1 antes de usar (índice começa em 0)
    e, após colocar o elemento, diminuímos esse valor para que a
    próxima ocorrência do mesmo número fique na posição anterior.
    */
    for (int i = vetor.size() - 1; i >= 0; i--) {
        int j = vetor[i];
        aux[j]--;
        saida[aux[j]] = vetor[i];
    };

    vetor = saida;
};