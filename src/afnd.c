#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quintupla.h"

int *lerArquivo(char *nomeArquivo);
int indexOf(char target, char *str);
int transicao(int qAtual, char *palavra, int pi, List **matriz, int *eFinais, int tam, char *alfabeto);

int main(void)
{
    Quintupla quin;
    int nPalavras;
    char **palavras;

    FILE *fp = fopen("entrada.txt", "r");

    fscanf(fp, "%s", quin.alfabeto);
    quin.tamAlfabeto = strlen(quin.alfabeto);
    fscanf(fp, "%d", &(quin.qntEstados));
    fscanf(fp, "%d", &(quin.qntEstadosFinais));


    for (int i = 0; i < quin.qntEstadosFinais; i++)
        fscanf(fp, "%d", &(quin.listaEstadosFinais[i]));
        
    
    fscanf(fp, "%d", &(quin.numTrasicoes));
    quin.matriz = alocarMT(quin.qntEstados, quin.tamAlfabeto);

    char c;
    for (int i = 0, qIncial = 0, qFinal = 0; i < quin.numTrasicoes; i++)
    {
        fscanf(fp, "%d", &qIncial);
        fscanf(fp, "%c", &c);
        fscanf(fp, "%d", &qFinal);

        inserir(&(quin.matriz[qIncial][indexOf(c, quin.alfabeto)]), qFinal);
    }

    fscanf(fp, "%d", &nPalavras);

    palavras = malloc(nPalavras * sizeof(char *));
    for (int i = 0; i < nPalavras; i++)
    {
        palavras[i] = malloc(101 * sizeof(char));
        fscanf(fp, "%s", palavras[i]);
    }

    fclose(fp);
    printf("Alfabeto: %s\n", quin.alfabeto);
    printf("Quantidade de estados: %d\n", quin.qntEstados);
    printf("Quantidade de estados finais: %d\n", quin.qntEstadosFinais);
    printf("Estados Finais:\n");

    for (int i = 0; i < quin.qntEstadosFinais; i++)
    {
        printf("%d ", quin.listaEstadosFinais[i]);
    }

    printf("\nNumero de transicoes: %d\n", quin.numTrasicoes);

    printf("Matriz de transicao:\n");
    printMatrizTransicao(quin.matriz, quin.qntEstados, quin.tamAlfabeto);
    printf("Lendo %d palavras\n", nPalavras);

    for (int i = 0; i < nPalavras; i++)
    {
        printf("Palavra %d: %s", i, palavras[i]);

        if (transicao(0, palavras[i], 0, quin.matriz, quin.listaEstadosFinais, quin.qntEstadosFinais, quin.alfabeto))
        {
            printf(" ok..\n");
        }
        else
        {
            printf(" not ok\n");
        }
    }

    
    deletarMT(quin.matriz, quin.qntEstados, quin.tamAlfabeto);
}

int indexOf(char target, char *str)
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == target)
            return i;
    }

    return -1;
}

int isFinal(int q, int *eFinais, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (eFinais[i] == q)
            return 1;
    }
    return 0;
}
int transicao(int qAtual, char *palavra, int pi, List **matriz, int *eFinais, int tam, char *alfabeto)
{
    List a;
    Node *cursor;
    int indice = indexOf(palavra[pi], alfabeto);

    a = matriz[qAtual][indice];
    cursor = (a.head);

    if (isFinal(cursor->data, eFinais, tam) == 1 && palavra[pi+1] == '\0')
    {
        return 1;
    }
    else if (isFinal(cursor->data, eFinais, tam) == 0 && palavra[pi+1] == '\0')
    {
        return 0;
    }
    while (cursor->data != -1)
    {
        if (transicao(cursor->data, palavra, pi + 1, matriz, eFinais, tam, alfabeto))
            return 1;
        cursor = cursor->next;
    }

    return 0;
}
