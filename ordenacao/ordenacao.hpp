#ifndef __ORDENACAO__
#define __ORDENACAO__

bool ordenado(int a[],  unsigned int t);
void selecao(int a[], unsigned int t);
void insercao(int a[], unsigned int t);
void insercao_otimizada(int a[], unsigned int t);
void merge(int a[], int i1, int j1, int i2, int j2);
void merge_sort_r(int a[], int inicio, int fim);
void merge_sort(int a[], unsigned int t);

#endif