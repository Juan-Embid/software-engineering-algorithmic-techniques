/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

/*@ <answer>
 *
 * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
 * Estudiante 1: Alejandro Valencia Blancas
 * Estudiante 2: Juan Embid Sánchez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
#include "Grafo.h"

using namespace std;


/*@ <answer>
 
Primero llenamos el vector de oro con coste lineal. En el segundo for ponemos las aristas en el grafo para saber cómo es. Este segundo for
también es de coste lineal ya que la función solo tiene dos push_back de un vector. Después inicializamos un vector de tamaño N  con falses
para después indicar qué posiciones del vector visitamos. En el siguiente for comprobamos si no hemos visitado esa posición del grafo y hacemos 
una búsqueda en profundidad donde encontramos el valor mínimo de cada camino. El coste de esta búsqueda es de O(N + M) donde N son nodos y M aristas.
El coste total del programa es O(N + M); :)-()=
 @ </answer> */                            


// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>

void dfs(Grafo const& g, int v, vector<bool>& visit, int &min, vector<int>& oro) {
  visit[v] = true;
  if (oro[v] < min) min = oro[v];
  for(int w : g.ady(v)) {
    if(!visit[w]) {
      dfs(g, w, visit, min, oro);
    }
  }
}

bool resuelveCaso() {
  // N personas
  // M pares de amigos
    vector<int> oro;
    int N, M, aris, aris1, temp, totalprice = 0;
    cin >> N >> M;
   
    if (!cin)
      return false;

    Grafo rumor(N);
    for (int i = 0; i < N; i++){ //O(n)
        cin >> temp;
        oro.push_back(temp);
    }
    for(int j = 0; j < M; j++) { //O(n)
        cin >> aris >> aris1;
        rumor.ponArista(aris - 1, aris1 - 1);
    }
    vector<bool> visit(N, false);
    int min = 10000;
   for (int i = 0; i < N; i++) { // O(N + M) donde N son nodos y M aristas
        if (!visit[i]) {
            dfs(rumor, i, visit, min, oro);
            totalprice += min;
        }
        min = 10000;
    }
    cout << totalprice << "\n"; 

  return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
  // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  // Resolvemos
  while (resuelveCaso());
  
  // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}
