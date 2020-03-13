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

    /* Leitura do arquivo de entrada   */
    FILE *fp = fopen("entrada.txt", "r");

    fscanf(fp, "%s", quin.alfabeto);            //le o alfabeto na primeira linha
    quin.tamAlfabeto = strlen(quin.alfabeto);

    fscanf(fp, "%d", &(quin.qntEstados));       //le a quantidade de stados na segunda linha
    fscanf(fp, "%d", &(quin.qntEstadosFinais)); //le a quantidade de stados finais na terceira linha

    //salva os estados finais no vetor listaEstadosFinais
    for (int i = 0; i < quin.qntEstadosFinais; i++)
        fscanf(fp, "%d", &(quin.listaEstadosFinais[i]));
        
    
    fscanf(fp, "%d", &(quin.numTrasicoes));     // le o numero de transicoes na quarta linha
    quin.matriz = alocarMT(quin.qntEstados, quin.tamAlfabeto); //aloca a matriz de transicao

    //Este loop preenche a matriz de transicao lendo o arquivo de entrada
    char c;
    for (int i = 0, qIncial = 0, qFinal = 0; i < quin.numTrasicoes; i++)
    {
        fscanf(fp, "%d", &qIncial);
        fscanf(fp, "%c", &c);
        fscanf(fp, "%d", &qFinal);

        inserir(&(quin.matriz[qIncial][indexOf(c, quin.alfabeto)]), qFinal);
    }

    fscanf(fp, "%d", &nPalavras);       //le a quantidade de palavras a serem analisadas

    //Este loop preenche o vetor palavras
    palavras = malloc(nPalavras * sizeof(char *)); 
    for (int i = 0; i < nPalavras; i++)
    {
        palavras[i] = malloc(101 * sizeof(char));
        fscanf(fp, "%s", palavras[i]);
    }

    fclose(fp);
    /* Fim da leitura do arquivo de entrada*/

    /* Printa informacoes da Quintupla */
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



    //Salva cada palavra a ser analisada no vetor palavras
    for (int i = 0; i < nPalavras; i++)
    {
        printf("Palavra %d: %s", i, palavras[i]);

        //Faz a analise da palavra
        if (transicao(0, palavras[i], 0, quin.matriz, quin.listaEstadosFinais, quin.qntEstadosFinais, quin.alfabeto))
        {
            printf(" ok..\n");
        }
        else
        {
            printf(" not ok\n");
        }
    }

    /*Liberando memoria alocada */

    free(palavras);
    //Deleta a matriz de transicao
    deletarMT(quin.matriz, quin.qntEstados, quin.tamAlfabeto);
}

//retorna o indice do caracter target na string str
int indexOf(char target, char *str)
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == target)
            return i;
    }

    return -1;
}

//Retorna 1 caso o estado q pertenca ao vetor qFinais
int isFinal(int q, int *eFinais, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (eFinais[i] == q)
            return 1;
    }
    return 0;
}

//Funcao recursiva que analisa a palavra
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
