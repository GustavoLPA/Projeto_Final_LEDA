#include <stdio.h>
#include <stdlib.h>

typedef struct noh
{
    int dado;
    struct noh *prox;
} noh;

typedef struct pilha
{
    noh *topo;
    int qtd_elementos;
} pilha;

typedef struct fila
{
    noh *inicio;
    noh *fim;
} fila;

// Funções auxiliares

void display_pilha(pilha *stack)
{
    noh *ptr = stack->topo;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->dado);
        ptr = ptr->prox;
    }
}

void display_fila(fila *fila)
{
    noh *ptr = fila->inicio;

    if (ptr == NULL)
    {
        printf("Fila vazia!!\n");
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

// Funções principais

void iniciarPilha(pilha *stack) { stack->topo = NULL; }

void push(int dado, pilha *stack)
{
    noh *ptr;
    ptr = (struct noh *)calloc(1, sizeof(struct noh));

    if (ptr == NULL)
    {
        printf("Erro na alocacao");
    }
    else
    {
        ptr->dado = dado;
        ptr->prox = stack->topo;
        stack->topo = ptr;
        stack->qtd_elementos += 1;
    }
}

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
    }
}

int main(void)
{

    // Alocando pilha
    pilha *STACK;
    STACK = (struct pilha *)calloc(1, sizeof(struct pilha));

    iniciarPilha(STACK);

    // Alocando fila PAR
    fila *FILA_PAR;
    FILA_PAR = (struct fila *)calloc(1, sizeof(struct fila));

    // Alocando fila ÍMPAR
    fila *FILA_IMPAR;
    FILA_IMPAR = (struct fila *)calloc(1, sizeof(struct fila));

    int dado;

    while (1)
    {
        printf("Insira um numero inteiro ou 0 para sair: ");
        scanf("%d", &dado);
        if (dado > 0)
        {
            push(dado, STACK);
            system("clear || cls");
            printf("------------------------------------\n");
            printf("Item adicionado a pilha com sucesso!\n");
            printf("------------------------------------\n\n");

            if (dado % 2 == 0)
            {
                queue(dado, FILA_PAR);
            }
            else
            {
                queue(dado, FILA_IMPAR);
            }
        }
        else
        {
            printf("\n---------- Pilha inserida ----------\n");
            display_pilha(STACK);

            printf("\n\n----------  Fila Par  ----------\n");
            display_fila(FILA_PAR);

            printf("\n\n---------- Fila Impar ----------\n");
            display_fila(FILA_IMPAR);

            break;
        }
    }

    return 0;
}