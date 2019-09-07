
/* Este programa comprime ou extrai arquivos usando a Codificação de Huffman.
 * Na compressão, o arquivo de saída terá nos 3 primeiros bits o número cor-
 * respondente à quantidade de bits de lixo no final do arquivo. Nos 13 bits
 * seguintes haverá o número correspondente à quantidade de bytes ocupada pe-
 * la árvore de Huffman. A árvore de Huffman será escrita após os dois primei-
 * ros bytes em pré-ordem, em codificação ASCII. Após a árvore de Huffman, ha-
 * verá os bits com os dados do arquivo comprimido usando a árvore impressa
 * como codificação. Na descompressão, as regras descritas anteriormente devem
 * ter sido usadas para comprimir o arquivo de entrada.
 * Este é o arquivo principal do projeto, que deve ser compilado utilizando essa classe.
 */

#include "Descompress.c"
#include "Compress.c"
#include <stdio.h>

int main(void) {
	int op;
	printf("////////////////////////////////////\n");
	printf("INFORME O QUE DESEJA REALIZAR:\n");
	printf("1 - COMPRESSAO | 2 - DESCOMPRESSAO\n");
	printf("////////////////////////////////////\n");
	scanf("%d", &op);
	switch (op) {
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
