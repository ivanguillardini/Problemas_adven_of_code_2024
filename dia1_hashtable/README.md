
# Advent of Code Ej1 -- Tablas Hash

## Descripción del Programa
El problema se centra en resolver la discrepancia entre dos listas de números, que representan los IDs de las ubicaciones donde podría encontrarse el historiador jefe. Estas listas son proporcionadas por dos grupos de historiadores, y aunque cada lista contiene números únicos, no coinciden entre sí. El objetivo es encontar las distancia entre las listas.

Para ello, usaremos este programa en C++ permite calcular la distancia total entre dos listas de números enteros ingresadas por el usuario. Utiliza tablas hash para optimizar la búsqueda y emparejamiento de los números en ambas listas, minimizando la distancia total entre ellos mediante un algoritmo eficiente de ordenamiento y emparejamiento.

El objetivo del programa es sumar las diferencias absolutas entre los números de ambas listas, considerando sus frecuencias y emparejándolos en orden ascendente.

## Funcionalidad del Programa

1. **Entrada de Datos**:
   - El programa solicita al usuario que ingrese los elementos de dos listas: izquierda y derecha.
   - Se especifica el número de elementos en cada lista y luego los valores correspondientes.

2. **Procesamiento de Datos**:
   - Las frecuencias de los números en ambas listas se almacenan en tablas hash (`std::unordered_map`).
   - Se extraen y ordenan las claves (números únicos) de ambas tablas hash para realizar un emparejamiento eficiente.
   - Se calculan las distancias absolutas entre los números emparejados y se multiplica por la frecuencia mínima entre ambos.

3. **Salida de Datos**:
   - El programa imprime la distancia total calculada entre las dos listas.

## Estructura del Código

### Entrada de Datos
El programa utiliza vectores para almacenar los datos ingresados por el usuario:
```cpp
std::vector<int> izquierda;
std::vector<int> derecha;
```
El usuario ingresa el número de elementos de cada lista y los valores correspondientes:
```cpp
std::cout << "Ingrese el número de elementos para la lista izquierda: ";
std::cin >> n;
std::cout << "Ingrese los elementos de la lista izquierda: \n";
```

### Cálculo de Distancia Total
1. **Contar Frecuencias**:
   - Se usa `std::unordered_map` para contar las ocurrencias de cada número en ambas listas.

2. **Ordenar las Claves**:
   - Las claves únicas de ambas tablas hash se ordenan en orden ascendente:
   ```cpp
   std::sort(clavesIzquierda.begin(), clavesIzquierda.end());
   std::sort(clavesDerecha.begin(), clavesDerecha.end());
   ```

3. **Emparejar y Calcular Distancias**:
   - Se emparejan los números más pequeños de ambas listas iterativamente y se calculan las distancias absolutas:
   ```cpp
   distanciaTotal += distancia * minimoFrecuencia;
   ```

### Salida de Datos
El resultado final se imprime en pantalla:
```cpp
std::cout << "La distancia total entre las listas es: " << distancia << std::endl;
```

## Ejemplo de Ejecución

### Entrada:
```bash
Ingrese el número de elementos para la lista izquierda: 6
Ingrese los elementos de la lista izquierda: 
3 4 2 1 3 3
Ingrese el número de elementos para la lista derecha: 6
Ingrese los elementos de la lista derecha: 
4 3 5 3 9 3
```

### Salida:
```bash
La distancia total entre las listas es: 11
```

## Notas
- Este programa es eficiente incluso con listas grandes gracias al uso de tablas hash.
- Los números deben ser enteros.
- La entrada de datos es validada solo superficialmente; se asume que el usuario proporciona datos válidos.


