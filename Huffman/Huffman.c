#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct Tree {
	unsigned int frequency;
	char character;
	struct Tree *left;
	struct Tree *right;
} Nodes;

typedef struct Array {
	int size;
	Nodes *table[MAX];
} heap;

typedef struct SaveValues {
	unsigned int frequencia;
	char c;
	unsigned char bits[30];
} NewValue;

typedef struct Hash {
	NewValue *array[256];
} hash;

Nodes *CreatNode(int data, char character, Nodes * left, Nodes *right) {
	Nodes* node = (Nodes*) malloc(sizeof(Nodes));
	node->frequency = data;
	node->character = character;
	node->left = left;
	node->right = right;
	return node;
}
/*It's in this function where we creat a array of pointers*/

heap *CreatTable(int size_table) {
	int i;
	heap *Table = (heap*) malloc(sizeof(heap));
	for (i = 0; i < size_table; i++) {
		Table->table[i] = NULL;
	}
	return Table;
}

hash *create_hash()
{
    hash* HASH = (hash*) malloc(sizeof(hash));

    for (int i = 0; i < 256; i++)
    {
    	HASH->array[i] = (NewValue*) malloc(sizeof(NewValue));
    	HASH->array[i]->frequencia = 0;
    	//HASH->array[i]->bits[0] = '\0';
    }
    return HASH;
}

// swap two min heap nodes//
void Swap(Nodes **a, Nodes **b) {
	Nodes *t = *a;
	*a = *b;
	*b = t;
}

int GetParentIndex(int index) {
	return index / 2;
}

int GetChildrenLeftIndex(int index) {
	return index * 2;
}

int GetChildrenRightIndex(int index) {
	return index * 2 + 1;
}

int eh_folha(Nodes *huffman_node) {
	if ((huffman_node->left == NULL) && (huffman_node->right == NULL)) {
		return 1;
	} else {
		return 0;
	}
}

void View(heap *Heap) {
	int i;
	for (i = 1; i <= Heap->size; i++) {
		printf(" %d %c ", Heap->table[i]->frequency, Heap->table[i]->character);
	}
	//printf("\n");
}

void DownHeapMin(int index, heap *Heap) {
	if (index * 2 > Heap->size) {
		return;
	} else {
		int left = GetChildrenLeftIndex(index);
		int Right = GetChildrenRightIndex(index);
		int smallest = index;
		if (left <= Heap->size
				&& Heap->table[left]->frequency
						< Heap->table[smallest]->frequency) {
			smallest = left;
		}
		if (Right <= Heap->size
				&& Heap->table[Right]->frequency
						< Heap->table[smallest]->frequency) {
			smallest = Right;
		}
		if (smallest == index) {
			return;
		} else {
			Swap(&Heap->table[index], &Heap->table[smallest]);
			DownHeapMin(smallest, Heap);
		}
	}
}

Nodes *Pop(heap *Heap) {
	if (Heap->size == 0) {
		return 0;
	} else {
		Nodes *aux = Heap->table[1];
		Heap->table[1] = Heap->table[Heap->size];
		Heap->size--;
		DownHeapMin(1, Heap);
		return aux;
	}
}

void UpHeapMin(int index, heap *Heap) {
	if (index == 1) {
		return;
	} else {
		int Parentidx = GetParentIndex(index);
		if (Heap->table[index]->frequency < Heap->table[Parentidx]->frequency) {
			Swap(&Heap->table[index], &Heap->table[Parentidx]);
			UpHeapMin(Parentidx, Heap);
		}
	}
}

void Insert(int Value, char character, heap *Heap, Nodes *left, Nodes *right) {
	Heap->size++;
	Heap->table[Heap->size] = CreatNode(Value, character, left, right);
	UpHeapMin(Heap->size, Heap);
}

void print_tree_huffman(Nodes *huffman_node) {
	if (huffman_node != NULL) {
		if (((huffman_node->character == '*') || (huffman_node->character == 92))
				&& eh_folha(huffman_node)) {
			printf("%c", 92);
		}

		printf("%c", huffman_node->character);
		print_tree_huffman(huffman_node->left);
		print_tree_huffman(huffman_node->right);
	}
}

void print_tree_huffman_file(FILE *output_file, Nodes *huffman_node) {
	if (huffman_node != NULL) {
		if (((huffman_node->character == '*') || (huffman_node->character == 92))
				&& eh_folha(huffman_node)) {
			fprintf(output_file, "%c", 92);
		}

		fprintf(output_file, "%c", huffman_node->character);
		print_tree_huffman_file(output_file, huffman_node->left);
		print_tree_huffman_file(output_file, huffman_node->right);
	}
}

long long int FileSize(FILE *in) {
	long long int bytes;
	if (in != NULL) {
		fseek(in, 0, SEEK_END);
		bytes = ftell(in);
	}
	return bytes;
}

Nodes *construct_tree(char nome_arquivo[], FILE *file_input) {
	FILE *file_output; //variavel que guardará o arquivo de entrada e saida
	unsigned char caracter;
	//char nome_arquivo[30];
	Nodes *root;
	Nodes *left;
	Nodes *right;
	Nodes *top;
	int byte = 0;

	heap *Heap = CreatTable(256);
	Heap->size = 0;

	unsigned int *string = (unsigned int*) calloc(256, sizeof(unsigned int));
	int cont, i;
	i = cont = 0;
	file_input = fopen(nome_arquivo, "rb");
	if (file_input == NULL) {
		printf("Unable to open file: %s\n", nome_arquivo);
		exit(1);
	} else {
		while (fscanf(file_input, "%c", &caracter) != EOF) {
			string[caracter]++;
			byte++;
			//printf("%c", caracter);
		}
	}
	/*printf("****************************************\n");
	printf("SIZE FILE: %lld\n", FileSize(file_input));
	printf("****************************************\n");*/
	for (i = 0; i < 256; i++) {
		if (string[i] >= 1) {
			Insert(string[i], i, Heap, NULL, NULL);
			printf("Characters: %c Frequency: %d\n", i, string[i]);
		}
	}

	while (!(Heap->size == 1)) {
		left = Pop(Heap);
		right = Pop(Heap);
		Insert(left->frequency + right->frequency, '*', Heap, left, right);
	}
	//Nodes *root = Heap[1];
	return root = Heap->table[Heap->size];
	//View(Heap);
}

void SaveInHash(char v[], long long int tam, hash *HASH, char c, unsigned int freq) {
	int j;

	HASH->array[c]->frequencia = freq;
	HASH->array[c]->c = c;

	for (j = 0; j < tam; j++) {
		//printf("%c", v[j]);
		//int lng = strlen(v);
		HASH->array[c]->bits[j] = v[j];
	}

	//printf("\n");
}

void Encode(Nodes *root, char arr[], long long int i, hash *HASH)
{
	// Assign 0 to left edge and recur
	if (root->left) {

		arr[i] = '0';
		Encode(root->left, arr, i+1, HASH);
	}

	// Assign 1 to right edge and recur
	if (root->right) {

		arr[i] = '1';
		Encode(root->right, arr, i+1, HASH);
	}

	if (eh_folha(root)) {
		//printf("%lld\n", i);
		//printf("%s\n", arr);
		/*printf("%s\n", arr);
		printf("%c\n", root->character);
		printf("%d\n", root->frequency);*/
		SaveInHash(arr, i, HASH, root->character, root->frequency);
	}
}

unsigned long long int tree_size(Nodes* raiz) {
	if (raiz == NULL) {
		return 0;
	} else {
		return 1 + tree_size(raiz->left) + tree_size(raiz->right);
	}
}

int esta_vazia(Nodes *raiz) {
	return (raiz == NULL);
}

int lenght_tree(Nodes *raiz) {
	int cont = 0;
	if (!esta_vazia(raiz)) {
		if (eh_folha(raiz)
				&& (raiz->character == '*' || raiz->character == 92)) {
			cont = 1;
		}

		cont = cont + 1 + lenght_tree(raiz->left);
		cont = cont + lenght_tree(raiz->right);
	}

	return (cont);
}

int convert_size_tree_to_bin(int size_tree, int bin[]) {
	int aux;

	for (aux = 13; aux >= 0; aux--) {
		if (size_tree % 2 == 0) {
			bin[aux] = 0;
		} else {
			bin[aux] = 1;
		}
		size_tree = size_tree / 2;
	}
	return *bin;
}

int is_bit_set(unsigned char byte, int i) {

	unsigned int aux = 1;
	aux = aux << (unsigned int) i;
	return (aux & byte);
}

int Cont_lixo_file(hash *HASH)
{
	int i;
	long long int lixo = 0;
	for(i = 0; i < 256; i ++)
	{
		 if(HASH->array[i]->frequencia >= 1)
		 {
			 lixo += strlen(HASH->array[i]->bits) * HASH->array[i]->frequencia;
		 }
	 }

	 lixo = 8 - (lixo % 8);

	 return lixo;
}

Nodes *construct_tree_descompress(Nodes *Nodes_huff, FILE *file_input_comprimido) {
	unsigned char c;
	fscanf(file_input_comprimido, "%c", &c);

	if (c == 42) {
		Nodes_huff = CreatNode(0, c, NULL, NULL);
		Nodes_huff->left = construct_tree_descompress(Nodes_huff->left,
				file_input_comprimido);
		Nodes_huff->right = construct_tree_descompress(Nodes_huff->right,
				file_input_comprimido);
	} else {
		if (c == '\\') {
			fscanf(file_input_comprimido, "%c", &c);
		}
		Nodes_huff = CreatNode(0, c, NULL, NULL);
	}
	return Nodes_huff;
}

void *get_header(FILE *file, unsigned int *tam_lixo, unsigned int *tam_arv)
{
    unsigned char bytes_cabecalho = (unsigned char)fgetc(file);
    *(tam_lixo) = bytes_cabecalho >> 5;

    unsigned char five_bytes_from_tree = bytes_cabecalho << 3;
    *(tam_arv) = five_bytes_from_tree >> 3;
    bytes_cabecalho = (unsigned char)fgetc(file);
    *(tam_arv) <<= 8;
    *(tam_arv) |= bytes_cabecalho;
}

void descompress() {
	FILE *file_input_descompress; //variavel que guardará o arquivo de entrada
	FILE *file_output;
	char nome_arquivo[30];
	int j;
	Nodes *temp;
	unsigned char character;
	unsigned int tam_lixo, tam_arv;
	int i;
	long long int tam_file = 0;
	long long int bytes = 0;
	char arquivo_saida[100];
	int tam_arquivo_entrada = 0;
	printf("Nome do arquivo a descompactar?\n");
	scanf("%s", nome_arquivo);
	file_input_descompress = fopen(nome_arquivo, "rb");
	if (file_input_descompress == NULL) {
		printf("Unable to open file: %s\n", nome_arquivo);
		return;
	}
	bytes = FileSize(file_input_descompress);
	fclose(file_input_descompress);
	file_input_descompress = fopen(nome_arquivo, "rb");
	/*while(fscanf(file_input_descompress, "%c", &character) != EOF)
	{
		tam_file++;
	}*/
	tam_arquivo_entrada = strlen(nome_arquivo);

	int *header;
	get_header(file_input_descompress, &tam_lixo, &tam_arv);
	Nodes *root = construct_tree_descompress(root,
			file_input_descompress);
	Nodes *root_aux = root;
	print_tree_huffman(root);
	printf("\n");

	//printf("TAM FILE: %lld\n", tam_file);

	printf("TAM FILE: %lld\n", bytes);
	printf("TAM LIXO: %d | TAM TREE: %d\n", tam_lixo, tam_arv);
	for (i = 0; i < tam_arquivo_entrada - 5; i++) {
		arquivo_saida[i] = nome_arquivo[i];
	}
	arquivo_saida[i] = '\0';

	//printf("%s\n", arquivo_saida);
	file_output = fopen(arquivo_saida, "wb");

	temp = root;
	//printf("%d %d\n", header[0], header[1]);
	while (bytes > 0)
	{
		fscanf(file_input_descompress, "%c", &character);
		//printf("%c\n", character);
		if(bytes != 1)
		{
			for(i = 7; i>=0; i--)
			{
				if(is_bit_set(character, i))
				{
					root_aux = root_aux->right;
				}
				else
				{
					root_aux = root_aux->left;
				}
				if(eh_folha(root_aux))
				{
					fprintf(file_output, "%c", root_aux->character);
					root_aux = root;
				}
			}
		}
		else
		{
			for(i = 7; i>=tam_lixo; i--)
			{
				if(is_bit_set(character, i))
				{
					root_aux = root_aux->right;
				}
				else
				{
					root_aux = root_aux->left;
				}
				if(eh_folha(root_aux))
				{
					fprintf(file_output, "%c", root_aux->character);
					root_aux = root;
				}
			}
		}
		bytes -= 1;
	}

	fclose(file_input_descompress);
	fclose(file_output);
	printf("Descompactado com sucesso!\n");
}

void get_header_compactacao(FILE* fileout, hash *HASH, Nodes *root, int tam_arvore) {
	unsigned char* bytes = (unsigned char*)malloc(3 * sizeof(unsigned char));
	int lixo = Cont_lixo_file(HASH);

	bytes[0] = lixo << 5 | tam_arvore >> 8;
	bytes[1] = tam_arvore;

	fputc(bytes[0], fileout);
	fputc(bytes[1], fileout);

	print_tree_huffman_file(fileout, root);
}

void compress() {
	FILE *file_input;
	char nome_arquivo[30];
	printf("Informe o nome do arquivo.\n");
	scanf("%s", nome_arquivo);
	Nodes *root = construct_tree(nome_arquivo, file_input);
	hash *HASH = create_hash();
	FILE *file_output;
	unsigned long long int size_tree;
	unsigned char *vetor;

	vetor = (char *)malloc(30 * sizeof(char));
	int bin_tam[8];
	int i = 0;

	Encode(root, vetor, 0, HASH);
	int tam_str = strlen(vetor);
	size_tree = lenght_tree(root);
	printf("TAM DA ARVORE EM DECIMAL: %lld\n", size_tree);

	for (i = 0; i < 256; i++) {
		if (HASH->array[i]->c > 1) {
			printf("CHAR: %c BITS: %s FREQ: %d\n", HASH->array[i]->c, HASH->array[i]->bits, HASH->array[i]->frequencia);
		}
	}
	int tam_lixo = Cont_lixo_file(HASH);
	printf("LIXO: %d\n", tam_lixo);

	char nome_file_output[30];
    strcpy(nome_file_output, nome_arquivo);
    strcat(nome_file_output, ".huff");

	file_output = fopen(nome_file_output, "wb");
	get_header_compactacao(file_output, HASH, root, size_tree);
	//Decode(root, vetor, );
	printf("PRE ORDEM: ");
	print_tree_huffman(root);
	printf("\n");
	convert_size_tree_to_bin(size_tree, bin_tam);
	for (i = 0; i < 14; i++) {
		printf("%d", bin_tam[i]);
	}
	printf("\n");
}

int main(void) {
	int op;
	printf("////////////////////////////////////\n");
	printf("INFORME O QUE DESEJA REALIZAR:\n");
	printf("1 - COMPRESSAO | 2 - DESCOMPRESSAO\n");
	printf("////////////////////////////////////\n");
	scanf("%d", &op);
	switch(op)
	{
		case 0:
			break;
		case 1:
			compress();
			break;
		case 2:
			descompress();
			break;
		default:
			printf("OPCAO INVALIDA!");
			break;
	}
	return 0;
}
