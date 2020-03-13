#include <stdlib.h>
#include <stdio.h>
#include "quintupla.h"

//Aloca uma matriz de listas
List** alocarMT(int qntEstados, int tamAlfabeto)
{
    List** newList = malloc(qntEstados * sizeof(List *));
    for (int i = 0; i < qntEstados; i++)
    {
        newList[i] = malloc(tamAlfabeto * sizeof(List));
    }

    for (int i = 0; i<qntEstados; i++)
    {
        for (int j = 0; j < tamAlfabeto; j++)
        {
            (newList[i][j]).head = createNode(-1);
        }
    }

    return newList;
}

//-Printa a matriz
void printMatrizTransicao(List** mt, int qntEstados, int tamAlfabeto)
{
    for (int i = 0; i < qntEstados; i++)
    {
        for (int j = 0; j < tamAlfabeto; j++ )
        {
            printList(mt[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}

//-Deleta a matriz
void deletarMT(List** mt, int qntEstados, int tamAlfabeto)
{
    for (int i = 0; i < qntEstados; i++)
    {
        for (int j = 0; j < tamAlfabeto; j++)
        {
            deleteList(&(mt[i][j]));
        }
    }
    free(mt);
}