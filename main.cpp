#include <random>
#include <vector>
#include <cmath>
#include <algorithm>
#include "mergeSort.h"
#include "countingSort.h"
#include "bubbleSort.h"

vector<int> lista;
int continuar = 1;
int choice;
int tamanho;

using namespace std;

int main() {
    while (continuar == 1) {

        /* Escolha do tamanho da lista */
        while (true) {
            cout << "Escolha a quantidade de valores: \n";
            cout << "[1] 10\n" 
                 << "[2] 100\n" 
                 << "[3] 1.000\n" 
                 << "[4] 10.000\n" 
                 << "> ";
            cin >> choice;

            if (choice == 1 || choice == 2 || choice == 3 || choice == 4) {
                tamanho = pow(10, choice);
                break;
            } else {
                cout << "Tente novamente.\n"; 
            };
        };



        /* Escolha da ordem da lista */
        while (true) {
            cout << "Escolha a ordem dos valores: \n";
            cout << "[1] Crescente (melhor caso)\n" 
                 << "[2] Decrescente (pior caso)\n" 
                 << "[3] Aleatório (caso médio)\n" 
                 << "> ";
            cin >> choice;

            switch (choice) {
                case 1:
                    for (int i = 1; i <= tamanho; i++) { lista.push_back(i); };
                    break;
                case 2:
                    for (int i = tamanho; i >= 1; i--) { lista.push_back(i); };
                    break;
                case 3:
                    for (int i = 1; i <= tamanho; i++) { lista.push_back(i); };
                    random_shuffle(lista.begin(), lista.end());
                    break;
                default: 
                    cout << "Tente novamente.\n";
                    continue;
                };
            break;  
        };



        /* Escolha de impressão do vetor */
        cout << "Quer imprimir o vetor? \n";
        cout << "[1] Sim\n" 
             << "[2] Não\n" 
             << "> ";
        cin >> choice;
        if (choice == 1) {
            for (int x : lista) {
                int ultimo = lista.back();
                if (x == ultimo) {
                    cout << x << endl;
                } else {
                    cout << x << ", ";
                }
            };
        };
        



        /* Escolha do algoritmo de ordenação */
        while (true) {
            cout << "Escolha o algoritmo de ordenação:\n";
            cout << "[1] Bubble Sort (O(n²))\n" 
                 << "[2] Merge Sort (O(nlogn))\n" 
                 << "[3] Counting Sort (O(n))\n" 
                 << "> ";
            cin >> choice;

            if (choice == 1 || choice == 2 || choice == 3) {
                /* TODO */
                break;
            }
        };



        /* Número de comparações, número de trocas, tempo de execução: TODO */



        /* Rodar novamente */
        cout << "Deseja rodar novamente?\n";
        cout << "[1] Sim\n" 
             << "[2] Não\n" 
             << "> ";
        cin >> continuar;

        if (continuar == 1) { lista.clear(); };
    };
};
  