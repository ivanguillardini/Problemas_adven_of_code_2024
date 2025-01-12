
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Mapa de memoria para guardar y coger calculos previamente calculados
unordered_map<long long, vector<long long>> memoria;

// Función para dividir un número en dos mitades.
vector<long long> dividirNumero(long long num) {
    string numero = to_string(num);
    int mitad = numero.size() / 2;
    long long izquierda = stoll(numero.substr(0, mitad));
    long long derecha = stoll(numero.substr(mitad));
    return {izquierda, derecha};
}

// Función para procesar una piedra con memorización.
vector<long long> procesarPiedra(long long piedra) {
    if (memoria.find(piedra) != memoria.end()) {
        return memoria[piedra]; // Devolver resultado guardado si ya fue calculado.
    }

    vector<long long> resultado;
    if (piedra == 0) {
        resultado.push_back(1);
    } else if (to_string(piedra).size() % 2 == 0) {
        resultado = dividirNumero(piedra);
    } else {
        resultado.push_back(piedra * 2024);
    }

    memoria[piedra] = resultado; // Guardar resultado en la memoria.
    return resultado;
}

// Función para simular los parpadeos.
long long simular(vector<long long> &piedras, int parpadeos) {
    for (int i = 0; i < parpadeos; i++) {
        vector<long long> nuevasPiedras;
        for (long long piedra : piedras) {
            vector<long long> partes = procesarPiedra(piedra);
            nuevasPiedras.insert(nuevasPiedras.end(), partes.begin(), partes.end());
        }
        piedras = nuevasPiedras;
    }
    return piedras.size();
}

int main() {
    vector<long long> piedras = {337,42493,1891760,351136,2,6932,73,0}; // Piedras iniciales.
    int parpadeos = 25; // Número de parpadeos.

    long long total = simular(piedras, parpadeos);
    cout << "Las piedras despues de los " << parpadeos << " parpadeos: " << total << endl;

    return 0;
}
