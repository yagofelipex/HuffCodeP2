#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*typedef struct Data_character
{
	char character[1000];
	int frequency;
}Creat;*/


struct Node
{  
    unsigned char caracter;
    int frequencia;
    struct Node *proximo; 
};


struct Node *novo_no(struct Node *head, unsigned char c, int f)
{
    if(head == NULL)
    {
        struct Node *novo = (struct Node*)malloc(sizeof(struct Node));
        novo->caracter = c;
        novo->frequencia = f;
        novo->proximo = NULL;
        return novo;
    }
    else
    {
        struct Node *novo = (struct Node*)malloc(sizeof(struct Node));
        novo->caracter = c;
        novo->frequencia = f;
	    /**
	    FALTA
	    COMPLETAR
	    */
        return novo;
    }
}
void zerar_array_frequencia(unsigned char array_frequencia[])
{
	int i;
	for(i = 0; i < 256; i++)
	{
		array_frequencia[i] = 0;
	}
}
int main()
{
    FILE *file_input; //variavel que guardará o arquivo de entrada
    unsigned char caracter;
    char nome_arquivo[30];
    unsigned char string[256];
    struct Node* head = NULL;
    int i = 0;

    zerar_array_frequencia(string);

    scanf("%s", nome_arquivo);
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
			printf("%c", caracter);
			string[caracter]++;
		}

        //novo_no(head, caracter, )
    }

    for(i = 0; i < 256; i++)
    {
    	printf("%d %d\n",i, string[i]);
    }

    return 0;
}
