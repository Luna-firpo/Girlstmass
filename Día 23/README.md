DÍA 23 ADVENT OF CODE

Justificación de la elección del problema
Este problema fue seleccionado debido a su enfoque en la representación y análisis de grafos, específicamente la detección de triángulos. Además, introduce conceptos de optimización mediante programación dinámica aplicada a subestructuras repetitivas como los triángulos. Este tipo de desafíos combina teoría de grafos con técnicas computacionales avanzadas, haciéndolo ideal para el aprendizaje y desarrollo de habilidades algorítmicas.

Explicación de la solución

- Representación del grafo:
Se utilizó una matriz de adyacencia para modelar el grafo. Esta estructura permite realizar comprobaciones rápidas de conexión entre nodos, esenciales para detectar triángulos.

- Construcción del grafo:
El archivo de entrada contiene líneas que representan aristas entre nodos. Cada nodo se mapeó a un índice único mediante un unordered_map, mientras que las conexiones se reflejaron en la matriz de adyacencia.

- Cálculo de triángulos:
    - Para detectar triángulos, se recorrieron todas las combinaciones de tres nodos (i, j, k) y se verificó si forman un triángulo comprobando si hay aristas entre los tres.
    - Para optimizar este proceso, se aplicó programación dinámica de triángulos, almacenando subestructuras verificadas previamente. Esto se logra reutilizando información sobre pares de nodos conectados en lugar de recalcular para cada triángulo potencial.

- Filtrado adicional:
Además de contar los triángulos totales, se identificaron aquellos que contenían al menos un nodo cuyo nombre empieza con la letra 't'.

Técnicas utilizadas

- Programación dinámica en grafos:
Durante el cálculo de triángulos, se utilizó información previamente calculada sobre pares de nodos conectados para evitar realizar comprobaciones redundantes. Esto permitió reducir el número de operaciones necesarias para encontrar triángulos, especialmente en grafos densos.
- Matrices de adyacencia:
Se emplearon para representar el grafo, optimizando las consultas de conexión entre nodos.
- Mapeo eficiente de nodos:
El uso de un unordered_map para asignar índices únicos a los nodos garantizó un acceso rápido y eficiente.

Dificultades encontradas

- Ineficiencia en grafos grandes:
La búsqueda de triángulos mediante un enfoque de fuerza bruta es costosa en términos de tiempo para grafos grandes. Implementar una optimización basada en programación dinámica ayudó a mitigar este problema.
- Gestión de nombres y conexiones:
Manejar correctamente el formato de las líneas del archivo y garantizar la correcta asignación de nodos al grafo presentó desafíos iniciales.
- Filtrado específico:
Contar únicamente los triángulos con nodos cuyo nombre empieza con 't' añadió una capa adicional de complejidad, ya que requería mantener un control preciso sobre los nodos involucrados en cada triángulo.

Cómo se han ido resolviendo las dificultades

- Optimización con programación dinámica:
En lugar de recalcular todas las conexiones para cada posible triángulo, se reutilizó la información de pares de nodos conectados almacenada en la matriz de adyacencia. Esto permitió reducir significativamente el tiempo de ejecución.
- Procesamiento del archivo:
Se utilizó una lógica clara para dividir las líneas en nombres de nodos y asignarlos correctamente al grafo.
- Manejo del filtrado:
Se añadió una comprobación específica durante la detección de triángulos para identificar si al menos un nodo comenzaba con 't'.

Alternativas consideradas y descartadas

- Enfoque de fuerza bruta completo:
Se probó calcular todos los triángulos desde cero en cada iteración. Aunque funcional, resultaba ineficiente para grafos grandes.
- Uso de listas de adyacencia:
Aunque las listas de adyacencia consumen menos memoria en grafos dispersos, complicaban la lógica de detección de triángulos, por lo que se optó por matrices de adyacencia.
- Algoritmos especializados para conteo de triángulos:
Se consideraron enfoques basados en álgebra lineal (como productos matriciales), pero se descartaron debido a la complejidad adicional que implicaban para este caso.

Reflexión y aprendizaje

Este problema demostró cómo aplicar programación dinámica en grafos para optimizar cálculos repetitivos, como la detección de triángulos. También permitió explorar la representación eficiente de grafos mediante matrices de adyacencia y el mapeo dinámico de nodos.

