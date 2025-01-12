
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>

class NodoPiedra {
public:
    long long valor; // Cambiado a long long para manejar números grandes
    std::unique_ptr<NodoPiedra> izquierda;
    std::unique_ptr<NodoPiedra> derecha;

    NodoPiedra(long long valorInicial) : valor(valorInicial), izquierda(nullptr), derecha(nullptr) {}

    void evolucionar() {
        if (valor == 0) {
            valor = 1; // Caso donde el valor es 0
        } else {
            std::string digitos = std::to_string(valor);
            if (digitos.length() % 2 == 0) {
                // Caso donde el número tiene cantidad par de dígitos
                int mitad = digitos.length() / 2;

                    long long valorIzq = std::stoll(digitos.substr(0, mitad));
                    long long valorDer = std::stoll(digitos.substr(mitad));

                    izquierda = std::make_unique<NodoPiedra>(valorIzq);
                    derecha = std::make_unique<NodoPiedra>(valorDer);

                    valor = -1; // Indicamos que este nodo ya no tiene un valor útil
         
	    } else {
                // Caso donde multiplicamos por 2024
                valor *= 2024;
            }
        }
    }
   bool esHoja() const {
        return izquierda == nullptr && derecha == nullptr;
    }
};

int contarPiedras(const NodoPiedra* nodo) {
    if (!nodo) {
        return 0;
    }
    if (nodo->esHoja()) {
        return 1;
    }
    return contarPiedras(nodo->izquierda.get()) + contarPiedras(nodo->derecha.get());
}

void evolucionarNodo(NodoPiedra* nodo) {
    if (!nodo) {
        return;
    }
    if (nodo->esHoja()) {
        nodo->evolucionar();
    } else {
        evolucionarNodo(nodo->izquierda.get());
        evolucionarNodo(nodo->derecha.get());
    }
}

    std::vector<std::unique_ptr<NodoPiedra>> inicializarPiedras(const std::vector<long long>& valores) {
    std::vector<std::unique_ptr<NodoPiedra>> piedras;
    for (long long valor : valores) {
        piedras.push_back(std::make_unique<NodoPiedra>(valor));
    }
    return piedras;
}

int evolucionarYContar(const std::vector<long long>& valoresIniciales, int parpadeos) {
    auto piedras = inicializarPiedras(valoresIniciales);

    for (int i = 0; i < parpadeos; i++) {
        for (auto& piedra : piedras) {
            evolucionarNodo(piedra.get());
        }
    }

    int totalPiedras = 0;
    for (const auto& piedra : piedras) {
        totalPiedras += contarPiedras(piedra.get());
    }
    return totalPiedras;
}

int main() {
    std::vector<long long> piedrasIniciales = {337, 42493, 1891760, 351136, 2, 6932, 73, 0};
    int parpadeos = 25;

    int resultado = evolucionarYContar(piedrasIniciales, parpadeos);

    std::cout << "Después de " << parpadeos << " parpadeos, hay " << resultado << " piedras." << std::endl;

    return 0;
}
