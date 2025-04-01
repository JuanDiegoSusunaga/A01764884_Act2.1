/*
 * Descripción: Pruebas unitarias para la función de hash polinómico.
 * Autor: Juan Diego Susunaga
 * Matrícula: A01764884
 * Fecha: 31/03/2025
 */

#include "gtest/gtest.h"
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

// Prueba con casos básicos
TEST(hash_function_test, basic_cases) {
    EXPECT_EQ(prhf("abc"), 2946);
    EXPECT_EQ(prhf("hello"), 99162322);
    EXPECT_EQ(prhf("test"), 120129);
}

TEST(hash_function_test, edge_cases) {
    EXPECT_EQ(prhf(""), 0);  
    EXPECT_EQ(prhf("a"), 1);
}


// Función main para ejecutar las pruebas
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
