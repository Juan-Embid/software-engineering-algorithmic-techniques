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
#include <vector>

using namespace std;

/*@ <answer>
 
 Para este problema hemos usado algoritmos voraces. Para construir nuestra
 solución disponemos de un conjunto de candidatos que guardamos en un vector.
 Estos candidatos se refieren a los puntos sin ordenar conseguidos por los 
 rivales y por los Broncos. 
 Ordenamos de mayor a menos la puntuación de los rivales y de manera contraria
 la de los Boston. Creamos una función de selección "exitoMaxim" en la que vamos acumulando los
 puntos. Si la diferencia entre la puntuación de la resta entre Broncos menos rivales
 es mayor que 0 entonces éstos empezarán a formar parte de los seleccionados. La puntuación
 acumulada será la solución al problema. 
 
 El coste del problema es O(n log n) donde n es el tamaño del vector. 

 Demostración:

    r1 <= r2 <= r3 ...| <= ri <=
    voraz  x1 >= x2   | >= xi >=
              ==      |   !=
    optima y1 >= y2   |    yi      xi == yj

    Caso xi <= ri:
      Si se pierde en xi entonces se pierden en todos los partidos que hay a la derecha tanto en xi como en yi,
      por esto podemos intercambiar .
    
    Caso xi > ri:
      Si es distinto xi a yi entonces esto significa que xi > yi porque nuestra solución voraz ha ordenador de mayor a menor.

      Opción yi > ri && yj > rj
        Caso yi > rj
          yi - ri + yi - rj (después de intercambiar) <= yj - ri + yi - rj (antes de intercambiar)
        Caso yi <= rj
          yi - ri + yj - rj (después de intercambiar) <= yj - ri (antes de intercambiar)
      Opción yi > ri && yj <= rj Este caso no se puede dar porque  estamos en el caso de xi > ri y la opcion yi <= rj donde xi == yj. 
      yi - ri (antes) <= yj - ri (después)
      Opción yi <= ri && yj > rj
      yj - rj (antes) <= yj -ri (después)

    Por lo tanto para este problema la solución voráz será la misma que la óptima.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>


int exitoMaxim(vector<int> rivales, vector<int> broncos) {
    int N = rivales.size(), result = 0; //O(1)

    for(int i = 0; i < N; i++) {//O(N)
        if(broncos[i] - rivales[i] > 0)
            result += broncos[i] - rivales[i];
    }

    return result;   
}

bool resuelveCaso() {
    int N, temp;
    vector<int> rivales, broncos;

    cin >> N; 
    if (N == 0) 
    return false;

    for(int i = 0; i < N; i++) {//O(N)
        cin >> temp;
        rivales.push_back(temp);//O(1)
    }
    for(int j = 0; j < N; j++) {//O(N)
        cin >> temp;
        broncos.push_back(temp); //O(1)
    }

    sort(rivales.begin(), rivales.end(), greater<int>()); //O(N log N) donde N es el tamaño del vector
    sort(broncos.begin(), broncos.end(), less<int>()); //O(N log N)

    cout << exitoMaxim(rivales, broncos) << "\n"; //O(N)
  
  return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

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
 // system("PAUSE");
#endif
  return 0;
}
