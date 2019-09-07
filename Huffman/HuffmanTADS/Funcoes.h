#ifndef  FUNCOES_H
#define  FUNCOES_H

#include "Huffman.h"

/*
 *
 * Funçoes usadas em Compress.c
 *
 * Linhas: 14 até 99
 */


void conting_freq(FILE *file_input, hash *Hash);

/*
 * Essa função tem o objetivo que é pegar o caractere lido do arquivo
 * e de acordo com sua numeração na ASCII contar a sua frequencia. Será
 * salvo em uma hash com 256 posições, onde cada posição representará o
 * caractere em decimal de acordo com a ASCII. Os argumentos necessários são
 * o arquivo de entrada a ser lido e a Hash table.
 */
Nodes *construct_tree(char nome_arquivo[], FILE *file_input);

/*
 * Essa função serve para realizar a construção árvore para compressão.
 * Será inicializado a Heap com todos os ponteiros nulos (endereço para os Nós). Eu leio o arquivo
 * de entrada e chamo a funcão conting_freq() no qual irá armazenar a frequencia
 * dos caracteres do arquivo. Se a frequencia dos caracteres forem >= 1 então será
 * inserido o caractere e sua frequencia na fila de prioridade(FP com heap). Chamamos a funcão
 * Insert() que criará Nós de todos os caracteres do arquivo junto com a frequencia respectiva.
 * A cada criação já é inserido na FP.
 * Enquanto o tamanho da FP for != 1, eu removo 2 nós com menor frequencia através da funcão
 * Pop() salvo-os em variáveis auxiliares e logo em seguida somo as suas frequencias e insiro na FP
 * formando um novo nó onde o ponteiro à esquerda (filho) será o 1º Nó removido da FP e o
 * ponteiro à direita (filho) será o 2º Nó removido da FP.
 * Quando a o tamanho da FP for igual a 1, então teremos um único Nó formado. Nossa árvore de Huffman está pronta!
 * Essa funcão retornará a raíz desse nó.
 * Os argumentos necessários são: o nome do arquivo ao abrir e o arquivo de entrada.
 *
 */

void Encode(Nodes *root, hash *HASH, char *new_path_bits);
/*
 * Essa função irá pecorrer a árvore para encontrar o novo caminho dos caracteres
 * onde parte de uma chamada recursiva caso a raíz nao seja uma folha. Se ela pecorrer
 * o filho à esquerda do Nó irá atribuir 0 e á direita irá atribuir 1. Sempre será salvo
 * em um array esses 0 e 1, pois quando chegar em uma folha, o caractere estará lá, logo
 * o seu caminho até ele será a string de 0 e 1.
 * Os argumentos necessários são: raíz da arvore, uma Hash e o array para guardar os bits.
 *
 */
void get_header_compactacao(FILE* fileout, hash *HASH, Nodes *root,
		int tam_arvore);
/*
 *
 * AINDA NAO SEI COMO FUNCIONA DIREITO
 *
 */
void insert_header_file(char nome_arquivo[], hash *HASH, Nodes *root,
		unsigned long long int size_tree, FILE *file_input);

/*
 * Essa funcão irá chamar get_header_compactactacao() para que seja escrito no
 * arquivo de saída o cabeçalho do programa. Será escrito o lixo e a árvore em pré-ordem.
 * Depois irá chamar a funcao insert_file_binary() para continuar escrevendo no arquivo
 * os novos bytes comprimidos com o auxilio da funcao is_set_bit() e caracteres da Hash;
 * Os argumentos necessários são: nome do arquivo de saída, uma Hash, raiz da arvore/nó,
 * um inteiro long para armazenar o tamanho da árvore e o arquivo de entrada.
 *
 */

void insert_file_binary(FILE *file_input, FILE *file_out, hash *HASH,
	char nome_arquivo[]);

/*
 * Essa funcão irá realizar a compressao dos bytes e jogá-los no novo arquivo de saída
 * Será criado dois unsigned char: um para a leitura dos caracteres do arquivo e o outro
 * como auxiliar, um auxiliar do tipo inteiro aux começando por 7 e um inteiro i. Após ler
 * cada caractere do arquivo de entrada ele irá pesquisar na Hash o byte desse caractere.
 * Iremos de posição em posição desse byte, iremos ver bit a bit. Se o bit for 1 ele
 * irá setar esse bit de acordo com o i (usará operador logico ou).
 * EX: Seja o byte aux totalmente zero: |00000000| seja i = 7 logo o byte será: |10000000|
 * Após isso reduz uma unidade do inteiro aux. Quando o int aux for < 0 então eu printo
 * o meu byte aux no arquivo de saída, retorno o meu byte a receber 0 e aux recebendo 7,
 * será realizado essa operação até não haver mais caracteres no arquivo de entrada.
 * Os argumentos necessários são: arquivo de entrada, arquivo de saída, uma Hash, nome do arquivo
 * de entrada para iniciar o arquivo do começo.
 *
 */

void compress();

/*
 * Essa será a função principal no qual chamará todas as funções:
 * conting_freq(), construct_tree(), encode(), get_header_compactacao(),
 * insert_file_binary(), insert_header_file().
 *
 */



/*
 *
 * Funçoes usadas em Descompress.c
 *
 * Linhas: 50 até ***
 */

void get_header(FILE *file, unsigned int *tam_lixo, unsigned int *tam_arv);

/*
 * NAO SEI DIREITO
 *
 */

Nodes *construct_tree_descompress(Nodes *Nodes_huff,
		FILE *file_input_comprimido);

/*
 *
 *
 */

long long int FileSize(FILE *in);

/*
 * Essa funcão serve para descobrir o tamanho
 * de um arquivo passado pelo argumento.
 * Será retornado seu tamanho em número.
 *
 */

void descompress();
/*
 *
 *
 */


/*
 *
 * Funçoes usadas em Huffman.h
 *
 * Linhas: 75 até ***
 */

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
 * Essa função servirá para inicializar a HashTable com valores nulos.
 * A nossa Hash guardará ponteiro para uma outra estrutura que
 * guardará a frequencia dos caracteres e também os novos
 * caminhos dos bits da funcao Encode().
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


int esta_vazia(Nodes *raiz);
int lenght_tree(Nodes *raiz);
int convert_size_tree_to_bin(int size_tree, int bin[]);
int is_bit_set(unsigned char byte, int i);
unsigned char set_bit(unsigned char c, int i);
int Cont_lixo_file(hash *HASH);
#endif
