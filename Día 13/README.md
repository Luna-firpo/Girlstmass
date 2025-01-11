DÍA 13 ADVENT OF CODE PARTE 1

Justificación de elección del problema

Este problema fue elegido porque involucra varios conceptos clave de optimización y teoría de números, específicamente:
- Resolución de ecuaciones diofánticas lineales: Encontrar combinaciones enteras de presiones de los botones A y B para alcanzar una
    posición exacta.
- Optimización de costos: Buscar la solución válida con el menor número de fichas posibles.
- Estrategia de búsqueda eficiente: Se puede abordar con un enfoque de búsqueda exhaustiva limitada o con algoritmos de teoría de números
  como el método de Euclides extendido.

Además, es un problema realista en videojuegos, robótica y planificación de movimientos.

Explicación de resolución del problema

Cada máquina tiene dos botones:
- Botón A: Mueve la garra (ax, ay) y cuesta 3 tokens.
- Botón B: Mueve la garra (bx, by) y cuesta 1 token.
- Premio: Se encuentra en (px, py), y debemos encontrar nA y nB tal que:

              nA⋅ax + nB⋅bx = px        nA⋅ay + nB⋅by = py
    
El objetivo es encontrar los valores enteros de nA y nB que cumplan ambas ecuaciones y minimicen el costo:

                      Costo = (nA⋅3) + (nB⋅1)

Dado que los valores de nA y nB deben ser enteros positivos, se trata de un problema de ecuaciones diofánticas con restricciones.

Técnicas que se han utilizado
Para resolver el problema, se han empleado las siguientes estrategias:
- Enumeración limitada (Brute Force):
  - Se iteran los valores de nA y nB en un rango razonable (<= 100 intentos), verificando si alcanzan la posición del premio.
  - Se selecciona la combinación con el menor costo.
- División y Conquista (Divide & Conquer):
  - Se dividen los datos en subgrupos y se resuelven en paralelo.
  - La función "values()" procesa de forma recursiva cada máquina para encontrar la mejor combinación de nA y nB.
- Estrategia de costos (Greedy Approach):
  - Se calcula el costo para cada solución posible y se elige la más baja.
  - Manejo eficiente de datos ("unordered_map" y "vector"): Se almacenan y manipulan los datos con estructuras de acceso rápido.

Dificultades encontradas
- Restricción de valores enteros (nA, nB): No siempre existen soluciones enteras, por lo que algunas máquinas no pueden ganar su premio.
- Crecimiento exponencial en la búsqueda de soluciones: La búsqueda exhaustiva (nA, nB <= 100) se vuelve lenta para valores grandes.
- Errores de precisión con números grandes (long long): Los valores de ax, ay, bx, by, px, py pueden ser grandes, requiriendo tipos de datos
  de 64 bits (long long).

Resolución de las dificultades
- Restricción de valores enteros: Se agregaron verificaciones para descartar soluciones inválidas.
- Crecimiento exponencial: Se usó DyV para procesar múltiples máquinas en paralelo.
- Errores de precisión: Se utilizaron tipos de datos adecuados (long long) y cálculos modulares para evitar desbordamientos.

Alternativas/soluciones consideradas y descartadas
- Algoritmo de Euclides extendido: Se consideró para resolver directamente las ecuaciones diofánticas, pero requería demasiadas restricciones
  en nA, nB.
- Programación Dinámica (DP): Se intentó modelar el problema como una mochila (coin change problem), pero los coeficientes no eran constantes.
- Reducción a un problema de grafos (BFS/DFS): Se intentó representar el problema como un grafo donde cada nodo es una posición (x, y), pero
  el espacio de búsqueda era demasiado grande.

Reflexión personal sobre lo aprendido

Este problema ha sido una excelente oportunidad para reforzar conceptos clave en programación de algoritmos:
- El equilibrio entre fuerza bruta y optimización:
- Aunque las ecuaciones pueden resolverse algebraicamente, en este caso, una búsqueda acotada es más eficiente.
- Uso práctico de DyV para mejorar la eficiencia en procesamiento paralelo.
- La necesidad de manejar correctamente datos grandes en C++ (long long, unordered_map).

Este tipo de problemas mejora la capacidad de abstracción y resolución algorítmica, habilidades clave para desafíos más complejos en teoría 
de números y optimización.
