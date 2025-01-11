DÍA 12 ADVENT OF CODE

Justificación de la elección del problema
El problema fue escogido ya que utiliza la técnica de búsqueda en grafos y exploración de regiones dentro de una cuadrícula. Además, se puede poner en práctica el uso de la búsqueda en profundidad(DFS), recursión, y utilización y manejo de estructuras de datos como matrices.

Explicación de cómo se ha resuelto el problema
1. Lectura del mapa
  -El primer paso fue leer el mapa a partir de un archivo de entrada (fichero_dia12.txt) almacenando los datos leídos en una matriz bidimensional.
2. Identificación de las diferentes regiones
  -Se recorrió la matriz para encontrar las regiones que aún no habían sido visitadas y que eran parte de una planta (indicadas por letras mayúsculas).
3. Exploración de cada región
  -Para cada celda que no se ha visitado con anterioridad, se llama a una función recursiva que realiza un DFS para recorrer todas las celdas alrededor de esa.
4. Cálculo del área y perímetro
  -Mientras se recorren las celdas se calcula el área (contando las celdas visitadas iguales) y el perímetro(contando las adyacentes).
5. Cálculo final
  -Se calcula el precio total sumando el área * perímetro de todas las regiones.

Técnicas que se han utilizado
-DFS(Búsqueda en profundidad): para explorar en todas las celdas de cada región y evitar recorrer las mismas.
-Recursividad: recorrido de las celdas adyacentes de cada región.
-Estructuras de datos: se usaron vectores(matriz) para almacenar las celdas visitadas.

Dificultades encontradas
-Manejo de bordes: La principal dificultad fue asegurarse de que el perímetro de una región se calculara correctamente cuando la celda estaba en el borde del mapa o tocaba una celda fuera de la región.
-Recursividad: Había que evitar bucles infinitos o volver a procesar celdas ya visitadas, lo cual requería un manejo cuidadoso de las condiciones de parada.

Cómo se han ido resolviendo las dificultades
-Manejo de los bordes: Se implementaron verificaciones dentro de la función recursiva para comprobar si una celda adyacente se encontraba dentro de los límites del mapa antes de proceder con la exploración.
-Control de la recursión: Se utilizó una matriz de visitados para asegurar que cada celda se procesara una sola vez y evitar ciclos infinitos.

Alternativas que se consideraron y no funcionaron
-Usasr fuerza bruta: sería una solución poco óptima ya que calcularía cálculos ya solucionados múltiples veces.
-Usar BFS: aunque podría haber sido otra opción, se optó por DFS al ser más sencillo a la hora de recorrer celdas de manera recursiva sin necesidad de utilizar colas.

Reflexión personal sobre lo que se ha aprendido
Este ejercicio se ha utilizado para practicar y profundizar en la técnica de búsqueda en grafos, específicamente en DFS, en problema de exploración de mapas. Se ha aprendido a usar mejor las estructuras como matrices y vectores. Además, el uso de la recursión en este problema ha sido clave a la hora de optimizarlo.
