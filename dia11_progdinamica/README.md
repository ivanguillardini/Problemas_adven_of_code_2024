
# AdventCode Day11 Programación Dinamica
# Descripción del Ejercicio con Programación Dinámica
El programa presentado utiliza programación dinámica para procesar y simular una transformación sobre un conjunto inicial de "piedras". Estas transformaciones se realizan de forma iterativa durante un número definido de "parpadeos". La memorización se emplea para evitar cálculos repetidos y optimizar el rendimiento.
# Solucion Implementada
He elegido el dia11 para representar como se puede realizar un ejercicio con memorizacion utilizando la programación dinamica, en la estructura del código explico como se utiliza

# Estructura del Código
1. Entrada de Datos
El programa inicializa un conjunto de "piedras" representado como un vector de números enteros (piedras = {337, 42493, 1891760, 351136, 2, 6932, 73, 0}).
Define el número de "parpadeos" como una variable (parpadeos = 75).
2. Uso de Programación Dinámica
La memorización se implementa utilizando un unordered_map llamado memoria. Este mapa almacena resultados previamente calculados para evitar realizar los mismos cálculos en futuras iteraciones:

Clave: El número de la piedra que se está procesando.
Valor: El resultado de dividir o transformar la piedra.
Esto reduce significativamente la complejidad del programa cuando se procesan piedras repetidas.

3. Procesamiento de Piedras
La lógica principal para procesar cada piedra se define en la función procesarPiedra. Esta función transforma una piedra en base a ciertas reglas:

Si la piedra ya ha sido procesada, se devuelve el resultado almacenado en memoria.
Reglas de transformación:
Si la piedra es 0, se transforma en 1.
Si el número de dígitos de la piedra es par, se divide en dos mitades (usando la función dividirNumero).
Si el número de dígitos de la piedra es impar, se multiplica por 2024.
El resultado se guarda en memoria para futuras consultas.

4. Simulación de Parpadeos
La función simular realiza iteraciones sobre el conjunto de piedras durante el número de "parpadeos" especificado. En cada iteración:

Se inicializa un vector vacío para almacenar las nuevas piedras generadas.
Cada piedra del conjunto actual se procesa usando la función procesarPiedra, y las partes generadas se agregan al nuevo conjunto de piedras.
Después de cada parpadeo, el conjunto de piedras se actualiza con las nuevas piedras generadas.
El valor final devuelto por simular es el número total de piedras después de todos los parpadeos.
