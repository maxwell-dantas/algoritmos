#include <iostream>

long long soma(long long a, long long b) {
  long long r = a + b;
  return r;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  long long s = soma(a, b);
  std::cout << s << std::endl;
  return 0;
}

/*
Testes de Valores (Tipos int - 32 bits):
(1) a = 10          | b = 20          | s = 30
(2) a = -10         | b = 10          | s = 0
(3) a = -2          | b = -3          | s = -5
(4) a = 1000000000  | b = 1000000000  | s = 2000000000
(5) a = -1000000001 | b = 1000000005  | s = 4
(6) a = 2000000000  | b = 1000000000  | s = -1294967296 (overflow)
(7) a = -1212121212 | b = -2987654321 | s = 935362436   (overflow)

(c) Explicação dos resultados 6 e 7:
Os dois últimos testes resultaram em overflow. Isso ocorre porque o 
tipo de dado inteiro padrão ("int") possui apenas 32 bits. Em complemento de 2, o intervalo vai de -2^31 até (2^31) - 1.

(d) Correções para os resultados incorretos:
Para resolver o problema, é necessário alterar o tipo das variáveis ('a', 'b', 's' e 'r') 
e o retorno da função "soma" para o tipo "long long". Esse tipo aloca 64 bits de memória, 
estendendo o intervalo em complemento de 2 para -2^63 até (2^63) - 1, o que é mais do 
que suficiente para armazenar as somas corretamente.

Testes de Valores Corrigidos (Tipos long long - 64 bits):
(6) a = 2000000000  | b = 1000000000  | s = 3000000000
(7) a = -1212121212 | b = -2987654321 | s = -4199775533
*/