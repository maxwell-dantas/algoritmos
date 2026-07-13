#include "ordenacao.hpp"

bool ordenado(int a[],  unsigned int t){ // desempenho O(n)
    for (unsigned int i = 1; i < t; i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

void selecao(int a[], unsigned int t){ // desempenho O(n²)
    for (unsigned int i = 0; i < (t - 1); i++) {
        int idxMin = i;

        for (unsigned int j = (i + 1); j < t; j++) {
            if (a[idxMin] > a[j]) {
                idxMin = j;
            }
        }

        int aux = a[i];
        a[i] = a[idxMin];
        a[idxMin] = aux;
    }
}

void insercao(int a[], unsigned int t){ // desempenho O(n²)
    for (unsigned int i = 1; i < t; i++) {
        int idxAtual = i;

        for (int j = (i - 1); j > -1; j--) {
            if (a[idxAtual] < a[j]) {
                int aux = a[idxAtual];
                a[idxAtual] = a[j];
                a[j] = aux;
                idxAtual--;
            } else {
                break;
            }
        }
    }
}

void insercao_otimizada(int a[], unsigned int t) { // desempenho O(n²) --> a diferença é que aqui eu desloco ao invés de executar o swap
    for (unsigned int i = 0; i < t; i++) {
        int value = a[i];
        int j = i - 1;

        while (j > -1 && value < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = value;
    }
}

void merge(int a[], int i1, int j1, int i2, int j2) {
    int *temp = new int[((j1 - i1) + (j2 - i2) + 2)];
    int i, j, k;
    i = i1;
    j = i2;
    k = 0;

    while (i <= j1 and j <= j2) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }

    while (i <= j1) {
        temp[k++] = a[i++];
    }

    while (j <= j2) {
        temp[k++] = a[j++];
    }

    for (i = i1, j = 0;i <= j2;i++, j++) {
        a[i] = temp[j];
    }

    delete[] temp;
}

void merge_sort_r(int a[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        merge_sort_r(a, inicio, meio);
        merge_sort_r(a, meio + 1, fim);
        merge(a, inicio, meio, meio + 1, fim);      
    }
}

void merge_sort(int a[], unsigned int t) {
    if (t > 1) {
        merge_sort_r(a, 0, t - 1);
    }
};