/* 
Escreva um programa que leia dois lados l1 e l2 que forma um retângulo, como mostrado a seguir, e mostre o
perímetro do retângulo.
Considere a restriçao 1 ≤ li ≤ 109, ou seja, tanto l1 quanto l2 possuem valores entre 1 e 109 (1000000000 - Um bilhão). 
*/

#include <iostream>

long long calcula_perimetro(long long l1, long long l2) {
  return 2*l1 + 2*l2;
}

int main() {
  int l1, l2;
  std::cin >> l1 >> l2;
  std::cout << calcula_perimetro(l1, l2);
  return 0;
}

/*
(a) Determine e explique qual o tipo de l1 e de l2.
  - O tipo de l1 e l2 deve ser no mínimo **int**, pois o limite estabelecido é de 1.000.000.000 (um bilhão)

(b) Escreva uma função que receba Os 2 (dois) parâmetros e retorne o perímetro. Determine o tipo de dado de
retorno da função.
  - O tipo de dado do retorno da função é um "long long", pois caso l1 e l2 sejam um bilhão, teríamos um perímetro de 4 bilhões, sendo assim
  não caberiam no tipo de dado "int"

(c) Escreva um conjunto com, pelo menos, 5 casos de teste e monte uma tabela.
Testes de Valores:
(1) l1 = 1           | l2 = 1           | calcula_perimetro(l1, l2) = 4
(2) l1 = 10          | l2 = 20          | calcula_perimetro(l1, l2) = 60
(3) l1 = 5000        | l2 = 100000      | calcula_perimetro(l1, l2) = 210000
(4) l1 = 1000000000  | l2 = 500000      | calcula_perimetro(l1, l2) = 2001000000
(5) l1 = 1000000000  | l2 = 1000000000  | calcula_perimetro(l1, l2) = 4000000000
*/