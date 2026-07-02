#include <iostream>
#include <vector>
using namespace std;

int labirinto_bt(vector<vector<int>> &labirinto, unsigned int linha, unsigned int coluna, unsigned int l, unsigned int c) {
    if (l >= linha || c >= coluna || labirinto[l][c] != 0) {
        return false;
    }

    if (l == linha - 1 && c == coluna - 1) {
        return true;
    }

    labirinto[l][c] = -1;

    bool ans =
        labirinto_bt(labirinto, linha, coluna, l + 1, c) ||
        labirinto_bt(labirinto, linha, coluna, l, c + 1) ||
        labirinto_bt(labirinto, linha, coluna, l, c - 1) ||
        labirinto_bt(labirinto, linha, coluna, l - 1, c);

    labirinto[l][c] = 0;

    if (ans) {return 1;}
    return 0;
}

int main() {
    unsigned int linha, coluna; cin >> linha >> coluna;
    vector<vector<int>> labirinto(linha, vector<int>(coluna));

    for (unsigned int i = 0; i < linha; i++) {
        for (unsigned int j = 0; j < coluna; j++) {
            cin >> labirinto[i][j];
        }
    }

    int ans = labirinto_bt(labirinto, linha, coluna, 0, 0);
    cout << ans << endl;
    return 0;
}