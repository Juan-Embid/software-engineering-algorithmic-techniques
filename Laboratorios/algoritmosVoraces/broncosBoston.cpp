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

    rk donde r se refiere a los rivales e i a la posición del vector
    bk donde b se refiere a los Broncos e i a la posición del vector

    solución voraz = d1 + d2 + d3 + ...+ dj
    Solución óptima = b1 - r1 + b2 - r2 ... + bk -rk

    Si di = bi - ri seguimos la solucion óptima
    Si di > bi - ri seguimos la solución voraz (este caso nunca se va a dar)
    Si di < bi - ri seguimos la solución óptima
    
    Como nuestro algoritmo voraz tiene encuenta la suma de la máxima diferencia
    entre los rivales y los Broncos siempre que sean los Broncos mayor que los rivales,
    entonces nunca va a ocurrir que la solución óptima tenga en la posición i un número 
    mayor que el que tiene la solución voraz en la misma posición. 

    Por lo tanto para este problema la solución voráz será la misma que la óptima.

    Una solución que no sigue el algoritmo voraz va a ser mejorable. Nuestro algoritmo voraz
    ordena los vectores por tamaño. Por tanto una solución que no siguiera el algoritmo 
    voraz no estaría ordenando el vector:
      Voraz: b1 - r1 > b2 - r2 > b3 - r3 ... > bk -rk
      Otro: b1 - r1 > b2 - r2 < b3 - r3 ... > bk -rk

    La diferencia de restas de la posición 2 es mayor que la de la posición 3 haciendo
    diferente el algoritmo voraz del otro. Como queremos maximizar escogeremos la mayor
    direfencia que en todos los casos será el del algoritmo voraz.

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
