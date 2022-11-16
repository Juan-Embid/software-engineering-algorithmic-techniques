#include <iostream>
#include <vector>
#include <fstream>

/*
Alumno 1: Alejandro Valencia Blancas
Alumno 2: Juan Embid Sánchez

Coste O(currentPrice.size())

Resolvemos el problema por programación dinámica ascendente basándonos en la siguiente
recurrencia:

    currentPrice(Presupuesto) = números de conciertos a los que puede asistir
                                si podemos usar el presupuesto "Presupuesto"

Maximizamos la cantidad de conciertos a la que podemos asistir:

    std::max(currentPrice[j], currentPrice[j - precios[i]] + conciertos[i])

Comprobamos que no nos pasemos del presupuesto:

    precios[i] <= j

 */
int precio(const std::vector<int> &conciertos, const int &Presupuesto, const std::vector<int> &precios) {
    
    std::vector<int> currentPrice(Presupuesto + 1, 0);
    currentPrice[0] = 0;
        
    for (int i = 0; i < conciertos.size(); ++i) {
        for (int j = Presupuesto; precios[i] <= j; --j) {
            currentPrice[j] = std::max(currentPrice[j], currentPrice[j - precios[i]] + conciertos[i]);
        }
    }
    return currentPrice[Presupuesto];
}

bool resuelveCaso() {
    int P, N;
    std::cin >> P >> N;
    
    if (!std::cin) return false;
    
    std::vector<int> conciertos(N, 0);
    std::vector<int> precios(N, 0);
    for (size_t i = 0; i < N; ++i) {
        std::cin >> conciertos[i];
        std::cin >> precios[i];
    }
    
    std::cout << precio(conciertos, P, precios) << "\n";
    
    return true;
}

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
    //system("PAUSE");
#endif
    return 0;
}