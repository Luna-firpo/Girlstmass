DÍA 10 ADVENT OF CODE

Justificación de la elección del problema

Este problema es interesante porque combina técnicas de búsqueda en grafos con exploración de caminos en una cuadrícula. Es una excelente 
oportunidad para practicar Búsqueda en Profundidad (DFS) y reforzar conceptos de recursión, backtracking y estructuras de datos eficientes. 
Además, es un reto encontrar todos los caminos válidos de manera óptima.

Explicación de cómo se ha resuelto el problema
1. Leer el mapa topográfico desde un archivo (input.txt):
    - Se guarda la información en una matriz (grid), donde cada celda contiene un número
  del 0 al 9.
2. Identificar los "trailheads":
    - Se recorren todas las posiciones de la matriz en busca de celdas con el valor 0, ya que estas son los puntos
  de inicio de los caminos.
3. Explorar caminos desde cada "trailhead":
    - Se usa una función recursiva "explore" que: realiza un DFS para seguir caminos que aumentan de 1
    en 1.
    - Detiene la búsqueda cuando encuentra una celda con valor 9, añadiéndola a un conjunto (reachable_nines).
    - Evita visitar la misma celda dos veces con una matriz "visited".
4. Sumar el número de 9 alcanzables desde cada trailhead:
    - Se usa la función "total_sum" para contar cuántos 9 puede alcanzar cada trailhead sin romper las reglas del problema.
5. Sumar todas las puntuaciones:
    - Se suma la cantidad de 9 alcanzados por cada trailhead y se imprime el resultado final.

Técnicas que se han utilizado
- Búsqueda en Profundidad (DFS): Se ha implementado una exploración recursiva para recorrer caminos válidos en la cuadrícula.
- Backtracking: Se utiliza la matriz "visited" para evitar volver a visitar nodos explorados.
- Uso de un set para almacenar posiciones únicas: Se asegura que cada 9 alcanzado solo se cuente una vez por camino.
- Estructuras dinámicas (vector, set): Se usan vector<vector<int>> para almacenar la cuadrícula y set<pair<int, int>> para evitar duplicados.
- Manejo de archivos (ifstream): Se lee el archivo de entrada y se convierte en una matriz de enteros.

Dificultades encontradas
- Evitar exploraciones infinitas o caminos inválidos: Si no se controlaba bien la condición de parada en la recursión, el algoritmo podía
- entrar en ciclos o seguir caminos incorrectos.
- Manejo de límites en la matriz: Era necesario asegurarse de que los índices (x, y) nunca estuvieran fuera del rango válido.
- Duplicados en la cuenta de 9 alcanzables: Al principio, se podían contar los mismos 9 varias veces si diferentes rutas llegaban a ellos.
  Se solucionó con un set.

Cómo se han ido resolviendo las dificultades
- Control de recursión con condiciones de parada: Se implementó la verificación if (visited[x][y]) return; para evitar ciclos.
- Límites de la matriz bien definidos: Se usó is_valid_position(nx, ny, rows, cols) para verificar si (nx, ny) estaba dentro de los límites.
- Estructura set para evitar contar 9 repetidos: Se guardan los 9 en reachable_nines, asegurando que solo se cuenten una vez.

Alternativas que se consideraron y no funcionaron 
- Usar BFS en lugar de DFS: BFS explora todos los caminos posibles simultáneamente, lo cual hubiera sido más complejo en términos de memoria.
  DFS permite explorar cada camino de manera natural sin necesidad de almacenar todas las rutas en una cola.
- No usar una matriz visited: Sin visited, el código podía entrar en bucles o re-explorar las mismas rutas, aumentando el tiempo de ejecución.
- Almacenar las rutas en lugar de solo contar 9: Aunque hubiera permitido visualizar los caminos, requería más memoria y procesamiento.

Reflexión personal sobre lo que se ha aprendido

Este problema refuerza la importancia de las búsquedas en grafos (DFS/BFS) aplicadas a cuadrículas y la necesidad de estructuras como set 
para evitar duplicados. También demuestra cómo el backtracking y el manejo eficiente de memoria pueden optimizar la solución. Además, el 
trabajo con matrices y lectura de archivos es clave en problemas de análisis de datos.
