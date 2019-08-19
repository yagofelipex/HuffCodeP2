#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define Max 10000

typedef struct Tree
{
int frequency;
char character;
struct Tree *left;
struct Tree *right;
}Nodes;
typedef struct Array
{
int size;
Nodes *table[Max];
}heap;
/*Nodes *BuildTreeHuff(int Ffrequency,int Sfrequency,char character)
{
Nodes *Node   = (Nodes*)malloc(sizeof(Nodes));
Node->Value_node = Ffrequency + Sfrequency;
Node->symbol     =  '*';
Node->left       = Node->right = NULL;
return Node;
} */
/*we use this function for creat the nodes*/
Nodes *CreatNode(int data,char character)
{
Nodes* node     = (Nodes*)malloc(sizeof(Nodes));
node->frequency = data;
node->character = character;
return node;
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
// swap two min heap nodes//
void Swap(Nodes* *a,Nodes* *b)
{
Nodes *t = *a;
*a = *b; 
*b = t; 
}
int GetParentIndex(int index)
{
return index/2;
}
int GetChildrenLeftIndex(int index)
{
return index*2;
}
int GetChildrenRightIndex(int index)
{
return index*2 + 1;
}
void View(heap *Heap){
int i;
for(i = 1;i <= Heap->size;i++)
{
printf(" %d %c ",Heap->table[i]->frequency,Heap->table[i]->character);
}
printf("\n");
}
void DownHeapMin(int index,heap *Heap)
{
if(index*2 > Heap->size)return;
int left = GetChildrenLeftIndex(index);
int Right = GetChildrenRightIndex(index);
int smallest = index;
if(left <= Heap->size && Heap->table[left]->frequency < Heap->table[smallest]->frequency){
smallest = left;
}
if(Right <= Heap->size && Heap->table[Right]->frequency < Heap->table[smallest]->frequency){
smallest = Right;
}
if(smallest == index)return;
Swap(&Heap->table[index],&Heap->table[smallest]);
DownHeapMin(smallest,Heap);
}
Nodes *Pop(heap *Heap)
{
if(Heap->size == 0){
return 0;
}
Nodes *aux = Heap->table[1];
Heap->table[1] = Heap->table[Heap->size];
Heap->size--;
DownHeapMin(1,Heap);
return aux;
}
void UpHeapMin(int index,heap *Heap)
{
if (index <= 1) return;
int Parentidx = GetParentIndex(index);
if(Heap->table[index]->frequency < Heap->table[Parentidx]->frequency){
Swap(&Heap->table[index],&Heap->table[Parentidx]);
UpHeapMin(Parentidx,Heap);
}
}
void Insert(int Value,char character,heap *Heap)
{
Heap->size++;
Heap->table[Heap->size] = CreatNode(Value,character);
UpHeapMin(Heap->size,Heap);
}
int main()
{
FILE *file_input; //variavel que guardará o arquivo de entrada
unsigned char caracter;
char nome_arquivo[30];
//every time we call the function we're going to have to pass character and value that we want to add in Heap //
heap *Heap = CreatTable(256);
Heap->size = 0;
//Testes//
unsigned int *string = (unsigned int*)calloc(256,sizeof(unsigned int));
int cont, i;
i = cont = 0;
scanf("%[^\n]", nome_arquivo);
file_input = fopen(nome_arquivo, "rb");
if(file_input == NULL)
{
printf("Unable to open file: %s\n", nome_arquivo);
return 0;
}
else
{
while(fscanf(file_input, "%c", &caracter) != EOF)
{
    string[caracter]++;
}
}
for(i = 0; i < 256; i++)
{
if(string[i] >= 1){
Insert(string[i],i,Heap);
printf("Characters: %c Frequency: %d\n",i, string[i]);
}
}
View(Heap);
}
