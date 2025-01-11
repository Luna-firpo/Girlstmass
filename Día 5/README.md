DÍA 5 ADVENT OF CODE 

Justificación de la elección del problema 

Este problema fue seleccionado porque representa un desafío interesante en la manipulación de grafos y validación de órdenes en listas de nodos. Trabajar con grafos, específicamente listas de adyacencia, es una técnica esencial en algoritmos y estructuras de datos. 

Explicación de la solución 

- Construcción del grafo 

Se utilizó una lista de adyacencia representada mediante un map<int, vector<int>> para almacenar las conexiones entre nodos. Cada línea del archivo que contenía una conexión se procesó y añadió al grafo mediante un método específico. 

- Validación de órdenes 

Las líneas que no representaban conexiones fueron interpretadas como listas de nodos. Para estas listas, se implementó una función que verificaba si el orden era válido, asegurándose de que ningún nodo procesado tuviera vecinos ya visitados. Esto se logró utilizando un conjunto (set) para llevar el control de los nodos procesados. 

- Cálculo de la solución final 

Si el orden de una lista de nodos era válido, se seleccionaba el nodo central de la lista y se sumaba a una variable que acumulaba la solución total. 

Técnicas utilizadas 

- Representación de grafos con listas de adyacencia: Se usó un mapa con vectores para almacenar las conexiones de manera eficiente, especialmente útil para grafos dispersos. 

- Conjuntos (set) para control de nodos procesados: Esta estructura permitió realizar búsquedas rápidas y evitar duplicados al verificar si un nodo ya había sido procesado. 

- Manejo de archivos: Se usaron flujos de entrada (ifstream) para procesar línea por línea el archivo de entrada, manejando de manera eficiente los datos proporcionados. 

Dificultades encontradas 

- Parsing del archivo: Identificar correctamente si una línea representaba una conexión o una lista de nodos requería un manejo preciso del formato, especialmente cuando había líneas vacías o con datos no válidos. 

- Validación de órdenes en listas de nodos: Diseñar una lógica eficiente para verificar que ningún vecino procesado estuviera en conflicto con el nodo actual fue un desafío. 

- Manejo de bordes en grafos dispersos: Las conexiones incompletas o nodos aislados podían causar errores si no se verificaban adecuadamente. 

Cómo se han ido resolviendo las dificultades 

- Parsing del archivo: Se añadieron condiciones para filtrar líneas vacías o mal formateadas y separar correctamente los números y delimitadores en cada línea. 

- Validación de órdenes: Se utilizó un conjunto para mantener un registro de los nodos ya procesados, lo que permitió realizar verificaciones rápidas y evitar conflictos de manera eficiente. 

- Gestión de bordes: Se implementaron verificaciones adicionales para manejar casos donde los nodos no tenían vecinos o las conexiones eran incompletas. 

Alternativas consideradas y descartadas 

- Uso de una matriz de adyacencia: Aunque esta estructura permite representar grafos de manera directa, fue descartada debido a su alto consumo de memoria para grafos dispersos. 

- Procesamiento secuencial sin estructuras adicionales: Se consideró trabajar directamente sobre las listas de nodos sin un conjunto para controlar los nodos procesados, pero esto habría aumentado la complejidad del código y el tiempo de ejecución. 

Reflexión y aprendizaje 

Este problema permitió reforzar conocimientos sobre la representación y manipulación de grafos mediante listas de adyacencia, así como trabajar con técnicas de validación de órdenes y gestión de dependencias.  

 
