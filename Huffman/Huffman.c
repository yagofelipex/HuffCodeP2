//AINDA NAO TESTEI

#include <stdio.h>
#include <stdlib.h>

struct HuffTree
{
	int frequencia; //frequencia do caractere no arquivo
	unsigned char c;		//chave passada
	struct HuffTree *esq;	//filho a esq
	struct HuffTree *dir;	//filho a dir
};

struct HuffTree init()
{
	struct HuffTree novo_valor = (struct Huff*)malloc(sizeof(struct Huff));
	novo_valor->c = NULL;
	novo_valor->frequencia = NULL;
	novo_valor->esq = NULL;
	novo_valor->dir =  NULL;
	return novo_valor;
}

struct HuffTree add(unsigned int frequencia, void* valor, struct HuffTree *esq, struct HuffTree *dir)
{
	struct HuffTree novo_valor = (struct Huff*)malloc(sizeof(struct Huff));
	novo_valor->c = valor;
	novo_valor->frequencia = frequencia;
	novo_valor->esq = esq;
	novo_valor->dir =  dir;
	return novo_valor;
}

int eh_folha(struct HuffTree huffman)
{
	if((huffman != NULL) && (huffman->esq == NULL) && (huffman->dir == NULL))
		return 1;
	else
		return 0;
}

void print_huffman()
{

}

int main() {

	return 0;
}
