DÍA 24 ADVENT OF CODE

Justificación de la elección del problema

Este reto se centra en simular un sistema de puertas lógicas, lo cual brinda una excelente oportunidad 
para aplicar técnicas avanzadas de programación, como el uso de tablas hash. Estas estructuras son 
esenciales en este caso, ya que optimizan el manejo de información sobre cables y puertas lógicas, 
evitando el recalculo de valores ya computados, lo que mejora considerablemente el rendimiento global.

Explicación de la solución al problema
1. Leer los valores iniciales desde un archivo (input.txt):
  - Se leen los valores iniciales desde el archivo y se almacenan en una estructura de datos adecuada, en este caso, una tabla hash. La clave de la tabla es el nombre del cable (como x00, y00, etc.), y el valor es el estado de dicho cable (0 o 1). Esta estructura facilita el acceso rápido a los resultados sin tener que volver a calcular los valores de los cables ya procesados.
2. Definir las puertas lógicas:
  - El sistema se basa en operaciones booleanas (AND, OR, XOR), cada una de las cuales depende de los 
  valores de los cables de entrada. Las puertas lógicas tienen dos entradas y una salida. La salida se 
  escribe en un cable de salida y su valor depende de la operación lógica aplicada a las entradas. Las 
  instrucciones de estas operaciones se encuentran en el archivo, por ejemplo: x01 OR y00 -> z00.
3. Evaluar las operaciones lógicas:
  - Tras leer los valores iniciales, se comienza a realizar las operaciones lógicas. Si ambas entradas 
  de una puerta lógica ya tienen un valor calculado (es decir, están presentes en la tabla hash), se 
  puede realizar la operación y obtener el valor de salida. Si alguna entrada aún no tiene valor, el 
  cálculo se aplaza y se resuelve de forma recursiva.
4. Almacenar los resultados en la tabla hash:
  - Cada vez que se calcula una salida, se guarda en la tabla hash bajo la clave correspondiente al 
  cable de salida, con el valor recién calculado, para poder usarlo más tarde si es necesario.
5. Calcular hasta obtener todos los resultados:
  - El proceso continúa evaluando todas las puertas lógicas hasta que se hayan calculado todos los 
  valores necesarios para las salidas.
6. Obtener el valor final:
  - Cuando todos los valores de los cables han sido calculados, se genera un número binario concatenando
  los valores de todos los cables de salida que comienzan con la letra "z" (como z00, z01, z02, etc.). 
  Este número binario se convierte a su equivalente decimal y se muestra como resultado.

Técnicas utilizadas
  - Tablas Hash: El uso de tablas hash (específicamente con unordered_map) permite almacenar los 
	resultados de las puertas lógicas y los valores de los cables de forma eficiente. Esto elimina la 
	necesidad de recalcular valores ya obtenidos, mejorando el rendimiento en simulaciones de sistemas 
	grandes y complejos.
  - Recursión: Se utiliza recursión para evaluar las puertas lógicas en el orden correcto, lo que
	facilita el cálculo de los valores de cada cable sin tener que iterar sobre todos los cables de 
	manera redundante.
  - Operaciones Booleanas: Las puertas lógicas (AND, OR, XOR) se implementan como funciones lambda, 
	integrándose de manera limpia y eficiente dentro del algoritmo.

Desafíos enfrentados

Uno de los principales problemas fue gestionar las dependencias entre cables, específicamente cuando 
algunos cables dependían de otros que aún no tenían un valor calculado. Sin embargo, al utilizar tablas
hash,este problema se resolvió eficazmente, ya que los resultados intermedios se almacenaron y 
reutilizaron. Y otro problema fue a la hora de leer el fichero para guardar los valores que leía.

Soluciones aplicadas

El uso de tablas hash no solo solucionó el problema de dependencias entre cables, sino que también
mejoró la eficiencia al evitar cálculos innecesarios. Esto permitió que el código pudiera manejar 
fácilmente las combinaciones de puertas lógicas más complejas y realizar la evaluación en un tiempo 
mucho menor.

Alternativas

- Uso de fuerza bruta: en vez de usar recursividad, se probarían todas las opciones, aunque su coste
sería mucho mayor.
- Uso de grafos: se podría modelar las conexiones entre los cables y puertas lógicas como un grafo
dirigido, donde los cables son los nodos y las puertas lógicas son las aristas.

Reflexión sobre lo aprendido

Este ejercicio ha sido muy útil para entender cómo las tablas hash pueden ser utilizadas en problemas 
complejos de simulación, especialmente cuando se tienen múltiples dependencias y resultados intermedios.
Además, nos ha permitido reforzar el uso de recursión, de las tablas hash y de leer información de
ficheros.
