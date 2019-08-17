#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<string.h>

#define MAX 256

typedef struct Tree
{
	int Value_node;
	char symbol;
	struct Tree *left;
	struct Tree *right;
} HuffTree;

typedef struct data
{
	int frequency;
	char character;
	struct data *next;
} Nodes;

typedef struct Array
{
	Nodes *table[MAX];
} Hash;

/*we use this function for creat the nodes*/
Nodes *CreatNode(int data,char character)
{
	Nodes* node     = (Nodes*)malloc(sizeof(Nodes));
	node->frequency = data;
	node->character = character;
	return node;
}

/*Here in this function we're going creat a node with sum of the elements*/
/*HuffTree *Creation(int Ffrequency,int Sfrequency,char character)
{
	HuffTree *Node   = (HuffTree*)malloc(sizeof(HuffTree));
	Node->Value_node = Ffrequency + Sfrequency;
	Node->symbol     =  '*';
	Node->left       = Node->right = NULL;
	return Node;
}*/

HuffTree *create_nodes_huff(Nodes *node)
{
	HuffTree *Node   = (HuffTree*)malloc(sizeof(HuffTree));
	Node->Value_node = node->frequency;
	Node->symbol     = node->character;
	Node->left       = Node->right = NULL;
	return Node;
}

/*It's in this function where we creat a array of pointers*/
Hash *CreatTable(int size_table)
{
	int i;
	Hash *Table = (Hash*)malloc(sizeof(Hash));
	for(i = 0;i < size_table;i++)
	{
		Table->table[i] = NULL;
	}
	return Table;
}

void print_hash_table(Hash *Hash,int size)
{
	int i;
	for (i = 0;i < size;i++)
	{
		printf("%d %c\n",Hash->table[i]->frequency,Hash->table[i]->character);
	}
}

void print_huff_tree(HuffTree *huff_node) {
	if (huff_node == NULL) return;
	printf("(");
	if (huff_node->symbol == ' ') {
		printf("+");
	}
	else
	{
		printf("%d ", huff_node->Value_node);
		printf("%c", huff_node->symbol);
	}
	if (huff_node->left == NULL) {
		printf("()");
	} else {
		print_huff_tree(huff_node->left);
	} if (huff_node->right == NULL) {
		printf("()");
	} else {
		print_huff_tree(huff_node->right);
	}
	printf(")");
}

int main()
{
	FILE *file_input; //variavel que guardará o arquivo de entrada
	unsigned char caracter;
	char nome_arquivo[30];
	unsigned int *string = (unsigned int*)calloc(256,sizeof(unsigned int));
	int i = 0;
	int cont = 0;
	scanf("%[^\n]", nome_arquivo);
	file_input = fopen(nome_arquivo, "rb");
	int tam_hash = 0;
	int j = 0;
	int *indice = (int*)malloc(256 * sizeof(int));

	if(file_input == NULL)
	{
		printf("ERRO AO ABRIR ARQUIVO: %s\n", nome_arquivo);
		return 0;
	}
	else
	{
		while(fscanf(file_input, "%c", &caracter) != EOF)
		{
			//printf("%c", caracter);
			string[caracter]++;
		}
	}

	for(i = 0; i < 256; i++)
	{
		if(string[i] >= 1)
		{
		//	printf("Characters: %c Frequency: %d\n",i, string[i]);
			tam_hash++;
			indice[j] = i;
			j++;
		}
		/*Nodes* node = CreatNode(string[i], 'i');
		Heap->table[i] = node;*/
	}
	//printf("%d\n", tam_heap);
	Hash *hash = CreatTable(tam_hash);

	for(i = 0; i < tam_hash; i++)
	{
		Nodes* node = CreatNode(string[indice[i]], indice[i]);
		hash->table[i] = node;
		HuffTree *Node_h = create_nodes_huff(hash->table[i]);
		print_huff_tree(Node_h);
		//printf("Characters: %c Frequency: %d\n",indice[i], string[indice[i]]);
		//printf("%d\n", indice[i]);
	}
	printf("\n");
    //HuffTree *Node  = Creation(5,5);
    //HuffTree *Node1 = Creation(5,20);
    //Testes//
    /*Nodes* node = CreatNode(2,'A');
    Nodes* node2 = CreatNode(5,'B');
    Heap->table[0] = node;
    Heap->table[1] = node2;
    print_heap_table(Heap,2);*/
	//print_hash_table(hash,tam_hash);
}
