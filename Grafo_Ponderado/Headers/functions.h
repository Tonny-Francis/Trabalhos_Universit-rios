#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

#ifdef linux
    #include <unistd.h>
#elif LINUX
    #include <unistd.h>
#elif UNIX
    #include <unistd.h>
#else
    #include <windows.h>
#endif

using namespace std;

//Limpa Tela
void Limpa_Tela();

//Delay
void Delay(int i);

//Algoritmo de Diikstra
//Pede a ori