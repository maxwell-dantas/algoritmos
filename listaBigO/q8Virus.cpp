/* Um novo vírus foi descoberto e sua taxa de transmissão é de 1.0 (100%), o que indica que a quantidade de infectados
dobra a cada dia. Uma vez que o vírus se instala no seu corpo ele se mantém vivo e não causa nenhum mal a
sua saúde, isto quer dizer que todos na cidade serão infectados. Faça um algoritmo que, dada a população de
uma cidade, informe em quantos dias todos da cidade estarão infectados depois do primeiro cidadão ser infectado.
Determine o desempenho do seu algoritmo usando a notação O (big-Oh). */

#include <iostream>

int dayInfected(int population) {
    int ans = 0;
    for (int i = 1; i <= population; i *= 2) {
        ans++;
    }
    return ans;
}

int main() {
    int population;
    std::cin >> population;
    std::cout << dayInfected(population);
    return 0;
}