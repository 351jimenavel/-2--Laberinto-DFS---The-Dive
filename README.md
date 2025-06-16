# -2---Laberinto-DFS---The-Dive
# Laberinto Generado y Resuelto con Algoritmos de Búsqueda

## ¿Cómo generé el laberinto?

El laberinto se genera usando el algoritmo **DFS (Depth-First Search)**, también conocido como **búsqueda en profundidad**.  
Se parte desde la celda de entrada (0, 0) y se expande recursivamente hacia direcciones aleatorias, marcando caminos abiertos ('-') y rompiendo muros intermedios.

Este enfoque garantiza que el laberinto sea resoluble:  
- Se visita cada celda alcanzable una sola vez.  
- Se crea un único camino posible entre la entrada y la salida.

---

## ¿Qué algoritmo usé para resolverlo?

Para resolver el laberinto también utilicé **DFS**, pero adaptado para moverse una celda a la vez.

- Se comienza en la celda de entrada 'E'.
- Se exploran las direcciones posibles por caminos abiertos ('-') hasta encontrar la salida 'S'.
- Si se llega a un callejón sin salida, se **retrocede (backtracking)** y se intenta otra dirección.
- Las celdas del camino correcto se marcan con una 'x'.

---

## ¿Qué haría distinto la próxima vez?

- Probaría con **BFS (Breadth-First Search)** para resolver el laberinto, ya que este encuentra el **camino más corto**, a diferencia de DFS que no garantiza una solución óptima.
- Implementaría una **visualización paso a paso** para analizar mejor el rendimiento y las decisiones del algoritmo.
- Mediría los tiempos de ejecución con mayor precisión usando la librería chrono de C++ para comparar el desempeño entre DFS y BFS bajo las mismas condiciones.

---

## Extras (si querés agregar):
📌 Lenguaje utilizado: C++  
📌 Técnicas aplicadas: recursión, vectores de vectores, generación aleatoria, estructuras de control, backtracking 

