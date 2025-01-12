
# Resumen de Problemas y Técnicas Algorítmicas

Este repositorio contiene soluciones a varios problemas de programación, cada uno de los cuales utiliza una técnica algorítmica diferente. A continuación, se presenta un resumen de los problemas y las razones por las cuales se eligieron, teniendo en cuenta las cinco técnicas principales: **Divide y Vencerás**, **Hash Table**, **Grafos**, **Programación Dinámica** y **Árbol Binario**.

---

## 1. **Divide y Vencerás**
### Problema: Day1. Ordenamiento y Cálculo de Distancia entre Listas.
- **Descripción**: Se tienen dos listas de números únicos que representan ubicaciones. El objetivo es calcular la distancia total entre las listas ordenadas.
- **Técnica Utilizada**: **Divide y Vencerás** (Merge Sort).
- **Razón de Elección**: 
  - El problema requiere ordenar ambas listas para emparejar los elementos y calcular las diferencias. 
  - Merge Sort es un algoritmo eficiente que utiliza la técnica de "divide y vencerás", dividiendo el problema en subproblemas más pequeños, resolviéndolos y combinando las soluciones.
  - Esta técnica es ideal para problemas de ordenamiento y emparejamiento.

---

## 2. **Hash Table**
### Problema:Day1. Cálculo de Distancia entre Listas usando Tablas Hash
- **Descripción**: Dadas dos listas de números, se debe calcular la distancia total entre ellas, considerando las frecuencias de los números y emparejándolos de manera eficiente.
- **Técnica Utilizada**: **Hash Table** (unordered_map en C++).
- **Razón de Elección**:
  - Las tablas hash permiten un acceso rápido a los elementos y son ideales para realizar búsquedas eficientes.
  - En este problema, se utilizan para almacenar las frecuencias de los números en ambas listas y para emparejarlos de manera óptima.
  - La técnica es especialmente útil cuando se necesita realizar operaciones de búsqueda y conteo en tiempo constante.

---

## 3. **Grafos**
### Problema: Day 5 y 23 LAN Party - Triángulos en un Grafo
- **Descripción**: Dada una lista de conexiones entre ordenadores, se deben encontrar triángulos (grupos de tres ordenadores interconectados) que contengan al menos un ordenador cuyo nombre comience con 't'.
- **Técnica Utilizada**: **Grafos** (representación con mapas y conjuntos).
- **Razón de Elección**:
  - El problema se modela naturalmente como un grafo, donde los nodos son los ordenadores y las aristas son las conexiones entre ellos.
  - La búsqueda de triángulos en un grafo es un problema clásico que se resuelve eficientemente utilizando estructuras de grafos y algoritmos de recorrido.
  - La representación con mapas y conjuntos permite verificar conexiones entre nodos de manera rápida y eficiente.

---

## 4. **Programación Dinámica**
### Problema: Day11.Transformación de Piedras con Memorización
- **Descripción**: Se simula una transformación iterativa sobre un conjunto de "piedras" durante un número definido de "parpadeos". Se utiliza memorización para evitar cálculos repetidos.
- **Técnica Utilizada**: **Programación Dinámica** (memorización con unordered_map).
- **Razón de Elección**:
  - El problema involucra transformaciones repetitivas sobre un conjunto de datos, lo que genera subproblemas superpuestos.
  - La memorización permite almacenar resultados intermedios y reutilizarlos, evitando recalcularlos en futuras iteraciones.
  - Esta técnica es esencial para optimizar problemas con subproblemas superpuestos y reducir la complejidad temporal.

---

## 5. **Árbol Binario**
### Problema:Dia1 Ordenamiento y Cálculo de Distancia usando Árboles Binarios
- **Descripción**: Se tienen dos listas de números que deben ser ordenadas y emparejadas para calcular la distancia total entre ellas.
- **Técnica Utilizada**: **Árbol Binario** (inserción y recorrido inorden).
- **Razón de Elección**:
  - Los árboles binarios son estructuras eficientes para almacenar y ordenar datos. En este problema, se utilizan para insertar los números de las listas y luego recorrerlos en orden ascendente.
  - El recorrido inorden de un árbol binario de búsqueda garantiza que los elementos se procesen en orden, lo que facilita el emparejamiento y el cálculo de distancias.
  - Esta técnica es ideal para problemas que requieren ordenamiento y recorrido eficiente de datos.

---

## Conclusión
Cada problema fue seleccionado para representar una técnica algorítmica específica, demostrando cómo estas técnicas pueden aplicarse para resolver problemas reales de manera eficiente. La elección de cada técnica se basó en las características del problema y en cómo la técnica podía optimizar la solución:

- **Divide y Vencerás**: Para problemas de ordenamiento y emparejamiento.
- **Hash Table**: Para problemas que requieren conteo y búsqueda rápida.
- **Grafos**: Para problemas que involucran relaciones y conexiones entre entidades.
- **Programación Dinámica**: Para problemas con subproblemas superpuestos y cálculos repetitivos.
- **Árbol Binario**: Para problemas que requieren almacenamiento y recorrido ordenado de datos.

