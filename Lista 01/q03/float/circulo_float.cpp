/*
Escreva um programa que leia um número real, com 5 (cinco) casas decimais, que represente o diâmetro de um
círculo e mostre a área a do mesmo, de acordo com a fórmula da área a seguir: a = πr2
onde r é o raio do círculo. Seu programa deve mostrar o resultado com 5 casas decimais.
PS1: Considere o valor de π com 5 casas decimais: 3.14159.
PS2: Lembre-se que o raio é o diâmetro dividido por 2.
*/

#include <iostream>
#include <iomanip>

float calc_area(float diametro) {
  float raio = diametro / 2;
  float pi = 3.14159;
  return pi * (raio * raio);
}

int main() {
  float diametro;
  std::cin >> diametro;
  std::cout << std::fixed << std::setprecision(5) << calc_area(diametro) << std::endl;
  return 0;
}

/*
Casos de Teste (Área do Círculo):
Fórmula: A = pi * r^2  |  pi = 3.14159

| Entrada (Diâmetro) | Saída (Área)              |
|--------------------|---------------------------|
| 1.00000            | 0.78540                   |
| 10.00000           | 78.53975                  |
| 50000.00000        | 1963493888.00000          |
| 100000.00000       | 7853975552.00000          |
| 200000.00000       | 31415902208.00000         |
| 1.56780            | 1.93050                   |
| 123.45678          | 11970.69629               |
| 12345678.87654     | 119706988052480.00000     |
| 2000000000.88888   | 3141590043823439872.00000 |
*/