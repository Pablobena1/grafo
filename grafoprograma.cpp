#include "grafoN.h"
#include <iostream>
#include <string>

using namespace std;

// Función de dispersión
int funcionDispersa(string texto) {
    int sumaAscii = 0;
    for (char c : texto) {
        sumaAscii += c;
    }
    int sumaDigitos = 6 + 2 + 1 + 3 + 8 + 8;
    return sumaAscii % sumaDigitos;
}

// Función de decodificación
string decodificar(string textoCodificado, int valorDisperso) {
    string textoDecodificado;
    for (char c : textoCodificado) {
        char decodificado = c - valorDisperso; // Resta el valor disperso al valor ASCII del carácter codificado
        textoDecodificado += decodificado;
    }
    return textoDecodificado;
}

