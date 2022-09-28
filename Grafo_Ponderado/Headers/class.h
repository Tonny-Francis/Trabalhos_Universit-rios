#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "functions.h"

using namespace std;

//Classes
class Grafo
{
    private:
    vector <string> _Vertice_1;
    vector <string> _Vertice_2;
    vector <string> _Arestas;
    
    public:
    //Obtem os valores do Vertice 1
    string GetVertice_1(int n);
    //Obtem os valores do vertice 2
    string GetVertice_2(int n);
    //Obtem os valor da aresta
    string GetAresta(int n);
    //Obtem o tamanho do vertice
    int GetTam();
    //Gerencia os dados do arquivo.txt
    void GerenciaDados();
    //Numero de vertices e enlaces
    int Numero_vertices_enlaces();
    //Lista de vertices
    int ListaVertices();
    //Metodo de inserção de arestas
    void InsercaoArestas(string Vertice_1,string Vertice_2, string Peso );
    //Função menu e amiga da class Grafo
    friend int Menu(Grafo _Grafo);
    //Funçao voltar e amiga da class Grafo
    friend int Voltar(Grafo _Grafo);
    //Algoritmo de Dijkstra
    friend vector <string> MenorValor(Grafo _Grafo, string Origem);
    friend int Algoritmo_Diijkstra(Grafo _Grafo);
    //
    friend vector <string> Vizinhos_Pesos(Grafo _Grafo, string Ponto);
};

class Vertice
{
    private:
    vector <string> _Vertice_1;
    vector <string> _Vertice_2;
    
    public:
    //Armazena os vertices lidos do arquivo.txt no vector
    void setVertices(string _vertice_1, string _vertice_2);
};

class Aresta 
{
    private:
    string Origem;
    string Destino;

    public:
    //Construtor que define o ponto de origem e destino 
    Aresta(string _origem, string _destino);
    //Função menu e amiga da class Aresta
    friend int Menu(Grafo _Grafo, Aresta _Aresta);
    //Funçao voltar e amiga da class Grafo
    friend int Voltar(Grafo _Grafo, Aresta _Aresta);
    friend int Algoritmo_Diijkstra(Grafo _Grafo, Aresta _Aresta_1);
};