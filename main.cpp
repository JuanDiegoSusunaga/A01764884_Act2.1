/*
 * Archivo: actividad_2_1.cpp
 * Descripción: Implementación de una función de hash polinómico para calcular el valor hash de una cadena.
 * Autor: Juan Diego Susunaga
 * Matrícula: A01764884
 * Fecha: 31/03/2025
 */
#include <iostream>
#include <string>

using namespace std;

long long prhf(string s) {
 int n = s.length();
 int p = 31;
 int m = 1e9 + 9;
 long long valorHash = 0;
 long long potencia = 1;

 for (int i = 0; i < n; i++) {
  valorHash = (valorHash + (s[i] - 'a' + 1) * potencia) % m;
  potencia = (potencia * p) % m;
 }
 return valorHash;
}

int main() {
 string S;
 getline(cin, S);
 cout << prhf(S) << endl;
 return 0;
}
