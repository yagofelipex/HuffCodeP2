#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 1000

/*ESTRUTURA PARA LISTA*/
struct Nos
{
	int valor;
	struct Nos* proximo;
};

/*ESTRUTURA PARA ARVORE DE BUSCA BINÁRIA*/
struct abb
{
	int valor;
	struct abb *esq, *dir;
};
/*FUNCOES PROTOTIPAS PARA A LISTA ENCADEADA ORDENADA */
struct Nos *push(struct Nos **lista, int valor);
void selectionSort(struct Nos* LISTA);
void printf_lista(struct Nos *lista);
void troca(struct Nos *n1, struct Nos *n2);

/*FUNCOES PROTOTIPAS PARA A ABB*/
struct abb *novo_no(int valor);
void printf_abb(struct abb *raiz);
struct abb *inserir_na_abb(struct abb *novo, int valor);
int buscar_na_arvore(struct abb *raiz, int valor, int comparacacao);
int busca_na_lista(struct Nos* LISTA, int valor);
void print_arvore(struct abb* raiz);
void print_pre_ordem(struct abb* raiz);
int numero_procurado_lista(struct Nos *LISTA, int valor);
int numero_procurado_abb(struct abb *raiz, int valor);
//struct abb *buscar_na_arvore(int valor);

int main()
{
	struct Nos *LISTA = NULL;
	struct abb *raiz = NULL;
	int i, n, escolha, valor_desejado;
	int *r_comp_lista;
	int *r_comp_abb;
	int *numeros_comparados;
	int aux = 0;

	r_comp_lista = (int*)malloc(sizeof(int) * MAX_ELEMENT);
	r_comp_abb = (int*)malloc(sizeof(int) * MAX_ELEMENT);
	numeros_comparados = (int*)malloc(sizeof(int) * MAX_ELEMENT);
	srand(time(NULL));

	for(i = 0; i <= MAX_ELEMENT; i++)
	{
		n =(rand() % 1000);
		push(&LISTA, n);
		raiz = inserir_na_abb(raiz, n);
		selectionSort(LISTA);
	}
		do
		{
			printf("******************************************\n");
			printf("ESCOLHA UMA OPÇÃO:\n");
			printf("1 - PROCURAR POR UM ELEMENTO\n");
			printf("2 - IMPRIMIR A LISTA ENCADEADA ORDENADA\n");
			printf("3 - IMPRIMIR A ABB\n");
			printf("0 - SAIR\n");
			printf("******************************************\n");

			scanf("%d", &escolha);

			switch(escolha)
			{
				case 0:
					break;
				case 1:
					for(i = 0; i < 100; i++)
					{
						n =(rand() % 1000);
						if( ((numero_procurado_lista(LISTA, n)) && ((numero_procurado_abb(raiz, n))  == n)))
						{
							printf("Número procurado: %d\n", n);
							//printf(">>>> %d <<<<\n", numero_procurado_abb(raiz, n));
							printf("Número de comparações pra achar na lista: %d\n", busca_na_lista(LISTA, n));
							r_comp_lista[aux] = busca_na_lista(LISTA, n);
							printf("Número de comparações pra achar na abb: %d\n", buscar_na_arvore(raiz, n, 0));
							r_comp_abb[aux] = buscar_na_arvore(raiz, n, 0);
							numeros_comparados[aux] = n;
							aux++;
						}
					}
					printf("Números usados: ");
					for(i = 0; i < aux; i++)
					{
						printf("%d ", numeros_comparados[i]);
					}
					printf("\n");
					printf("\n");
					printf("Comparações da lista: ");
					for(i = 0; i < aux; i++)
					{
						printf("%d ", r_comp_lista[i]);
					}
					printf("\n");
					printf("\n");
					printf("Comparações da abb: ");
					for(i = 0; i < aux; i++)
					{
						printf("%d ", r_comp_abb[i]);
					}
					printf("\n");
					break;
				case 2:
					printf_lista(LISTA);
					break;
				case 3:
					//printf_abb(raiz);
					//print_arvore(raiz);
					print_pre_ordem(raiz);
					printf("\n");
					break;
				default:
					printf("OPÇÃO INVALIDA!\n");
					break;
			}

		} while(escolha);

	return 0;
}

struct Nos *push(struct Nos **lista, int valor)
{
	struct Nos* init = (struct Nos*)malloc(sizeof(struct Nos));
	init->valor = valor;
	init->proximo = *lista;
	*lista = init;
}

void selectionSort(struct Nos* LISTA)
{
    struct Nos* aux = LISTA;

    while (aux) {
        struct Nos* old = aux;
        struct Nos* resltado = aux->proximo;

        while (resltado) {
            if (old->valor > resltado->valor)
                old = resltado;

            resltado = resltado->proximo;
        }

        troca(aux, old);
        aux = aux->proximo;
    }
}

void printf_lista(struct Nos *lista)
{
	if(lista->proximo == NULL)
	{
		printf("A lista está vazia");
	}
	else
	{
		while(lista != NULL)
		{
			printf("%d\n", lista->valor);
			lista = lista->proximo;
		}
	}
}

void troca(struct Nos *n1, struct Nos *n2)
{
	int aux = n1->valor;
	n1->valor = n2->valor;
	n2->valor = aux;
}

void printf_abb(struct abb *raiz)
{
	if(raiz != NULL)
	{
		printf_abb(raiz->esq);
		printf("%d \n", raiz->valor);
		printf_abb(raiz->dir);
	}
}

void print_arvore(struct abb* raiz)
{
	if(raiz != NULL)
	{
		print_arvore(raiz->esq);
		printf("\n%d", raiz->valor);
		print_arvore(raiz->dir);
	}
}

void print_pre_ordem(struct abb* raiz)
{
    if(raiz != NULL)
    {
        printf("\n%d", raiz->valor);
        print_pre_ordem(raiz->esq);
        print_pre_ordem(raiz->dir);
    }
}

struct abb *inserir_na_abb(struct abb *novo, int valor)
{
	if(novo == NULL)
	{
		struct abb *new = (struct abb*)malloc(sizeof(struct abb));
		new->valor = valor;
		new->esq = NULL;
		new->dir = NULL;

		return new;
	}
	else
	{
		if(valor >= novo->valor)
		{
			novo->dir = inserir_na_abb(novo->dir, valor);
		}
		else if(valor < novo->valor)
		{
			novo->esq = inserir_na_abb(novo->esq, valor);
		}
	}
	return novo;
}

int buscar_na_arvore(struct abb *raiz, int valor, int comparacacao)
{
	if(raiz == NULL)
	{
		return 0;
	}
	else
	{
		if(valor == raiz->valor)
		{
			//printf("Número de comparações pra achar na abb: %d\n", comparacacao);
			return comparacacao;
		}
		if(valor >= raiz->valor)
		{
			return buscar_na_arvore(raiz->dir, valor, ++comparacacao);
		}
		if(valor < raiz->valor)
		{
			return buscar_na_arvore(raiz->esq,valor, ++comparacacao);
		}
	}
}

int busca_na_lista(struct Nos* LISTA, int valor)
{
	int comparacao = 0;
	while(LISTA != NULL)
	{
		if(LISTA->valor == valor)
		{
			//printf("Número de comparações pra achar na lista: %d\n", comparacao);
			return comparacao;
		}
		LISTA = LISTA->proximo;
		comparacao++;
	}
}

int numero_procurado_lista(struct Nos *LISTA, int valor)
{
	while(LISTA != NULL)
	{
		if(LISTA->valor == valor)
		{
			return 1;
			break;
		}
		LISTA = LISTA->proximo;
	}
	return 0;
}

int numero_procurado_abb(struct abb *raiz, int valor)
{
	if(raiz == NULL)
	{
		return 0;
	}
	if(raiz->valor == valor)
	{
		return (valor);
	}
	if(raiz->valor > valor)
	{
		return (numero_procurado_abb(raiz->esq, valor));
	}
	else
	{
		return (numero_procurado_abb(raiz->dir, valor));
	}
}
