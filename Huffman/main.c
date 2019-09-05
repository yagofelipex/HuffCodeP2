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
