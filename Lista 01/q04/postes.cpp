/* 
Escreva um algoritmo que calcule a quantidade de postes a serem colocados em uma rua. O algoritmo tem como
entrada a distância do início ao fim da rua, um número inteiro m, em metros, e a distância entre 2 (dois) postes p,
também em metros. Há sempre um poste no ponto 0 da rua e outro no ponto m, que é o final da rua. Seu programa
deve mostrar a quantidade de postes a serem colocados e a distância entre os dois últimos postes. Lembre-se que
há sempre um poste no início da rua e outro no final. A distância entre cada par de postes é o valor, em metros,
lido pelo programa, com exceção da distância entre os dois últimos postes da rua.
Exemplo: Se a rua tiver 1000 metros e a distância entre os postes for de 250 metros então temos 5 postes, com
distância de 250 metros entre eles. Já se a rua tiver os mesmos 1000 metros e a distância entre os postes for de 300
metros, a rua terá os mesmos 5 postes, mas a distência entre os dois últimos postes será de 100 metros. 
*/

#include <iostream>

int main() {
  int distanciaRua;
  int distanciaPoste;
  int qtdPostes = 2;

  std::cout << "Distancia da rua: ";
  std::cin >> distanciaRua;
  std::cout << "Distancia entre os postes: ";
  std::cin >> distanciaPoste;
  int acumulador = distanciaPoste;

  while (acumulador < distanciaRua) {
    qtdPostes += 1;
    acumulador += distanciaPoste;
  }

  std::cout << "Quantidade de postes: " << qtdPostes << "\nDistancia entre os dois ultimos postes: " << distanciaRua - (acumulador - distanciaPoste) << std::endl;
  return 0;
}