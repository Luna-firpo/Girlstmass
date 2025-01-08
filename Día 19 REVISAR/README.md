DÍA 19 ADVENT OF CODE PARTE 1

Justificación de la elección del problema

Este problema fue seleccionado porque representa un desafío típico de programación dinámica y búsqueda de cadenas dentro de un conjunto predefinido. Requiere procesar eficientemente una gran cantidad de combinaciones posibles de patrones, lo que lo convierte en un problema interesante en términos de optimización.

Explicación de la solución

Leer los patrones disponibles y almacenarlos en un unordered_set para búsquedas rápidas.
Leer los diseños deseados y comprobar si pueden construirse utilizando los patrones disponibles.
Usar programación dinámica (dp[i]) para verificar si es posible formar cada prefijo del diseño usando los patrones disponibles.

Técnicas utilizadas
Programación Dinámica

Se usa un enfoque de segmentación de cadenas (word break problem).
Se mantiene un vector dp donde dp[i] indica si es posible formar el prefijo de longitud i de la cadena con los patrones disponibles.
Se recorren todas las posiciones i y se intenta emparejar subcadenas con los patrones dados.
Estructuras eficientes

Se usa un unordered_set<string> para almacenar los patrones, permitiendo búsquedas en O(1).
Se usa un vector<bool> dp para almacenar si es posible formar una parte del diseño, evitando recomputaciones innecesarias.
Fragmentación del archivo para optimización

Se procesan fragmentos de líneas en bloques de tamaño FRAGMENT_SIZE = 1000, reduciendo el uso de memoria y mejorando la eficiencia en archivos grandes.
🚧 Dificultades encontradas
Ineficiencia al verificar substrings

Una implementación ingenua con find() para buscar patrones en cada posición de la cadena era demasiado lenta.
Se solucionó utilizando dp[i] y verificando solo los prefijos relevantes.
Problemas con espacios en blanco

Algunas líneas del archivo de entrada tenían espacios adicionales.
Se agregó una función trim() para limpiar las entradas.
Manejo de archivos grandes

Leer todo el archivo en memoria podía causar problemas de rendimiento.
Se implementó un procesamiento por fragmentos para mejorar la eficiencia.
🔍 Alternativas consideradas y descartadas
Backtracking puro

Se probó un enfoque basado en backtracking para generar combinaciones de patrones.
Sin embargo, tenía una complejidad exponencial en el peor caso, por lo que se descartó.
Trie para almacenamiento de patrones

Se consideró usar un Trie para almacenar patrones y buscar prefijos de manera eficiente.
Aunque podía mejorar el tiempo de búsqueda, no se justificaba en este caso debido a la cantidad relativamente pequeña de patrones disponibles.
🤔 Reflexión y aprendizaje
Este problema mostró la importancia de elegir estructuras de datos adecuadas para la búsqueda eficiente de patrones dentro de cadenas. Además, resaltó cómo la programación dinámica puede optimizar problemas de segmentación de cadenas de manera efectiva.

Se aprendió a:

Usar unordered_set para búsquedas rápidas.
Aplicar dp[i] para resolver problemas de partición de cadenas.
Optimizar el manejo de archivos grandes con procesamiento en fragmentos.
