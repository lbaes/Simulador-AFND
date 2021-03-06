#include "lista.h"

typedef struct Quintupla
{

    char alfabeto[11];      //string dos caracteres do alfabeto, max 10
    int tamAlfabeto;        //tamanho do alfabeto, max 10

    int qntEstados;         //Quantidade de estados, max 20, numero Q
    int qntEstadosIniciais; //Quantidade de Estados inciais
    int qntEstadosFinais;   //Quantidade de Estado finais, numero F
    int numTrasicoes;       //Numero de transicoes

    int vetorEstadosFinais[19]; //Lista dos estados finais, max 19

    List** matriz; //Matriz de transicao
} Quintupla;

List** alocarMT(int, int);
void printMatrizTransicao(List**, int, int);
void deletarMT(List** mt, int qntEstados, int tamAlfabeto);
