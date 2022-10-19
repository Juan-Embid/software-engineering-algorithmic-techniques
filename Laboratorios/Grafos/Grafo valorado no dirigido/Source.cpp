
/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Valencia Blancas y Juan Embid Sánchez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <tuple>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
/*@ <answer>
  
   Haciendo uso del algoritmo Kruskal hemos mirado la cantidad de 
   subconjuntos que había. De esta manera sabemos que tenemos que 
   poner tantos aeropuertos como número de subconjuntos para que todas 
   las localidades puedan tener acceso a aeropuertos. Comprobamos 
   si el coste de la carretera es mayor que el del aeropuerto para 
   así elegir si contruir aeropuerto o elegir carretera. 
   Para dar el resultado devolvemos el coste de las carreteras más
   la suma del coste de los aeropuertos multiplicado por el número de estos.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

pair<int, int> constAeropuertos(const GrafoValorado<int> g, const int costA) { //O( N * log N)
    PriorityQueue<Arista<int>> pq(g.aristas()); //O(N) Donde n es el número de aristas
    ConjuntosDisjuntos cjd(g.V()); //O(N) N número de localidades
    vector <Arista<int>> arm;
    int aeropuertos = 0;
    int cost = 0;
    while (!pq.empty()) { // Algoritmo de Kruskal
        auto a = pq.top(); // O(1)
        pq.pop(); //O(log A)
        int v = a.uno(), w = a.otro(v);
        if (!cjd.unidos(v, w)) { //O(log * V)
            cjd.unir(v, w); //O(log * V)
            arm.push_back(a);  //O(1)
            if (a.valor() >= costA) {
                aeropuertos++;
            }
            else { // solo elegimos carretera si cuesta menos que hacer el aeropuerto
                cost += a.valor();
            }
            if (arm.size() == g.V() - 1) break;
        }
    }
    aeropuertos += cjd.num_cjtos();
    return { cost+costA*aeropuertos, aeropuertos};
}

bool resuelveCaso() {
   int loc, cam, costA;
   int x, y, costC;
   Arista<int> edge;

   cin >> loc >> cam >> costA;

   if (!std::cin)
       return false;

   GrafoValorado<int> graph(loc);
   for(int i = 0; i < cam; i++) {
      cin >> x >> y >> costC;
      edge = { x - 1,y - 1 , costC};
      graph.ponArista(edge);
   }

 
   cout << constAeropuertos(graph, costA).first << " " << constAeropuertos(graph, costA).second << endl;

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