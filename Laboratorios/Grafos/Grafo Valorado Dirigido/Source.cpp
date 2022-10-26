
/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Valencia Blancas y Juan Embid Sánchez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "IndexPQ.h"
#include "DigrafoValorado.h"

using namespace std;


/*@ <answer>

 Para el problema de ratones en un laberinto nos dan un número N de celdas
 y un número P de pasadizos. Las celdas en nuestro caso serán los vértices
 y los pasadizos las aristas. 

 Para resolver el problema usamos el algoritmo Dijkstra relajando las aristas.
 Como queremos hayar el tiempo mínimo hasta un origen desde todas 
 las celdas, tendremos que dar la vuelta a todas las aristas del grafo
 y poner como origen el final. De esta menera con un contador (sin tener en cuenta el origen)
 aumentamos cada vez que existe un camino y cumple que es menor que el 
 tiempo.


 

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

//Lectura: O(P) siendo P el número de caminos entre las celdas (aristas).
//Calcular el grafo inverso: O(N+P) siendo N el número de celdas.
//Función resolver(): O(PlogN)

void relajar(AristaDirigida<int> a,  vector<int>& dist, IndexPQ<int>& pq) {
    int v = a.desde(), w = a.hasta();
    if (dist[w] > dist[v] + a.valor()) {
        dist[w] = dist[v] + a.valor(); 
        pq.update(w, dist[w]);
    }
}

int resolver(DigrafoValorado<int> const& g, const int T, int origen) {
    int ratones = 0;
    vector<int> dist(g.V(), 2000000); // 
    IndexPQ<int> pq(g.V());
    dist[origen] = 0;
    pq.push(origen, 0);
    
    while (!pq.empty()) {
        int v = pq.top().elem; pq.pop();
        for (auto a : g.ady(v))
            relajar(a, dist, pq);
    }
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] <= T && i != origen) ratones++;
    }
    return ratones;
}

bool resuelveCaso() {
    // N celdas | S salida | T tiempo | P pasadizos
    int N, S, T, P, A, B, C;
    int contRatones = 0, dist = 0;
    bool cam = false;
    cin >> N >> S >> T >> P;
    if (!std::cin)
        return false;
    DigrafoValorado<int> d(N);
    for (int i = 0; i < P; i++) {
        cin >> A >> B >> C;
        d.ponArista(AristaDirigida<int>(A - 1, B - 1, C));
    }
    
    cout << resolver(d.inverso(), T, S - 1) << "\n";
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

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
