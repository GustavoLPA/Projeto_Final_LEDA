#include <stdio.h>
#include <stdlib.h>

// Máximo de elementos na pilha
#define MAX 5

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

// Funções auxiliares
void menu()
{
  printf("\n___________________________\n");
  printf("\n1 - Push()\n");
  printf("2 - Pop()\n");
  printf("3 - Display\n");
  printf("4 - Buscar elemento\n");
  printf("\n0 - Sair\n");
  printf("___________________________\n");
  printf("\nDigite sua opcao: ");
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

int pop(pilha *stack)
{
  noh *ptr = stack->topo;
  int dado; // Backup

  if (ptr == NULL)
  {
    printf("Pilha Vazia!\n");
  }
  else
  {
    stack->topo = ptr->prox;
    ptr->prox = NULL;
    dado = ptr->dado; // Backup
    free(ptr);
    stack->qtd_elementos -= 1;
  }

  return dado;
}

void display_pilha(pilha *stack)
{
  noh *ptr = stack->topo;

  if (ptr == NULL)
  {
    printf("Pilha vazia!\n");
  }
  else
  {
    printf("--------- Pilha Atual ---------\n");
    while (ptr != NULL)
    {
      printf("%d\n", ptr->dado);
      ptr = ptr->prox;
    }
    printf("\n-------------------------------");
    printf("\nQuantidade de elementos: %d\n", stack->qtd_elementos);
    printf("-------------------------------\n");
  }
}

int busca_elemento(pilha *stack, int dado_buscado)
{
  noh *ptr = stack->topo;
  int ind = 0;

  if (ptr == NULL)
  {
    printf("Pilha vazia!");
  }
  else
  {
    while (ptr->dado != dado_buscado)
    {
      ptr = ptr->prox;
      if (ptr->prox == NULL && ptr->dado != dado_buscado)
      {
        printf("Elemento nao localizado\n");
      }
    }
    printf("Elemento localizado: %d\n", ptr->dado);
  }

  return dado_buscado;
}

// Main
int main(void)
{

  // Alocando pilha
  pilha *STACK;
  STACK = (struct pilha *)calloc(1, sizeof(struct pilha));

  iniciarPilha(STACK);

  if (STACK == NULL)
  {
    printf("Erro durante a alocacao\n");
    exit(0);
  }
  else
  {
    iniciarPilha(STACK);
  }

  int opc = 0, dado = 0;

  while (1)
  {
    menu();
    scanf("%d", &opc);

    if (opc == 1)
    {
      if (STACK->qtd_elementos >= MAX)
      {
        printf("\n!!! Pilha cheia, realize o comando pop() para poder inserir "
               "um novo "
               "elemento !!!\n");
      }
      else
      {
        system("clear || cls");
        printf("Insira um numero inteiro: ");
        scanf("%d", &dado);
        push(dado, STACK);
        system("clear || cls");
        printf("Item adicionado a pilha com sucesso!\n");
      }
    }
    else if (opc == 2)
    {
      system("clear || cls");
      pop(STACK);
      system("clear || cls");
      printf("Item excluido da pilha com sucesso!\n");
    }
    else if (opc == 3)
    {
      system("clear || cls");
      display_pilha(STACK);
    }
    else if (opc == 4)
    {
      system("clear || cls");
      printf("Insira o elemento a ser pesquisado: ");
      scanf("%d", &dado);
      busca_elemento(STACK, dado);
    }
    else if (opc == 0)
    {
      system("clear || cls");
      printf("\n---------- Finalizado ----------");
      break;
    }
    else
    {
      printf("\n!!! Digite uma opcao valida !!!\n");
    }
  }
  return 0;
}