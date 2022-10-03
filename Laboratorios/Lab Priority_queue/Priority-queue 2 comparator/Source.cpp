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
#include <vector>
using namespace std;


const int MAX_PARTITURAS = 200000;
const int MAX_ORQUESTA = 100000;
const int MAX_MUSICOS = 1000;

/*@ <answer>
 
Para resolver el problema usamos un comparator para ordenar nuestra cola donde distinguimos la division entre 
los músicos y las partituras en caso de que tenga resto o no. De esta manera
ordenamos la priority_queue con este comparator. Con esto conseguimos hallar el 
mayor grupo de instrumentos. 
El coste es O(N * log (N)) donde N es la diferencia entre partituras e instrumentos.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>

struct orchest {
    int musicos;
    int partituras;
};

struct comp_orch {
    bool operator()(orchest const& a, orchest const& b) {
        int i = 0, i2 = 0;
        if (a.musicos % a.partituras > 0) { i = 1; }
        if (b.musicos % b.partituras > 0) { i2 = 1; }
        return (a.musicos / a.partituras) + i < (b.musicos / b.partituras) + i2;
    }
};

bool resuelveCaso() {
  
  // leemos la entrada
   int P, N, temp;
   vector<int> instrumentos;
   orchest par;
   priority_queue<orchest, vector<orchest>, comp_orch> cola;
   cin >> P >> N;
   
   if (!cin)
      return false;
    
   
       for(int i = 0; i < N; i++){ // O(N * log(N))
            cin >> temp;
            cola.push({ temp, 1 }); // O(logn)
        }
        P -= N;
        
        while (P > 0) { // O(N * logN)
            par = cola.top();//O(1)
            par.partituras++;
            cola.pop(); //O(logN)
            cola.push(par); //O(logN)
            P--;
   }
        if (cola.top().musicos % cola.top().partituras > 0) { 
            cout << (cola.top().musicos / cola.top().partituras) + 1 << "\n"; //O(1)
        }
        else {
            cout << (cola.top().musicos / cola.top().partituras) << "\n"; //O(1)
        }
   

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
