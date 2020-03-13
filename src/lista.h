//Node de lista ligada simples
typedef struct Node 
{
    int            data;
    struct Node*    next;
}Node;

//Lista Ligada simples
typedef struct List
{
    Node*   head;
}List;

Node* createNode(int);
void deleteList(List*);
void inserir(List*, int);
void printList(List);
List* createList();
