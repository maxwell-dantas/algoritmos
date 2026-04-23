#include <iostream>
#include <vector>
int main() { 
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int s;
    char ans = 'N';
    std::cin >> s;
    for (int i = 0; i < n; i++) {
        long long numAtual = a[i];
        for (int j = i + 1; j < n; j++) {
            if (numAtual + a[j] == s) {
                ans = 'S';
                break;
            }
        }
        if (ans == 'S') {
            break;
        }
    }
    std::cout << ans;
    return 0;
}