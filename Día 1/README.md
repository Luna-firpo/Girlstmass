DÍA 1 ADVENT OF CODE
JUSTIFICACIÓN DE LA ELECCIÓN DEL PROBLEMA

Este problema se ha elegido porque introduce conceptos clave de ordenación y cálculo de diferencias absolutas, fundamentales en 
algoritmos de procesamiento de datos. Además, es un buen ejercicio para aplicar técnicas de "Divide y Vencerás" mediante Merge Sort,
lo que permite reforzar la comprensión de algoritmos eficientes de ordenación.

EXPLICACIÓN DE LA RESOLUCIÓN DEL PROBLEMA
- Lectura de Datos: Se lee el archivo de entrada input.txt, donde cada línea contiene dos números. Estos números se almacenan en dos 
  vectores(v1 y v2).
- Ordenación: Se ordenan ambas listas utilizando el algoritmo Merge Sort para asegurarse de que los elementos sean emparejados correctamente.
- Cálculo de la Suma de Diferencias: Se recorren ambas listas, ya ordenadas, y se calcula la diferencia absoluta entre los elementos en la
  misma posición.
- Salida de Resultados: Se imprimen los pares emparejados junto con su diferencia y se muestra la suma total.

TÉCNICAS EMPLEADAS

Algoritmo de Ordenación Merge Sort: Se implementa este algoritmo de tipo DyV para ordenar ambas listas de manera eficiente. 
Manejo de Archivos: Se usa ifstream para leer los datos desde un archivo de entrada.
Uso de vector<int>: Se emplean estructuras de datos dinámicas para almacenar los números de manera eficiente.
Recorrido Lineal: para calcular la suma de diferencias absolutas una vez ordenadas las listas.

DIFICULTADES
- Manejo de Archivos: Leer correctamente los datos y asegurarse de que se procesan sin errores.
- Implementación de Merge Sort: Aunque es un algoritmo estándar, implementarlo correctamente con estructuras dinámicas como vector<int> puede
  generar errores si no se manejan bien los índices.
- Emparejamiento Correcto: Era fundamental asegurarse de que los números se emparejaban correctamente después de ordenar ambas listas.

Resolución a las dificultades anteriores
- Lectura de Archivos: Se usó ifstream y stringstream para extraer los valores de cada línea sin depender de formatos específicos.
- Corrección de Merge Sort: Se verificaron los índices y los casos base para garantizar que la implementación no generara errores fuera de rango.
- Verificación Manual de Emparejamiento: Se imprimieron los pares antes de calcular la suma para comprobar que la lógica era correcta.

Alternativas/soluciones que se han ido considerando y no funcionaban
- Uso de sort() en lugar de Merge Sort: Aunque std::sort() es más corto de escribir, el objetivo era practicar un algoritmo de ordenación
  basado en "Divide y Vencerás".
- Ordenación Parcialmente Manual: Intentar ordenar cada lista mientras se leía el archivo hubiera sido más complejo y menos eficiente.
- Emparejamiento sin Ordenar: Si se sumaran las diferencias sin ordenar, los resultados serían inconsistentes y la solución incorrecta.

REFLEXIÓN SOBRE LO APRENDIDO

Este problema ha servido para reforzar la importancia de la ordenación previa cuando se trabaja con listas que deben compararse elemento
a elemento. También ha permitido mejorar la implementación de Merge Sort y comprender cómo aplicar "Divide y Vencerás" en problemas prácticos. 
Además, se ha trabajado con la lectura de archivos y el manejo de datos en estructuras dinámicas.
