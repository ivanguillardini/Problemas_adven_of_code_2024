
# Advent of Code Ej1 - > Arboles Binarios
El problema consiste en arreglar dos listas de números que son los IDs de ubicaciones donde puede estar el historiador jefe, proporcionadas por dos grupos de historiadores. Cada lista contiene números únicos, pero las listas no son idénticas. El objetivo es:

Parte 1: consiste en calcular la distancia total entre las dos listas. Lo que primero hacemos es ordenar ambas listas de números en dos arrays diferentes, se emparejan los números más pequeños de ambas listas y se calcula la diferencia absoluta entre ellos. Luego, se suman todas estas diferencias y daría el resultado de la distancia total.
Parte 2: consiste en calcular una puntuación de similitud entre las dos listas. Para ello, se cuenta cuántas veces aparece cada número de la lista izquierda en la lista derecha, y se suma el producto de cada número por su frecuencia que aparece en la lista derecha.

# Solución Implementada
El código en C++ resuelve el problema. La eleccion de este problema es que el metodo de arboles binarios se veia muy bien, por lo que representa muy bien lo que se pide en la tarea.
A continuación, se explica cómo funciona:
# Estructura Código
1. Entrada de Datos
El programa define dos listas de números enteros, vectorizquierda y vectorderecha, que representan los conjuntos de datos a analizar. Estas listas son fijas en el código ({38, 43, 28, 16, 35, 39} y {47, 36, 55, 36, 97, 35}), aunque podrían ser adaptadas para recibir entradas dinámicas en futuras versiones.

2. Construcción de Árboles Binarios
El código emplea la clase ArbolBinario para crear árboles binarios a partir de los elementos de ambas listas. Cada número de las listas es insertado en su respectivo árbol (arbolizq para vectorizquierda y arbolderecha para vectorderecha) utilizando el método introducir.

Los árboles binarios permiten organizar los datos de manera jerárquica y eficiente. El proceso de inserción asegura que los datos puedan ser recorridos en orden ascendente más adelante.

3. Ordenamiento de las Listas
Se utiliza un recorrido inorden para obtener las listas ordenadas de ambos árboles binarios. Este recorrido garantiza que los elementos sean procesados en secuencia, desde el más pequeño hasta el más grande.

La clase ArbolBinario implementa este recorrido a través del método in_orden, que utiliza una función recursiva interna para navegar por el árbol y extraer los valores en orden ascendente.

4. Cálculo de la Distancia Total
Una vez obtenidas las listas ordenadas (vectorizquierdaordenada y vectorderechaordenada), el programa calcula la distancia total entre las dos listas. Esto se logra mediante la suma de las diferencias absolutas entre los elementos correspondientes de ambas listas:

distancia total = ∣vectorizquierdaordenada[i]−vectorderechaordenada[i]∣
El resultado de este cálculo representa una medida de la diferencia entre las listas, basada en sus elementos emparejados.
