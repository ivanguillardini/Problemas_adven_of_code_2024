
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath> // Para abs()

// Función para calcular la distancia total entre dos listas
int calcularDistanciaTotal(const std::vector<int>& izquierda, const std::vector<int>& derecha) {
    // Crear tablas hash para contar las frecuencias de los números en ambas listas
    std::unordered_map<int, int> hashIzquierda;
    std::unordered_map<int, int> hashDerecha;

    // Contar frecuencias en la lista izquierda
    for (int num : izquierda) {
        hashIzquierda[num]++;
    }

    // Contar frecuencias en la lista derecha
    for (int num : derecha) {
        hashDerecha[num]++;
    }

    // Extraer claves (números únicos) de ambas tablas hash
    std::vector<int> clavesIzquierda;
    std::vector<int> clavesDerecha;

    for (const auto& par : hashIzquierda) {
        clavesIzquierda.push_back(par.first);
    }

    for (const auto& par : hashDerecha) {
        clavesDerecha.push_back(par.first);
    }

    // Ordenar las claves para emparejar por valores mínimos
    std::sort(clavesIzquierda.begin(), clavesIzquierda.end());
    std::sort(clavesDerecha.begin(), clavesDerecha.end());

    // Inicializar punteros para recorrer ambas listas de claves
    int i = 0, j = 0;
    int distanciaTotal = 0;

    // Emparejar las claves de las dos listas
    while (i < clavesIzquierda.size() && j < clavesDerecha.size()) {
        // Obtener el número de veces que se debe considerar este par
        int minimoFrecuencia = std::min(hashIzquierda[clavesIzquierda[i]], hashDerecha[clavesDerecha[j]]);

        // Calcular la distancia entre los números actuales
        int distancia = abs(clavesIzquierda[i] - clavesDerecha[j]);

        // Sumar la distancia al resultado total (multiplicada por la frecuencia mínima)
        distanciaTotal += distancia * minimoFrecuencia;

        // Reducir las frecuencias usadas en las tablas hash
        hashIzquierda[clavesIzquierda[i]] -= minimoFrecuencia;
        hashDerecha[clavesDerecha[j]] -= minimoFrecuencia;

        // Avanzar en las listas según la frecuencia actual
        if (hashIzquierda[clavesIzquierda[i]] == 0) {
            i++;
        }
        if (hashDerecha[clavesDerecha[j]] == 0) {
            j++;
        }
    }

    return distanciaTotal;
}

int main() {
    // Listas a ser llenadas por el usuario
    std::vector<int> izquierda;
    std::vector<int> derecha;

    int n;

    // Leer lista izquierda
    std::cout << "Ingrese el número de elementos para la lista izquierda: ";
    std::cin >> n;
    std::cout << "Ingrese los elementos de la lista izquierda: \n";
    for (int i = 0; i < n; ++i) {
        int valor;
        std::cin >> valor;
        izquierda.push_back(valor);
    }

    // Leer lista derecha
    std::cout << "Ingrese el número de elementos para la lista derecha: ";
    std::cin >> n;
    std::cout << "Ingrese los elementos de la lista derecha: \n";
    for (int i = 0; i < n; ++i) {
        int valor;
        std::cin >> valor;
        derecha.push_back(valor);
    }

    // Calcular la distancia total
    int distancia = calcularDistanciaTotal(izquierda, derecha);

    // Mostrar el resultado
    std::cout << "La distancia total entre las listas es: " << distancia << std::endl;

    return 0;
}

