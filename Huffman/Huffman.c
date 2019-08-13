/*
 ============================================================================
 Name        : Huffman.c
 Author      : WILAMIS AVIZ
 Version     :
 Copyright   : Your copyright notice
 Description : UMA TENTATIVA DE IMPLEMENTACAO DA CODIFICACAO DE HUFFMAN
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct HuffTree
{
	unsigned int frequencia;
	void* valor;
	struct HuffTree *esq;
	struct HuffTree *dir;
};

struct HuffTree init()
{
	struct HuffTree novo_valor = (struct Huff*)malloc(sizeof(struct Huff));
	novo_valor->valor = NULL;
	novo_valor->frequencia = NULL;
	novo_valor->esq = NULL;
	novo_valor->dir =  NULL;
	return novo_valor;
}

struct HuffTree add(unsigned int frequencia, void* valor, struct HuffTree *esq, struct HuffTree *dir)
{
	struct HuffTree novo_valor = (struct Huff*)malloc(sizeof(struct Huff));
	novo_valor->valor = valor;
	novo_valor->frequencia = frequencia;
	novo_valor->esq = esq;
	novo_valor->dir =  dir;
	return novo_valor;
}

unsigned char eh_folha(struct HuffTree huffman)
{
	if((huffman->esq == NULL) && (huffman->dir == NULL))
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
