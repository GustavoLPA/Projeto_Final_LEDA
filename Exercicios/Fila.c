#include <stdio.h>
#include <stdlib.h>

// Máximo de itens na fila
#define MAX 5

typedef struct noh
{
    int dado;
    struct noh *prox;
} noh;

typedef struct fila
{
    int max_qtd, qtd_elementos;

    noh *inicio;
    noh *fim;
} fila;

// Funções Auxiliares
void menu()
{
    printf("\n___________________________\n");
    printf("\n1 - Enfileirar\n");
    printf("2 - Desenfileirar\n");
    printf("3 - Display\n");
    printf("4 - Buscar elemento\n");
    printf("\n0 - Sair\n");
    printf("___________________________\n");
    printf("\nDigite sua opcao: ");
}

// Funções Principais

void iniciar_fila(fila *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

// Enfileirar
void queue(int dado, fila *f)
{
    noh *ptr = (noh *)calloc(1, sizeof(struct noh));

    if (ptr == NULL)
    {
        printf("Erro de alocação\n");
    }
    else
    {
        ptr->dado = dado;

        if (f->inicio == NULL)
        {
            f->inicio = ptr;
        }
        else
        {
            f->fim->prox = ptr;
        }

        f->fim = ptr;

        f->qtd_elementos += 1;
    }
}

// Desenfileirar
int dequeue(fila *f)
{
    noh *ptr = f->inicio;
    int dado; // Backup

    if (ptr == NULL)
    {
        printf("\n|| Fila vazia ||\n");
    }
    else
    {
        f->inicio = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        f->qtd_elementos -= 1;
    }

    return dado;
}

void display_fila(fila *fila)
{
    noh *ptr = fila->inicio;

    if (ptr == NULL)
    {
        printf("\n|| Fila vazia ||\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d  ", ptr->dado);
            ptr = ptr->prox;
        }
    }
}

int buscar_elemento(fila *fila, int dado_buscado)
{
    noh *ptr = fila->inicio;

    while (ptr->dado != dado_buscado)
    {
        ptr = ptr->prox;
        if (ptr->prox == NULL && ptr->dado != dado_buscado)
        {
            printf("Elemento nao localizado\n");
            printf("\nEncerrando...");
        }
    }
    printf("\nElemento localizado: %d\n", ptr->dado);

    return dado_buscado;
}

int main(void)
{
    int opc, dado, elemento_buscado;

    // Alocando fila
    fila *fila;
    fila = (struct fila *)calloc(1, sizeof(struct fila));

    iniciar_fila(fila);

    while (1)
    {
        menu();
        scanf("%d", &opc);

        if (opc == 1)
        {
            if (fila->qtd_elementos >= MAX)
            {
                printf("\n|| Fila cheia, realize a operação 'Dequeue' para poder "
                       "inserir um novo elemento||\n\n");
            }
            else
            {
                system("clear || cls");
                printf("Insira um numero inteiro: ");
                scanf("%d", &dado);
                queue(dado, fila);
                printf("\n|| Elemento inserido na fila com sucesso ||\n");
            }
        }
        else if (opc == 2)
        {
            system("clear || cls");
            dequeue(fila);
            if (fila->qtd_elementos >= 1)
            {
                printf("\n|| Elemento removido da fila com sucesso ||\n");
            }
        }
        else if (opc == 3)
        {
            system("clear || cls");
            printf("---------- Fila Atual ----------\n");
            display_fila(fila);
            printf("\n--------------------------------\n");
        }
        else if (opc == 4)
        {
            system("clear || cls");
            if (fila->qtd_elementos < 1)
            {
                printf("\n|| Fila vazia ||\n");
            }
            else
            {
                printf("Insira o elemento a ser buscado: ");
                scanf("%d", &elemento_buscado);
                buscar_elemento(fila, elemento_buscado);
            }
        }
        else if (opc == 0)
        {
            system("clear || cls");
            printf("Encerrando...\n");
            break;
        }
        else
        {
            system("clear || cls");
            printf("|| Digite uma opcao valida de acordo com o menu ||");
        }
    }

    return 0;
}