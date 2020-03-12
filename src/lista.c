#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

Node* createNode(int _data)
{
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        return NULL;

    newNode->data = _data;
    newNode->next = NULL;

    return newNode;
}

List* createList()
{
    List* newList = malloc(sizeof(List));
    if (newList == NULL)
        return NULL;
    newList->head = createNode(0);

    return newList;
}

void inserir(List* l, int data)
{
    Node* newNode = createNode(data);
    if (newNode != NULL){
        newNode->next = l->head;
        l->head = newNode;
    }

}

void printList(List l)
{
    Node* cursor = l.head;
    printf("[");
    while(cursor != NULL)
    {   
        if (cursor->data != -1)
            printf("%d ", cursor->data);
        cursor = cursor->next;
    }
    printf("]");
}


void deleteList(List* l)
{
    Node* aux = l->head;
    while(l->head != NULL)
    {
        aux = l->head;
        l->head = (l->head)->next;
        free(aux);
    }

    l = NULL;
}