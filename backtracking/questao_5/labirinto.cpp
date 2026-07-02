#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int labirinto_bt(vector<vector<int>> &labirinto, unsigned int linha, unsigned int coluna, unsigned int lf, unsigned int cf, unsigned int l, unsigned int c) {
        if (l >= linha || c >= coluna || labirinto[l][c] <= -1) {
            return linha * coluna * 1000;
        }

        if (l == lf && c == cf) {
            return 0;
        }

        int value = labirinto[l][c];

        labirinto[l][c] = -10;

        int ans = min({
            value + labirinto_bt(labirinto, linha, coluna, lf, cf, l + 1, c),
            value + labirinto_bt(labirinto, linha, coluna, lf, cf, l, c + 1),
            value + labirinto_bt(labirinto, linha, coluna, lf, cf, l, c - 1),
            value + labirinto_bt(labirinto, linha, coluna, lf, cf, l - 1, c)
        });

        labirinto[l][c] = 0;
        return ans;
}

int main() {
    unsigned int linha, coluna; cin >> linha >> coluna;
    unsigned int l, c; cin >> l >> c;
    unsigned int lf, cf; cin >> lf >> cf;
    
    vector<vector<int>> labirinto(linha, vector<int>(coluna));

    for (unsigned int i = 0; i < linha; i++) {
        for (unsigned int j = 0; j < coluna; j++) {
            cin >> labirinto[i][j];
        }
    }

    int ans = labirinto_bt(labirinto, linha, coluna, lf, cf, l, c);
    if (ans >= linha * coluna * 1000) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}