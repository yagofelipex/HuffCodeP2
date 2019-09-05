#ifndef  FUNCOES_H
#define  FUNCOES_H

#include "Huffman.h"

Nodes *CreatNode(int data, char character, Nodes * left, Nodes *right);
/*
 * Esta função serve para a criação de um novo nó na Árvore de Huffman
 * Os argumentos necessário são:
 * um valor inteiro, caractere, ponteiro para nós da esquerda e direita
 *
 */

heap *CreatTable(int size_table);
/*
 * Esta função serve para a criação de uma tabela na qual usaremos
 * para implementar uma Heap.
 * Seus valores serão endereços para nós (ponteiro apontando a Nodes)
 * Necessário passar o tamanho da Heap.
 * Também será inicializado todas os indices com valor NULO.
 * No final será retornado a Heap.
 *
 */
hash *create_hash();

/*
 *
 *
 */

void Swap(Nodes **a, Nodes **b);

/* Essa função serve para
 *
 *
 */

int GetParentIndex(int index);

/*
 *
 *
 */

int GetChildrenLeftIndex(int index);

/*
 *
 *
 */

int GetChildrenRightIndex(int index);

/*
 *
 *
 */

void View(heap *Heap);
void DownHeapMin(int index, heap *Heap);
Nodes *Pop(heap *Heap);
void UpHeapMin(int index, heap *Heap);
void Insert(int Value, char character, heap *Heap, Nodes *left, Nodes *right);
int eh_folha(Nodes *huffman_node);

/*
 * Essa função serve para verificar se dado a raiz de uma arvore
 * seus filhos a esquerda e direita estão NULOS
 * Retorna 1 em caso positivo, 0 caso contrário.
 */
void print_tree_huffman(Nodes *huffman_node);

/*
 * Essa função serve para fazer a impressão da arvore de huffman.
 * Recebe o argumento sendo a raiz da árvore.
 * Será impressa na pré-ordem.
 *
 */

void print_tree_huffman_file(FILE *output_file, Nodes *huffman_node);

/*
 * Essa função serve para fazer a impressão da arvore de huffman no arquivo.
 * Recebe o argumento sendo a raiz da árvore e o arquivo de saída.
 * Será impressa na pré-ordem.
 *
 */

long long int FileSize(FILE *in);

/*
 * Essa funcão serve para descobrir o tamanho
 * de um arquivo passado pelo argumento.
 * Será retornado seu tamanho em número.
 *
 */
Nodes *construct_tree(char nome_arquivo[], FILE *file_input);

/*
 * Essa função serve para realizar a construção árvore para compressão
 * ela
 *
 */

void Encode(Nodes *root, hash *HASH, char *new_path_bits);
unsigned long long int tree_size(Nodes* raiz);
int esta_vazia(Nodes *raiz);
int lenght_tree(Nodes *raiz);
convert_size_tree_to_bin(int size_tree, int bin[]);
is_bit_set(unsigned char byte, int i);
Cont_lixo_file(hash *HASH);
Nodes *construct_tree_descompress(Nodes *Nodes_huff, FILE *file_input_comprimido);
void get_header(FILE *file, unsigned int *tam_lixo, unsigned int *tam_arv);
void get_header_compactacao(FILE* fileout, hash *HASH, Nodes *root, int tam_arvore);
#endif
