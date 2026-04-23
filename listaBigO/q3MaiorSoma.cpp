#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maiorSoma = a[0] + a[1];
    for (int i = 2; i < n; i++) {
        int somaAtual = a[i] + a[i - 1];
        if (somaAtual > maiorSoma) {
            maiorSoma = somaAtual;
        }
    }
    cout << maiorSoma;
    return 0;
}