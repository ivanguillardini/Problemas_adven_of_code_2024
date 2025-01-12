
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Nodo {
public:
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int val){
	valor=val;
   	izquierda=nullptr;
       	derecha=nullptr;
    }
};

class ArbolBinario {
private:
    Nodo* raiz;

    void insertar(Nodo*& nodo, int valor) {
        if (nodo == nullptr) {
            nodo = new Nodo(valor);
        } else if (valor < nodo->valor) {
            insertar(nodo->izquierda, valor);
        } else {
            insertar(nodo->derecha, valor);
        }
    }

    void ordenrecursivo(Nodo* nodo, vector<int>& elementos) {
        if (nodo != nullptr) {
            ordenrecursivo(nodo->izquierda, elementos);//Recorrido lado izquierdo del arbol para llegar a la posicion que debe ser colocado 
            elementos.push_back(nodo->valor);//Se coloca el valor en la posición
            ordenrecursivo(nodo->derecha, elementos);//Hacemos un recorrido en el lado derecho del arbol
        }
    }

public:
    ArbolBinario(){//Metodo Constructor
	    raiz=nullptr; 
    }

    void introducir(int valor) {//Metodo lanzadera de la funcion private "insertar"
        insertar(raiz, valor);
    }

    vector<int> in_orden() {//Metodo lanzadera de la funcion privada "ondenrecursivo"
        vector<int> elementos;
        ordenrecursivo(raiz, elementos);
        return elementos;
    }
};

// Función para calcular la distancia total entre dos listas
int calcular_distancia_total(const vector<int>& vectorizquierda, const vector<int>& vectorderecha) {
    // Crear árboles binarios
    ArbolBinario arbolizq;
    ArbolBinario arbolderecha;

    // Insertar elementos en los árboles
    for( int i =0; i < vectorizquierda.size(); i++){
	    int num = vectorizquierda[i];
	    arbolizq.introducir(num);
	 }
    for (int i =0; i < vectorderecha.size(); i++){
	    int num = vectorderecha[i];
	    arbolderecha.introducir(num);
	 }
    // Obtener listas ordenadas
    vector<int> vectorizquierdaordenada = arbolizq.in_orden();
    vector<int> vectorderechaordenada = arbolderecha.in_orden();

    // Calcular la distancia total
    int distancia = 0;
    for (size_t i = 0; i < vectorizquierdaordenada.size(); ++i) {
        distancia += abs(vectorizquierdaordenada[i] - vectorderechaordenada[i]);
    }

    return distancia;
}

int main() {
    vector<int> vectorizquierda = {38, 43, 28, 16, 35, 39};
    vector<int> vectorderecha = {47, 36, 55, 36, 97, 35};

    int distancia_total = calcular_distancia_total(vectorizquierda, vectorderecha);
    cout << "La distancia total entre las listas es: " << distancia_total << endl;

    return 0;
}
