DÍA 7 ADVENT OF CODE PARTE 1 

Justificación de elección del problema

Este problema es interesante porque requiere explorar todas las combinaciones posibles de operadores (+ y *) en una secuencia de números dada. Es una excelente oportunidad para practicar backtracking, recursión y la evaluación de expresiones bajo reglas no convencionales (evaluación estrictamente de izquierda a derecha, sin precedencia de operadores).

Explicación de resoludión del problema
1. Leer y procesar el archivo de entrada ("input.txt")
    - Cada línea contiene un número objetivo seguido de una lista de números separados por espacios.
    - Se divide la línea en:
      - "target": el número antes del :.
      - "nums": los números después del :.
    
2. Evaluar todas las combinaciones posibles de operadores
    - Se implementa una función recursiva evaluate_tree que explora todas las combinaciones de + y * entre los números de nums.
    - La evaluación de la expresión se realiza estrictamente de izquierda a derecha.
  
3. Comprobación de validez
    - Si al final de la exploración se obtiene "target", la ecuación es válida.
    - Se suma "target" al resultado final si la ecuación es válida.
  
4. Impresión del resultado total
    - Se imprime la suma de todos los valores objetivos (target) de las ecuaciones que pueden ser verificadas correctamente.

Técnicas que se han utilizado
- Backtracking (árbol de decisiones): Se usa recursión para probar todas las combinaciones posibles de operadores en cada ecuación.
- Recursión: La función "evaluate_tree" recorre todas las posibles evaluaciones de la ecuación.
- Manejo de archivos (ifstream): Se lee el archivo línea por línea y se procesa con "stringstream".
- Conversión de strings a números (stoll): Se convierte cada número leído desde el archivo en un long long para soportar valores grandes.

Dificultades encontradas
- Evaluación estrictamente de izquierda a derecha: No se puede usar la precedencia estándar de operadores (* antes de +). Se debe evaluar en el mismo orden en que aparecen los números.
- Manejo de valores grandes: Algunos cálculos pueden desbordar tipos de datos pequeños como int. Se solucionó usando long long.
- Explosión combinatoria en la recursión: Para n números, hay 2^(n-1) posibles combinaciones de operadores. Se debe optimizar evitando cálculos innecesarios.

Cómo se han ido resolviendo las dificultades
- Manejo correcto de la evaluación izquierda a derecha: Se pasó el resultado actual acumulado en la recursión en lugar de construir una expresión completa.
- Uso de long long para evitar desbordamientos: Se aseguró que todos los cálculos usaran tipos de datos de mayor capacidad.
- Pruning en la búsqueda recursiva: Se evitó continuar explorando si el resultado actual ya excedía el target.

Alternativas que se consideraron y no funcionaron
- Evaluar todas las permutaciones de operadores con eval(): No funcionó porque eval() respeta la precedencia de operadores, mientras que el problema requiere evaluación estrictamente de izquierda a derecha.
- Usar un enfoque de BFS en lugar de DFS: BFS es menos eficiente aquí porque requiere almacenar muchas expresiones parciales en la cola, lo que aumenta el consumo de memoria.
- Generar todas las expresiones como cadenas y evaluar: Ineficiente porque requería construir y analizar demasiadas cadenas.

Reflexión personal sobre lo que se ha aprendido

Este problema es un gran ejercicio de backtracking y evaluación de expresiones. Me enseñó la importancia de orden de evaluación, cómo manejar combinaciones de operadores en secuencias de números y cómo optimizar exploraciones recursivas con pruning.

Lecciones clave:

Evaluación de expresiones sin precedencia estándar puede requerir enfoques específicos.
Recursión y backtracking son esenciales en problemas con combinaciones de operadores.
Optimizar la búsqueda con poda evita evaluaciones innecesarias y mejora el rendimiento.
