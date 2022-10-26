
/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Valencia Blancas y Juan Embid Sánchez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
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
 

//Lectura: O(P) siendo P el número de caminos entre las celdas (aristas).
//Calcular el grafo inverso: O(N+P) siendo N el número de celdas.
//Función resolver(): O(PlogN)
 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }

    bool hayCamino(int v) const { return dist[v] != INF; }

    Valor distancia(int v) const { return dist[v]; }


private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso() {
    // N celdas | S salida | T tiempo | P pasadizos
    int N, S, T, P, A, B, tiempo;
    int contRatones = 0, dist = 0;
    bool cam = false;
    cin >> N >> S >> T >> P;
    if (!std::cin)
        return false;
    DigrafoValorado<int> d(N);
    for (int i = 0; i < P; i++) {
        cin >> A >> B >> tiempo;
        d.ponArista(AristaDirigida<int>(B - 1, A - 1, tiempo));
    }
    
    Dijkstra<int> di(d, S - 1);
    for(int i = 0; i < N; i++) {
        cam = di.hayCamino(i);
        dist = di.distancia(i);
        if (cam && dist <= T) { ++contRatones; }
    }
    cout << contRatones - 1 << "\n";
    
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
