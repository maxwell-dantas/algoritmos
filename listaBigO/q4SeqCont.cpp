#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int seqContigua = 1;
    int maiorseq = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i-1]) {
            seqContigua++;
            if (seqContigua > maiorseq) {
                maiorseq = seqContigua;
            }
        } else {
            seqContigua = 1;
        }
    }
    std::cout << maiorseq;
    return 0;
}