
/*@ <answer>
 *
 * Nombre y Apellidos: Alejandro Valencia Blancas y Juan Embid Sánchez
 *
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "Matriz.h"
using namespace std;

/*@ <answer>

El coste del problema es O(n²)

Para hallar la solución hemos ido rellenando la matriz con valores enteros en función de si los caracteres coincidían.
Para reconstruir la solución O(n) hemos recorrido de manera diagonal la matriz.

 @ </answer> */
string solver(string uno, string dos) {
   string construct;
   Matriz<size_t> espacioDeSoluciones(uno.size() + 1, dos.size() + 1, 0);
   for (int i = uno.size() - 1; i > -1; i--) {
      for (int j = dos.size() - 1; j > -1; j--) {
         if (uno[i] != dos[j])
            espacioDeSoluciones[i][j] = std::max(espacioDeSoluciones[i + 1][j], espacioDeSoluciones[i][j + 1]);
         else {
            espacioDeSoluciones[i][j] = espacioDeSoluciones[i + 1][j + 1] + 1;
         }
      }
   }

   int i = 0, j = 0;
   while (i != uno.size() && j != dos.size()) {
      if (uno[i] != dos[j])
            if(espacioDeSoluciones[i + 1][j] > espacioDeSoluciones[i][j + 1])
               i++;
            else 
               j++;
      else {
         construct.push_back(uno[i]);
         i++; j++;
      }
   }

   return construct;
   //return espacioDeSoluciones[0][0];
}

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso(){
   string uno, dos;
   
   cin >> uno >> dos;

   if (!std::cin)
      return false;
   cout << solver(uno, dos) << "\n";

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
