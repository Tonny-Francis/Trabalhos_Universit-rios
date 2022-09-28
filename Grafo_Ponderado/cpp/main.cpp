#include "class.h"
#include "functions.h"
int main()
{
    //Instanciano Grafo_1
    Grafo Grafo_1;
    Aresta Aresta_1("A", "A");
    Grafo_1.GerenciaDados();
    Algoritmo_Diijkstra(Grafo_1, Aresta_1);
    //Recebe o retorno da função menu
    //Menu(Grafo_1, Aresta_1);
    
    return 0;
}