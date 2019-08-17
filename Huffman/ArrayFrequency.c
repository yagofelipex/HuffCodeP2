#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    	printf("Characters: %c Frequency: %d\n",i, string[i]);
    }
}
