#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "../Compress.c"
#include "../HuffmanTADS/Huffman.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_tree() {
	unsigned char letter = 'A';
	int frequency = 5;
	Nodes *new_node = CreatNode(frequency, letter, NULL, NULL);

	CU_ASSERT_PTR_NOT_NULL(new_node); /*Checking if new_node is NULL*/
	CU_ASSERT_EQUAL('A', new_node->character); /*Checking if tree's element is equal to 'A' */
	CU_ASSERT_EQUAL(frequency, new_node->frequency);
	CU_ASSERT_PTR_NULL(new_node->left);
	CU_ASSERT_PTR_NULL(new_node->right);

	unsigned char letter1 = 'B';
	int frequency1 = 10;

	new_node->left = CreatNode(frequency1, letter1, NULL, NULL);

	CU_ASSERT_PTR_NOT_NULL(new_node->left);
	CU_ASSERT_PTR_NULL(new_node->right);
	CU_ASSERT_EQUAL(frequency1, new_node->left->frequency);

	unsigned char letter2 = 'C';
	short frequency2 = 15;

	new_node->right = CreatNode(frequency2, letter2, NULL, NULL);

	CU_ASSERT_EQUAL('C', new_node->right->character);
	CU_ASSERT_PTR_NOT_NULL(new_node->right);
	CU_ASSERT_EQUAL(frequency2, new_node->right->frequency);
}

void test_heap() {

	/*
	 * TESTANDO Insert() e Pop();
	 */
	unsigned char letter0 = 'A';
	int frequency0 = 7;
	heap *new_heap = CreatTable(256);
	int tam_heap = new_heap->size = 0;
	Nodes *left, *right;
	Insert(frequency0, letter0, new_heap, NULL, NULL);
	tam_heap = new_heap->size;
	CU_ASSERT_PTR_NOT_NULL(new_heap->table[tam_heap]); /*Checking if new_node is NULL*/
	CU_ASSERT_EQUAL('A', new_heap->table[tam_heap]->character); /*Checking if tree's element is equal to 'A' */
	CU_ASSERT_EQUAL(frequency0, new_heap->table[tam_heap]->frequency);
	CU_ASSERT_PTR_NULL(new_heap->table[tam_heap]->left);
	CU_ASSERT_PTR_NULL(new_heap->table[tam_heap]->right);

	unsigned char letter = 'B';
	int frequency = 10;

	Insert(frequency, letter, new_heap, NULL, NULL);
	tam_heap = new_heap->size;

	CU_ASSERT_PTR_NOT_NULL(new_heap->table[tam_heap]); /*Checking if new_node is NULL*/
	CU_ASSERT_EQUAL('B', new_heap->table[tam_heap]->character); /*Checking if tree's element is equal to 'A' */
	CU_ASSERT_EQUAL(frequency, new_heap->table[tam_heap]->frequency);
	CU_ASSERT_PTR_NULL(new_heap->table[tam_heap]->left);
	CU_ASSERT_PTR_NULL(new_heap->table[tam_heap]->right);


	Nodes *beforeLEFT = new_heap->table[1];
	Nodes *beforeRIGHT = new_heap->table[2];

	CU_ASSERT_EQUAL(2, new_heap->size);
	CU_ASSERT_TRUE((new_heap->table[0]) < new_heap->table[new_heap->size-1]);

	left = Pop(new_heap);

	CU_ASSERT_PTR_NOT_NULL(left);
	CU_ASSERT_EQUAL(left, beforeLEFT);
	right = Pop(new_heap);
	CU_ASSERT_PTR_NOT_NULL(right);
	CU_ASSERT_EQUAL(right, beforeRIGHT);
	CU_ASSERT_EQUAL(right, new_heap->table[tam_heap]);
	int soma_freq = left->frequency + right->frequency;

	Insert(soma_freq, '*', new_heap, left, right);
	tam_heap = new_heap->size;


	CU_ASSERT_PTR_NOT_NULL(new_heap->table[tam_heap]->left);
	CU_ASSERT_PTR_NOT_NULL(new_heap->table[tam_heap]->right);
	CU_ASSERT_EQUAL(soma_freq, new_heap->table[tam_heap]->frequency);

	CU_ASSERT_EQUAL(1, new_heap->size);
	Pop(new_heap);
	CU_ASSERT_EQUAL(0, new_heap->size);
	CU_ASSERT_PTR_NULL(new_heap->table[new_heap->size]);
}

void test_hash() {
	hash *HASH = create_hash();
	CU_ASSERT_PTR_NOT_NULL(HASH->array[0]);
	CU_ASSERT_EQUAL(0, HASH->array[0]->frequencia);
	CU_ASSERT_EQUAL('\0', HASH->array[0]->bits[0]);
	CU_ASSERT_EQUAL(0, HASH->array[255]->frequencia);
	CU_ASSERT_EQUAL('\0', HASH->array[255]->bits[0]);
}

int main() {
	CU_initialize_registry();

	CU_pSuite suite = NULL;

	suite = CU_add_suite("TESTE DAS ESTRUTURAS USADA NO HUFFMAN: NODES, HEAP and HASH", NULL, NULL); //a pointer to an initialization function, a pointer to a cleanup function
	if (NULL == suite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/*Adding a test case to the tree.*/
	if (NULL == CU_add_test(suite, "TESTING NODES", test_tree)) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/*Adding a test case to the heap.*/
	if(NULL == CU_add_test(suite, "TESTING HEAP", test_heap)){
	 CU_cleanup_registry();
	 return CU_get_error();
	 }

	/*Adding a test case to the hash.*/
	if(NULL == CU_add_test(suite, "TESTING HASH", test_hash)){
	 CU_cleanup_registry();
	 return CU_get_error();
	 }

	CU_basic_set_mode(CU_BRM_VERBOSE); /*to check the parametres*/
	CU_basic_run_tests();
	CU_cleanup_registry();

	return 0;
}
