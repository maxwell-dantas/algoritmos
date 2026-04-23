/* Um determinado material perde metade de sua massa a cada período fixo de tempo, dependendo das condições
ambientais. Conhecendo o período de tempo t (inteiro, em segundos) e a massa inicial mi (número real), escreva
um algoritmo que determine em quanto tempo a massa do material se reduz a 1g ou menos. */

#include <iostream>

int tempoMassa(int tempo, double massa) {
    int cont = 0;
    while (massa > 1) {
        massa /= 2;
        cont++;
    }

    return cont * tempo;
}

int main() {
    int tempo;
    double massa;
    std::cin >> tempo >> massa;
    std::cout << tempoMassa(tempo, massa);
    return 0;
}