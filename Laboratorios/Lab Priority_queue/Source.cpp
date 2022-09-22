
/*@ <answer>
 *
 * Nombre y Apellidos:
 Alejandro Blancas Valencia
 Juan Embid S�nchez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <list>
using namespace std;

/*@ <answer>
  
 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.
 
 En este ejercicio hemos hecho uso de dos Stl; una cola de prioridad que consta de un pair donde almacenamos las cajas
 con su tiempo actual y de segundo entero el identificador de la propia caja. Luego tambi�n hemos usado una lista para los clientes
 est� no es necesaria ya que se pod�a ir metiendo dentro de la cola de prioridad cliente por cliente, pero hemos preferido
 esta opci�n para tenerlo todo m�s ordenado y vistoso.
 Basicamente nuestro programa lo que hace es ir mirando cual es la caja con el tiempo menor y le va sumando el siguiente cliente
 hasta que ya no quedan clientes en la lista, donde se revisa por �ltima vez la caja con menor tiempo de espera y se elige. 
 
 
 @ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>

int resultIsmael(int cashiers, int clients, list<int> clientslist){ // O(n) donde n es el numero de clientes
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
        int i = 1;
        pair<int, int> temp;

        while(i <=  cashiers && clientslist.size() > 0 ){ //O(n) donde n es numero de clientes o cashiers
            queue.push({ clientslist.front(), i });
            clientslist.pop_front();
            i++;
        }

        if (cashiers > clients) { //si hay m�s cajeros que clientes se 
           return clients + 1;    // mete directamente a la primera caja vac�a
        } else {
            while (clientslist.size() > 0) {  // O(n) donde n es el tama�o de clientes
                temp = { queue.top().first + clientslist.front(), queue.top().second};
                clientslist.pop_front();
                queue.pop();
                queue.push(temp);
            }
            return queue.top().second;
       }
       
}

// pair <tiempoCliente, idCaja>;
bool resuelveCaso() {
    list<int> clientslist;
    int cashiers, clients, temp, temp1, i = 0;
   // leer los datos de la entrada
    cin >> cashiers;
    cin >> clients;
    temp1 = clients;
   if (cashiers == 0 && clients == 0)
      return false;
      
   while (clients != 0) {
       cin >> temp;
       clientslist.push_back(temp);
       clients--;
   }
   
   cout << resultIsmael(cashiers, temp1,clientslist)<< "\n";
 
   return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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