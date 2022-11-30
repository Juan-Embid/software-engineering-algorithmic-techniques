
/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Valencia Blancas y Juan Embid Sánchez
 *
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"
using namespace std;

/*@ <answer>

El coste del problema es O(n³) tanto en tiempo como en espacio donde n es la cantidad de poblados

Primero recorremos la diagonal y la inicializamos con infinito. En el caso de que elem sea el poblado vecino de j entonces lo 
guardamos en la matriz, si no comprueba que el coste que acabamos de calcular sea menor que el de la 
matriz y lo guarda.

 @ </answer> */
const int INF = 10000000;

Matriz<int> viajes(vector<vector<int>> const& alquiler, int poblados) {
    Matriz<int> viajes(poblados + 1, poblados + 1, 0);
    int temp, elem;
    
    for (int i = 1; i <= poblados - 1; i++) {
        for (int j = 0; j <= poblados - i; j++) { 
            elem = j + i;
            viajes[j][elem] = INF;
            if (j + 1 == elem) 
                viajes[j][elem] = alquiler[j][elem];
            else {
                for (int k = j; k <= elem - 1; k++) {
                    temp = viajes[j][k] + alquiler[k][elem];
                    if (temp < viajes[j][elem])
                        viajes[j][elem] = temp;
                }
            }
        }
    }

    return viajes;
}


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso(){
    int poblados, canoas;
    cin >> poblados;

    vector<vector<int>> alquiler(poblados, vector<int>(poblados,0));

    if (!std::cin)
        return false;

    for (int i = 0; i < poblados-1; ++i) {
        for (int j = i+1; j < poblados; ++j) {
            cin >> alquiler[i][j];
        }
    }
  
    Matriz<int> viaje = viajes(alquiler, poblados);
    for (int i = 0; i < poblados - 1; i++) {
        for (int j = i + 1; j < poblados; j++) {
            cout << viaje[i][j] << " ";
        }
        cout << "\n";
    }

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main()
{
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso()) {}
      
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
