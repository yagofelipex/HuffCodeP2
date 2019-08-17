
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<string.h>
#define Max 10000
typedef struct Tree
{
int Value_node;
char symbol;
struct Tree *left;
struct Tree *right;
}HuffTree;
typedef struct data
{
int frequency;
char character;
}Nodes;
typedef struct Array
{
int size;
Nodes *table[Max];
}heap; 
/*we use this function for creat the nodes*/
Nodes *CreatNode(int data,char character)
{
Nodes* node     = (Nodes*)malloc(sizeof(Nodes));
node->frequency = data;
node->character = character;
return node;
}
/*Here in this function we're going creat a node with sum of the elements*/ 
HuffTree *Creation(int Ffrequency,int Sfrequency,char character)
{
HuffTree *Node   = (HuffTree*)malloc(sizeof(HuffTree));
Node->Value_node = Ffrequency + Sfrequency;
Node->symbol     =  '*';
Node->left       = Node->right = NULL;
return Node;
}
/*It's in this function where we creat a array of pointers*/
heap *CreatTable(int size_table)
{
int i;
heap *Table = (heap*)malloc(sizeof(heap));
for(i = 0;i < size_table;i++)
{
    Table->table[i] = NULL;
}
return Table;
}
int function(heap *Heap,int size)
{
int i;
for (i = 0;i < size;i++)
{
printf("%d %c\n",Heap->table[i]->frequency,Heap->table[i]->character);
}
}
int main()
{
    heap *Heap = CreatTable(2);
    //HuffTree *Node  = Creation(5,5);
    //HuffTree *Node1 = Creation(5,20);
    //Testes//
    Nodes* node = CreatNode(2,'A');
    Nodes* node2 = CreatNode(5,'B');
    Heap->table[0] = node;
    Heap->table[1] = node2;
    function(Heap,2);
}
