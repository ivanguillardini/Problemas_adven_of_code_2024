# Problema Día 23: LAN Party

## Descripción del Problema

En este problema, se nos da una lista con todas las conexiones entre dos ordenadores o computadores. Cada línea de la entrada por ejemplo kh-tc  representa una conexión directa entre dos ordenadores en este casp kh y tc. El objetivo es encontrar grupos de tres ordenadores que estén  interconectados es decir que forme un triángulo en el grafo. 

Y nos dicen que el  Historiador Jefe probablemente esté en la fiesta de LAN y sabemos que su ordenador empieza con la letra `t`, nos interesa contar únicamente los triángulos que contengan al menos un ordenador cuyo nombre comience con `t` y el numero de triángulos que contengan al menos un ordenadir que empiece por la 't' es la solución al problema.

### Ejemplo de Entrada

```
kh-tc
qp-kh
de-cg
ka-co
yn-aq
qp-ub
cg-tb
vc-aq
tb-ka
wh-tc
yn-cg
kh-ub
ta-co
de-co
tc-td
tb-wq
wh-td
ta-ka
td-qp
aq-cg
wq-ub
ub-vc
de-ta
wq-aq
wq-vc
wh-yn
ka-de
kh-ta
co-tc
wh-qp
tb-vc
td-yn
fin
```

### Ejemplo de Salida

En este caso, los triángulos formados por tres ordenadores interconectados son 12, y como de estos solo 7 contienen al menos un ordenador que comienza con `t` la solución es 7.

```
Número de triángulos con al menos una computadora que comienza con 't': 7
```

---

## Solución a este Problema

La solución de este problema utiliza conceptos y estructuras de grafos para representar y procesar la red de conexiones. El enfoque principal se basa en encontrar "ciclos" de tamaño 3 o triángulos dentro del grafo creado gracias a lista de conexiones entre dos ordenadores que ha sido proporcionado por la entrada.

### Representación del Grafo

El grafo se representa mediante una estructura de tipo `map` donde:
- La clave es el nombre de un ordenador (nodo).
- El valor asociado a la clave es un conjunto que contiene los nombres de los ordenadores directamente conectados a dicho nodo (vecinos).

Esto nos permite un acceso eficiente para verificar conexiones entre nodos y explorar vecinos.

### Identificación de Triángulos

Se define un triángulo como un conjunto de tres nodos conectados entre sí. Para identificar estos triángulos:
1. Para cada nodo en el grafo, se exploran sus vecinos directos.
2. Para cada par de vecinos, se verifica si existe una conexión directa entre ellos.
3. Si los tres nodos están conectados entre sí, se considera que forman un triángulo.

### Conrar los Triángulos con Ordenadores que Comienzan con `t`

Una vez identificados los triángulos, se realiza un filtrado para contar únicamente aquellos que contienen al menos un ordenador(nodo) cuyo nombre comienza con la letra `t`. Esto se logra inspeccionando los nombres de los ordenadores(nodos) en cada triángulo y verificando su condición.

---

## Técnicas y Algoritmos Utilizados

1. **Representación de Grafos con Mapas y Conjuntos**:
   - Se utiliza una estructura basada en mapas (`map`) y conjuntos (`set`) para representar las conexiones bidireccionales de forma eficiente.

2. **Iteración y Comparación Eficiente**:
   - Para evitar redundancia y asegurar que cada triángulo se cuenta una sola vez, se emplea un orden estricto en la comparación de nodos (por ejemplo, `vecino1 > nodo_actual` y `vecino2 > vecino1`). Esto garantiza que cada triángulo se detecta de forma única.

3. **Verificación de Vecindad**:
   - El uso de conjuntos permite verificar rápidamente si un nodo está conectado a otro mediante operaciones como `grafo.at(vecino1).count(vecino2)`.

4. **Filtrado con Condición**:
   - Se recorre cada triángulo identificado y se verifica si alguno de sus nodos cumple la condición de comenzar con `t`.

---



