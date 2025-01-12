#include <iostream>
#include <vector>
#include <map>
#include <set>
#include<stdlib.h>
#include <string>

using namespace std;


//esta funcion sirve para agregar las conexiones al grafo

void agregar_conexion(map<string, set<string>>& grafo, const string& nodo_a, const string& nodo_b) {
    grafo[nodo_a].insert(nodo_b);
    grafo[nodo_b].insert(nodo_a);
}

//esta funcion sirve para encontrar todos los triples nodos concectados entre sí que por abreviar se van a llamar triángulos,  en el grafo
vector<set<string>> encontrar_triangulos(const map<string, set<string>>& grafo) {
    vector<set<string>> triangulos;

    for (const auto& par_nodo : grafo) {

        const string& nodo_actual = par_nodo.first;
        for (const string& vecino1 : par_nodo.second) {
            if (vecino1 > nodo_actual) {

                for (const string& vecino2 : par_nodo.second) {
                    //y aquí verificacamos si vecino1 esta conectado a vecino2
                    if (vecino2 > vecino1 && grafo.at(vecino1).count(vecino2)) { 
                        triangulos.push_back({nodo_actual, vecino1, vecino2});
                    }
                
                }
            }
        }
    }
    return triangulos;
}


//esta funcion sirve para contar los triángulos que contienen al menos un ordenador comienza por la letra 't'
int contar_triangulos_con_t(const vector<set<string>>& triangulos) {
    int contador = 0;

    for (const auto& triangulo : triangulos) {
        for (const string& nodo : triangulo) {

            if (nodo[0] == 't') {
                contador++;
                break;
            }
        }
    }
    return contador;
}

int main() {
    map<string, set<string>> grafo;
    
    cout<<"Intorduce la lista de todas las conexiones entre dos ordenadores o computadores, y para acabar de introdcirlas en la ultima linea pon 'fin'"<<endl;
    //leemos los datos desde la terminal
    string linea;
    while (getline(cin, linea)) {
        if (linea == "fin") {
            break; //cuando se introduce la palbra "fin" se termina
        }
        size_t pos_guion = linea.find('-');
        if (pos_guion == string::npos) {
            continue; 
        }
        //aquí dividimos las dos partes de rws-des por ejemplo y como buscamos "-" que esta en medio, agregamos el primer nodo la primera parte haste el - y la segunda parte desde el - hasta donde acabe
        string nodo_a = linea.substr(0, pos_guion);
        string nodo_b = linea.substr(pos_guion + 1);
        agregar_conexion(grafo, nodo_a, nodo_b);
    }


    //y ahora ya sabiendo todas las conexiones, buscamos con la anterior función creada los nodos triplemente interconectados o triangulos como les vamos a llamr
    vector<set<string>> triangulos = encontrar_triangulos(grafo);


    //y por ultimo con la funcion contar triangulos que uno de ellos empiece con la 't' y lo alamacenamos en la variable resultado
    int resultado = contar_triangulos_con_t(triangulos);

    //y por último mostramos por pantalla el resultado
    cout << "Número de triángulos con al menos una computadora que comienza con 't': " << resultado << endl;

    return 0;
}
